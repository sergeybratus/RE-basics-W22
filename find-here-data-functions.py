# Find functions that return the address of data immediately following their return ('bx lr')
#
# Examples in our GBA ROM: return_data_section1 (0x081157f4), FUN_08002564, FUN_080032f0, FUN_0800331c, FUN_08004ea8, ...
#    
#
#@author CS69.16 instructor
#@category _NEW_
#@keybinding 
#@menupath 
#@toolbar 


#
# Example of dumping native assembly code and P-code is from
#    https://github.com/HackOvert/GhidraSnippets:

def dump_raw_pcode(func):
    func_body = func.getBody()
    listing = currentProgram.getListing()
    opiter = listing.getInstructions(func_body, True)
    while opiter.hasNext():
        op = opiter.next()
        raw_pcode = op.getPcode()
        print("{}".format(op))
        for entry in raw_pcode:
            print("  {}".format(entry))

func = getGlobalFunctions("return_data_section1")[0]
#dump_raw_pcode(func)   
            
def get_instructions(func):
    func_body = func.getBody()
    listing = currentProgram.getListing()
    opiter = listing.getInstructions(func_body, True)
    instructions = list(opiter)
    return instructions

# print get_instructions(func)

def is_here_addr_function(func):
    l = get_instructions(func)
    ls = [ x.toString() for x in l ]   # this list comprehension is slightly better than
    # return len(l) == 3 and l[0].toString().startswith("stmdb") and l[1].toString().startswith("mov r0,pc") and l[2].toString().startswith("bx lr")
    return len(l) == 3 and ls[0].startswith("stmdb") and ls[1].startswith("mov r0,pc") and ls[2].startswith("bx lr") 
# Naive unit-testing
#func1 = getGlobalFunctions("process_this_here_string")[0]
#print is_here_addr_function(func)
#print is_here_addr_function(func1)

p = getCurrentProgram()
funcs = list(p.getFunctionManager().getFunctions(1))

# OK, I freely admit I am ashamed of this loop:
#i=0
#while i < len(funcs):
#    f = funcs[i]
#    if is_here_addr_function(f):
#        print f
#    i=i+1

# This one is slightly better
for f in funcs:
    if is_here_addr_function(f):
        print f

print "Found {} here-data functions".format(len(funcs))  
        
# Now we know where and how many these functions are, and can try to save and characterize
#  the data sections they return. 
        
# We stopped here, and will resume from this point.


