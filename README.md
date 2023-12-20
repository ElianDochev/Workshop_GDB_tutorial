<div style="display: flex; flex-direction: row; justify-content: center; align-items: center;">
  <p align="center">
  <h1 align="center"> Eliyan Dochev </h1>
   <div align="center"  class="icons-social" style="margin-left: 10px;">
          <a style="margin-left: 10px;"  target="_blank" href="https://www.linkedin.com/in/elian-dochev-8a53a9250/">
  			<img  style="width: 40px; height: 40px" src="https://img.icons8.com/doodle/40/000000/linkedin--v2.png"></a>
          <a style="margin-left: 10px;" target="_blank" href="https://github.com/ElianDochev">
  		<img  style="width: 40px; height: 40px" src="https://img.icons8.com/doodle/40/000000/github--v1.png"></a>
  		<a style="margin-left: 5px;" target="_blank" href="mailto:eliyan.dochev@epitech.eu">
  					<img style="width: 40px; height: 40px" src="https://image.similarpng.com/very-thumbnail/2021/09/Outlook-icon-on-transparent-background-PNG.png" ></a>
        </div>
  </p>

  <p align="center">
  <h1 align="center"> Vasiliy Novikov </h1>

   <div align="center"  class="icons-social" style="margin-left: 10px;">
          <a style="margin-left: 10px;"  target="_blank" href="#!/">
  			<img  style="width: 40px; height: 40px" src="https://img.icons8.com/doodle/40/000000/linkedin--v2.png"></a>
          <a style="margin-left: 10px;" target="_blank" href="#!">
  		<img  style="width: 40px; height: 40px" src="https://img.icons8.com/doodle/40/000000/github--v1.png"></a>
  		<a style="margin-left: 5px;" target="_blank" href="mailto:#!">
  					<img style="width: 40px; height: 40px" src="https://image.similarpng.com/very-thumbnail/2021/09/Outlook-icon-on-transparent-background-PNG.png" ></a>
        </div>
  </p>
</div>

# Introduction

Welcome to the GDB Workshop, a comprehensive exploration of debugging in C/C++ using the GNU Debugger (GDB). In it we'll unravel the mysteries of debugging, delve into GDB's intricacies, and provide hands-on experience with a deliberately flawed C program. Get ready to become a debugging maestro!

# Why use a debugger?

We all had the experince of writing a program, running it and founding out that it segfaults or worse does not work as expected. We all have used printf on every variable or to display "got to here" to debug our programs. This is a nightmare to do and it wastes a lot of time.

This is where a debugger comes in. A debugger is a program that allows you to run your program in a controlled environment and examine the state of your program at any point in time. One such debugger is GDB.

# Why use GDB?

GDB is a command line debugger that is available on most Linux distributions. It is a powerful tool that allows you to examine the state of your program at any point in time. It is also available on most Linux distributions. it is perfect for GCC and G++ compiled programs.

# Requirements

for this workshop you will need:
GNU gcc compiler - you likely already have this installed
GNU gdb debugger - you likely already have this installed

if you don't have them installed you can install them with the following commands:

Debian/Ubuntu

```bash
sudo apt install gcc
sudo apt install gdb
```

Fedora

```bash
sudo dnf install gcc
sudo dnf install gdb
```

# Understanding the basics

## Compiling with debug symbols with Makefile

When compiling a program with gcc or g++ you can add the -g3 flag to add debug symbols to the executable. This allows the debugger to map the executable to the source code.

Hint: you should add the -g3 flag to your Makefile

Note: many error can be detected at compile time with the -Wall flag so you may want to add that as well

## Run the makefile and execute the program

The program should sum the first n prime numbers and print the result. However, it is buggy and it will be up to you to fix it.

```bash
./test_buggy \[Number of primes to sum\]
```

Note: the argument is optional and if not provided the program will default to 10

The program will be stuck in a infinite loop. Now we will use gdb to find the bug.

## Running the program in gdb

```bash
gdb ./test_buggy
```

Note: if you want you can assing the cmd line arguments in gdb with the following command:

```bash
gdb --args ./test_buggy \[Number of primes to sum\]
```

Here is a list of commands that you can use in gdb, we will go over them in the next steps:

```txt

layout next					// Show source code in GUI
info locals 				// Vars in local scope
info variables				// Vars declared outside current scope
info functions				// Names and datatypes of all defined functions
info b 						// List all breakpoints
break funcName				// Set breakpoint at function funcName (short: b funcName)
break file::line			// Set breakpoint at line in file
layout next					// Cycle through the layouts of gdb
p var 						// Print the value of variable var
p var = value 			    // Force set value to a var
run 						// Start the program
start 						// Synonymous to (b main && run). Puts temporary b at main
next 						// Execute the current line in source (short: n)
step 						// Step into function call at current line (short: s)
finish						// Finish the execution of current function (short: fin)
continue					// Resume execution (After a breakpoint) (short: c)
refresh 					// Repaint the interface (To fix corrupted interface)
shell cmd 					// Run shell command cmd from gdb prompt
python gdb.execute(cmd)		// Run a gdb command cmd from python prompt
set print pretty on			// Enable pretty printing (Put in ~/.gdbinit)
$ gdb -c core.num			// Examine the dumped core file from a SIGSEGV(shell command)
bt							// Print backtrace
break _exit 				// Breakpoint at exit of program
whatis expr					// Print datatype of expr
ptype expr					// Detailed print of datatype of expr
watch var 					// Stop when var is modified
watch -l foo				// Watch foo loaction
rwatch foo					// Stop when foo is read
watch foo if foo>10			// Watch foo conditionally
delete						// Delete all breakpoints
delete breakpoint_no		// Delete breakpoint breakpoint_no
command breakpoint_no		// Run user listed commands when breakpoint is hit
							  (End list of commands with 'end')
file executable 			// Load the executable for debugging from inside gdb
quit						// Quit (short: q)
```

## Display source code in gdb

This line will display the source code in the GUI

```bash
layout next
```

Note: you will see nothing because the program is not run yet

## Running the program in gdb

```bash
run
```

The program will be stuck in a infinite loop. Now we will use gdb to find the bug.
press **_ctrl+c_** to stop the program so we can debug it

## examine the code flow

you will see that the program is stuck on line 57. To demosntrate that we will use the next command

```bash
next
```

You will see how the program is not progressing.

Note: you can use a short version of the command by typing **n** instead of **nexts**

lets print some of the variables to see what is going on

```bash
print i
print x
print n
```

Note: you can use a short version of the command by typing **p** instead of **print**
Hint: if you use print(p) without any arguments it will print the last printed variable

## Step into a function

As you can see the problem is in the function **is_prime**. To go into the function we will use the step command. Remember that next goes over the function calls and step goes into the function calls, otherwise they behave the same.

```bash
step
```

Note: you can use a short version of the command by typing **s** instead of **step**

lets print some numbers to see what is going on. use **print**. For example print **x**

Hint: Doesn't that if statement look suspicious?

## After finding the first bug

Great job! You have found the first bug. Now lets fix it. To do that we must first exit the gdb. To do that we will use the quit command.
I encourage you to think of some other corner cases that our programe might run into.

Hint: how are negative numbers handled? what about 0 and 1?

```bash
quit
```

now fix the bug and recompile the program. Then run it again and see where that gets us.

## Back to gdb
Oh no! we have another bug. Lets go back to gdb and see what is going on.

We know how to do that so lets do it.


