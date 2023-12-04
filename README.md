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

In this workshop, you will learn how to use gdb to debug a program. You will also learn how to use the most common commands of gdb.

# Simple commands

<!-- put the basic commands in gdb to debug example1.c program -->

## Pre-tasks

#### Compile the example1.c program

```bash
make example1
```

#### Run the example1 program

```bash
./example1
```

### it will Segfault

#### Run the example1 program with gdb

```bash
gdb ./example1
```

## Tasks

<!-- need to explain this commands and how to use them info gdb 					//Manual
info locals 				        //Vars in local scope
info variables				//Vars declared outside current scope
info functions				//Names and datatypes of all defined functions
info b 						//List all breakpoints
break funcName				//Set breakpoint at function funcName (short: b funcName)
break file::line			        //Set breakpoint at line in file
layout next					//Cycle through the layouts of gdb
p var 						//Print the value of variable var
p var = value 			        	//Force set value to a var
run 						        //Start the program
start 						//Synonymous to (b main && run). Puts temporary b at main
next 						//Execute the current line in source (short: n)
step 						//Step into function call at current line (short: s)
finish						//Finish the execution of current function (short: fin)
continue					//Resume execution (After a breakpoint) (short: c)
refresh 					        //Repaint the interface (To fix corrupted interface)
shell cmd 					//Run shell command cmd from gdb prompt
python gdb.execute(cmd)		//Run a gdb command cmd from python prompt
set print pretty on			//Enable pretty printing
							  (Put in ~/.gdbinit)
$ gdb -c core.num			//Examine the dumped core file from a SIGSEGV(shell command)
bt							//Print backtrace
break _exit 				        //Breakpoint at exit of program
whatis expr					//Print datatype of expr
ptype expr					//Detailed print of datatype of expr
watch var 					//Stop when var is modified
watch -l foo				        //Watch foo loaction
rwatch foo					//Stop when foo is read
watch foo if foo>10			//Watch foo conditionally
delete						//Delete all breakpoints
delete breakpoint_no		        //Delete breakpoint breakpoint_no
command breakpoint_no		//Run user listed commands when breakpoint is hit
							  (End list of commands with 'end')
file executable 			        //Load the executable for debugging from inside gdb
quit						        //Quit (short: q)
 -->

#### List all breakpoints

    ```bash
    info b
    ```

#### Set breakpoint at function funcName (short: b funcName)

    ```bash
    break funcName
    ```

#### Set breakpoint at line in file

    ```bash
    break file::line
    ```

#### Cycle through the layouts of gdb

    ```bash
    layout next
    ```

