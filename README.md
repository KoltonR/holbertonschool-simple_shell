# Simple Shell Project for Holberton School

## Description
This is a simple UNIX shell command interpreter. It reads user input from the command line, interprets it, and executes commands.

## To Run:
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

This shell can be run in interactive mode: ./hsh

Or non-interactive mode: echo "pwd" | ./hsh

## Examples Usage

```sh
$ ls -l  (lists directory contents using a long listing format)
total 1
-rw-r--r-- 1 root root   213 Apr 14 13:15 AUTHORS

$ ls -l /tmp/ 
total 1
-rw-r--r-- 1 root  root   0 Mar 29  2022 right_school
$
$ pwd (prints the working directory)
/holbertonschool-simple_shell
$
$ file_x (prints error because "file_x" does not exist)
file_x: No such file or directory
$
$ exit (To exit the program, you can type in either crtl + d or "exit".)
```

## Task

0. README, man, AUTHORS
- write a README, a man for your shell, and a AUTHORS file at the root of the repository, listing all individuals that contributed content to the repository.
1. Betty would be proud
- write a beautiful code that passes the Betty checks.
2. Simple shell 0.1
- write a UNIX command line interpreter.
3. Simple shell 0.2
- simple shell 0.1 + handle command lines with arguments
4. Simple shell 0.3
- simple shell 0.2 + handle the PATH, fork must not be called if the command doesn't exist
5. Simple shell 0.4
- simple shell 0.3 + implement the exit built-in that exits the shell, you don't have to handle any argument to the built-in exit
6. Simple shell 1.0
- simple shell 0.4 + implement the env built-in that prints the current environment.



## Authors
Kolton Rhodes and Carlos Alacon
