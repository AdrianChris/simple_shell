# Simple Shell Project

This is a simple implementation of a command-line interpreter for the Unix operating system created by **Christadrian Madegwa**

## Learning Objectives

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of **main**
* How does the shell use the **PATH** to find the programs
* How to execute another program with the **execve** system call
* How to suspend the execution of a process until one of its children terminates
* What is **EOF** / “end-of-file”?

## Requirements

* Allowed editors: vi, vim, emacs 
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the [Betty style](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl). It will be checked using **betty-style.pl**   and **betty-doc.pl**
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to [why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see     [Docker](https://github.com/moby/moby/blob/master/AUTHORS)

## Compilation and Installation

simple_shell is installed by running the following commands in your terminal.

    git clone https://github.com/AdrianChris/simple_shell.git

After that simple_shell can compile using

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

To start, write the following:

    ./hsh

## Contributors

[Christadrian Madegwa](https://github.com/AdrianChris)


