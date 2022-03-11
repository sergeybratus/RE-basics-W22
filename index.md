---
title: Basics of Reverse Engineering Winter 2022
layout: default
---

<h1>Basics of Reverse Engineering Winter 2022</h1>

<p>Dartmouth CS69.16 "Basics of Reverse Engineering" course materials will be available in this public repository.

<p><a href="syllabus-draft.pdf">Draft syllabus</a>. Please note that this is <b>draft</b>. 
Although the focus and pre-requisites of the course will not change, week-by-week topics and activities will likely go though several rounds of changes, to accommodate student backgrounds and requests.

<p>This is a brand-new course, in a rapidly changing technical field. We'll be experimenting and adjusting course materials as we go.

<hr>

<p><a href="https://sergeybratus.github.io/RE-basics-W22/day1-slides.pdf">Day 1 slides</a>

<p><a href="https://sergeybratus.github.io/RE-basics-W22/readings">Day 1 readings and notes</a>

<p><a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day1-src/">Day 1 examples</a> and
<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/homework1/">homework</a>

<hr>

<p><a href="https://sergeybratus.github.io/RE-basics-W22/day2-slides.pdf">Day 2 slides</a>

<p><a href="https://sergeybratus.github.io/RE-basics-W22/readings1">Day 2 readings and notes</a>

<p><a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day2-src/">Day 2 examples</a>, 
<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/homework2/">homework</a>,
and a resolution for the in-class embarrassing <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day2-src/why-no-lazy-linking.txt">dynamic linking mystery</a>.

<hr>

Notes from the X-hour: <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/day2-src/notes/local-vs-global-xhour-notes.txt">local vs global variables</a> and related topics. I also posted notes on
<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day2-src/notes/c-compilation-and-linking.txt">compilation</a>,
<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day2-src/notes/c-optimization-vs-code.txt">optimization</a>,
<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day2-src/notes/hello-world-disasm.txt">hello world disassembly example</a>, based on x86 MacOS binary environment.

<hr>

Day 5: <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/day5-src/sign-extension-and-syscalls.txt">Signed arithmetic and basic syscalls</a>, <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/day5-src/shellcode.txt">simple shellcode</a>, with <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day5-src">examples</a>. 

Videos from Day 5: <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/videos/CS69.16:169%20Day%205%20Part%201.mp4">Part 1</a> and <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/videos/CS69.16:169%20Day%205%20Part%202.mp4">Part 2</a>.

<hr>

Day 6: <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/day6-src/on-switches.txt">Notes on switches</a> and a quick <a href="https://github.com/sergeybratus/RE-basics-W22/blob/main/day6-src/starting-on-Cplusplus.txt">Introduction to C++ compilation</a>. See also
  <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day6-src">examples/</a>

<hr>

X-hour on C++ disassembly in Ghidra: <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/day6-Xhour-slides.pdf">slides</a> (look for the recorded video link in email).

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Cplusplus/inheritance-notes.txt">Notes on C++ inheritance implementation and artifacts</a>.

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Travis-Goodspeed-guest-lecture-week4-tues.pdf">Travis Goodspeed guest lecture</a>.

<p><a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/loading-raw-binary-into-ghidra.txt">Notes on loading raw binaries in Ghidra</a> (the lost part of the X-hour video).

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/GBA-Ghidra-example-notes.txt">Notes on Ghidra analysis of a GBA ARM v4t ROM</a>

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Ghidra-Sleigh-and-Pcode-notes.txt">Notes on Ghidra's Sleigh CPU/instruction definitions and P-code</a> (teaching Ghidra to recognize, disasseble, and decompile a GBA instruction it considers invalid out of the box).

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/annotate-GBA-strings.py">Example GBA automation script</a> from the cancelled X-hour. We'll revisit it in class on Tuesday.

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Random_Acts_of_RE_Graham.pdf">Robert Graham's invited talk slides</a>

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Ghidra-scripts-and-class-hierarchy-notes.txt">GhidraScript and class hierarchy notes</a>

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/instructions-matching-log.txt">Notes from the X-hour</a> on matching native instruction by scripting and the <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/find-here-data-functions.py">ad hoc plugin</a> to do it.

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/RiverLoopSecurity-FirmwareCarving-202202.pdf">Firmware Carving</a> slides from the River Loop Security invited talk.

<hr>

Invited talk <a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/GHIDRA-For-Dartmouth.pdf">Program Analysis With Ghidra</a> by Alexei Bulazel, with Ghidra script <a href="https://github.com/0xAlexei/Publications/tree/master/Ghidra">code</a>. 

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/REing_the_cloud.pdf">Slides</a> from invited X-hour talk by Jacob Torrey.

<hr>

<a href="https://github.com/sergeybratus/RE-basics-W22/tree/main/Sophia-DAntoine-inivted-talk-03032022.pdf">Slides</a> from invited talk by Sophia D'Antoine. 

<hr>


