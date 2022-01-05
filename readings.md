---
title: Resources and links
layout: default
---

ABI (Application Binary Interface) is the reverse engineer's best friend and best-kept open secret.

Understanding the ABI means understanding how the compilation pipeline works and
how information about the program's variables and functions (more generally, "symbols")
is passed between the stages of the compiler.

GCC options to examine these stages, in a nutshell:
<http://www.ouah.org/RevEng/x24.htm>

Do the steps in Parts 1 and 2 of this article:
<http://www.linuxjournal.com/content/examining-compilation-process-part-1>
<http://www.linuxjournal.com/content/examining-compilation-process-part-2>
<http://www.linuxjournal.com/content/examining-compilation-process-part-3>

I recommend reading sections of 
      "Introduction to Reverse Engineering Software in Linux" 
             <http://www.ouah.org/RevEng/t1.htm>
about tools you haven't yet encountered in your programming
experience. The "Understanding Assembly" chapter is also very useful
if you haven't done assembly before -- but nothing can replace playing
with the compiler ('gcc -S', 'objdump -d', etc.) on your own.

==================[ Item 1: x86-64 CPU and assembly history ]==========

<http://opencsw.wdfiles.com/local--files/porting-faq/solaris-on-x86.pdf>
explains how it got that way. In particular, pp. 9--12 and 19--20
discuss the history, pp. 25--27 discuss the registers, and pp. 28--31
describe addressing modes and the unfortunate divergence between Intel
and AT&T assembly syntax. Pages 32--41 explain the ABI.

==================[ Item 2: AMD64/x86_64 ABI ]========================

Get it: <https://www.uclibc.org/docs/psABI-x86_64.pdf>

Read sections 3.1 and 3.2; then sections 4 and 5.

On page 20 of the AMD64 ABI document, find how integer and pointer
arguments are passed to functions:

>  If the class is INTEGER, the next available register of the sequence %rdi,
>  %rsi, %rdx, %rcx, %r8 and %r9 is used.

Note that this is very different from the 32-bit Linux calling convention,
where arguments are pushed onto the stack by the caller function, rather
than being passed in registers. See Item 3.

Look at Figure 3.3 on page 16 to see the layout of an amd64 stack frame.

Look at Figure 3.1 on page 12, which shows how different C types are represented.
This table is very important; not understanding these representations leads
to nasty surprises like integer overflows.

==================[ Item 3: Intel 32-bit ABI ]========================

You may also find the "Tiny guide to the 32-bit x86 assembly language"
by Adam Ferrari and others useful (a local copy is at
<https://www.cs.dartmouth.edu/~sergey/cs108/tiny-guide-to-x86-assembly.pdf>).
It is dated (32 bit code is aging fast), but lucid.

==================[ Links and quick summaries ]========================

<http://www.ouah.org/RevEng/x24.htm> -- A brief summary of the Linux compilation process, with GCC (and LLVM) options that matter.

<https://www.linuxjournal.com/content/examining-compilation-process-part-1> -- Examining the Compilation Process, by Mike Diehl (see also <http://www.linuxjournal.com/content/examining-compilation-process-part-2>, and <http://www.linuxjournal.com/content/examining-compilation-process-part-3>)

<http://www.ouah.org/RevEng/t1.htm> -- Introduction to Reverse Engineering Software in Linux, a really useful summary of classic Linux tools for handling binaries. Although Linux binaries have gotten more complex since then, this is still and excellent reference.





