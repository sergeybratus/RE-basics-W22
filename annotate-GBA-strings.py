#
# This script automates a step in disassembling our GBA ROM example. The ROM uses
#   a trick that confuses Ghidra's disassembler. As it repeats frequently in the
#   the binary, fixing it by hand is tedious. Hence this script.
#
#@author CS69.16 instructor
#@category CS69.16 demo 
#@keybinding 
#@menupath 
#@toolbar 
#
# =================[ The confunsing trick ]=================
#
#   A call to the display string-processing function is followed by an address of the next
#   instruction and the string itself. The disassembler expects an instruction after the
#   call (i.e., the first instruction to return to after the call), finds the literal
#   address instead, gets confused, and stops disassembly. See "Details of the trick" below.
#
# =================[ An automated fix ]=====================
#
#   The fix is to traverse all calls to process_this_here_string(), annotate the following
#   four bytes after each call as a pointer, and then trigger re-disassembly. Note that
#   each new round of disassembly will expose new calls to the function in the newly
#   disassemled code, so the process will need to be repeated until no more new calls
#   to this function are revealed. Hence the "while True" loop around the code.
#
# =================[ Using Ghidra's Flat API ]==========
#
#   Ghidra exposes a very rich Java class hierarchy, but also provides the simpler Flat API,
#     https://ghidra.re/ghidra_docs/api/ghidra/program/flatapi/FlatProgramAPI.html
#     https://dev2u.net/2021/06/03/14-basic-ghidra-scripting-the-ghidra-book/
#   This flat API is featured in many tutorials, such as 
#     https://deadc0de.re/articles/ghidra-scripting-python.html
#     https://www.sentinelone.com/labs/a-guide-to-ghidra-scripting-development-for-malware-researchers/
#     https://blogs.blackberry.com/en/2019/07/an-introduction-to-code-analysis-with-ghidra
#   etc.
#
#   To test out these APIs, the Python REPL (Window >> Python) inside Ghidra is very handy.
#
# =================[ Details of the trick ]=================
#
#        08448964 06 de ee eb     bl         process_this_here_string                    
#                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
#        08448968 7c              ??         7Ch    |        // this is actually the address, 0x0844897c
#        08448969 89              ??         89h
#        0844896a 44              ??         44h    D
#        0844896b 08              ??         08h
#        0844896c 0c              ??         0Ch             // string length byte
#        0844896d 20 20 47        ds         "  GAME  OVER"  // the string
#                 41 4d 45 
#                 20 20 4f 
#        0844897a 00              ??         00h             // filler, for alignment
#        0844897b 00              ??         00h
#        0844897c 24              ??         24h    $        //  bl FUN_08000e14                      
#        0844897d e1              ??         E1h
#        0844897e ee              ??         EEh
#        0844897f eb              ??         EBh
#        08448980 01              ??         01h             //  more instructions
#
#  Pressing "p" at 0x08448968 (on the address( enables correct disassembly. For reference,
#    this works because the function we called process_this_here_string() uses LR to pick
#    up the literal address (0x0844897c) to return to, and also ends up with r0 pointing 
#    to the string's length byte (0x0844896c), which the next function FUN_08000e14 will
#    get as its first argument:
#
#  noreturn undefined process_this_here_string()
#        08000184 01 00 2d e9     stmdb      sp!,{r0}
#        08000188 0e 00 b0 e1     movs       r0,lr
#        0800018c 04 e0 b0 e4     ldrt       lr,[r0],#0x4
#        08000190 1e ff 2f e1     bx         lr
#
#
#
# Some of the following script is borrowed from https://resolute-tech.com/an-introduction-to-ghidra-scripting/
#
# Retrieve a Function (ghidra.program.model.listing.Function) object for a
#     named function.
#
functionName = "process_this_here_string"
funList = getGlobalFunctions(functionName)
funObj  = funList[0]

# Get the Address (ghidra.program.model.address.Address) object for the entry point of
#     a function
funObjAddr = funObj.getEntryPoint()

# Annotating the 4-byte address as a pointer with createData (see below) needs a DataType object.
#  This actually took me quite long time to find, because I was trying various type names and
#  classes/objects, only to find out that they were not defined in the current context. Then
#  FlatAPI's getDataTypes() helped.
print( "Pointer types in currentProgram: ")
for t in list(getDataTypes("pointer")):
    print t
pointer = list(getDataTypes("pointer"))[0]

# Get all references to a function, print address of the reference and function
#     containing the reference
# getReferencesTo returns a java array of ghidra.program.model.symbol.Reference
#     objects, the list() method coverts the java array into a python list

refList  = list(getReferencesTo(funObjAddr))
refList.sort()
refCount = funObj.getSymbol().getReferenceCount()
print("There are {} initial references to {}".format(refCount, funObj.getName()))

# NOTE: Not all references will be immediately revealed. We need an iterative process
#        as we disassemble more code each time      

while True:
      for ref in refList:
          addr      = ref.getFromAddress()
          next_addr = addr.add(4)
          print( "Reference to function {} at address 0x{:016x}, "
                  "next address  0x{:016x}".format(funObj.getName(), addr.getOffset(), next_addr.getOffset()))
          clearListing(next_addr)         # the following three clears are needed for multiple passes
          clearListing(next_addr.add(4))  #  otherwise the next iteration produces errors.
          clearListing(next_addr.add(5))
          data = createData(next_addr, pointer)
          #
          #  Collect the string, too
          #
          byte_len = createByte(next_addr.add(4))
          string   = createAsciiString(next_addr.add(5)).getValue()
          print string
          disassemble(data.getValue())    # triggers recovery of more references to the function!
          #
          #  An additional hack: bookmark the "GAME OVER" invocation for ease of navigation.
          #
          if string.find("GAME") != -1 and string.find("OVER") != -1 :
              print "<======== GAME OVER sink ======"
              createBookmark(addr, "", "GAME OVER exit")
              game_over_sink = addr
      newRefList  = list(getReferencesTo(funObjAddr))
      newRefList.sort()
      newRefCount = len(newRefList)
      if newRefCount == refCount :
          break
      else:
          print "New references found, now {}".format(newRefCount)
      refList  = newRefList
      refCount = newRefCount
      
print "Done at {} references".format( newRefCount )
print "Game over exit is {}".format(game_over_sink)

##### Run it and see what it produces!
