| Title | Version | Date | 
| ------ | ------ |  ------ |
| Simple Shell | 3 | April 11, 2023

## NAME
Simple Shell

## SYNOPSIS
This function requires the following elements:

Main file: "main_shell.c"
<br>Header file: "shell.h"

## DESCRIPTION
Shell is a command programming language that executes commands read from a terminal or a file and breaks it up into words at whitespace (blanks and tabs).
This shell mimics /bin/sh in it's funcationaly. It can be ran in both interacitve and noninteractive modes.

## BUILT-INS
```sh
env - ./hsh prints the current environment to standard output.
exit - when is entered, shell exits out of the shell program.
```
## INVOCATION
If no arguments are present and if the standard input of the shell is connected to a terminal, the shell is considered an interactive shell.

If the standard input is used with a pipeline operator, |, to connect the command, such as echo "qwerty" | ./hsh, then the shell is in non-interactive mode.

It is compiled in this way:

root@d8922e3653ac:# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
root@d8922e3653ac:#  ./hsh

Run the following command to view the MAN page:

man -l man_simple_shell.3

## EXAMPLES
root@d8922e3653ac:#  ./hsh

$ echo "qwerty" | /bin/sh
"qwerty" | /bin/sh

$ echo "qwerty" | ./hsh
"qwerty" | ./hsh

## RETURN VALUE
Upon successful return, the shell will always return a 0 for success. If the shell program fails when a command is entered incorrectly or does not exist in the $PATH, then shell program will exit out of the child process and display an error message corresponding to the error the user committed and return with a prompt.

## NOTES
All files and code used in .hsh were created and compiled on "Ubuntu 20.04.4 LTS"
## BUGS
This is a simple shell (./hsh) there are many features and builtin commands such as aliases, cd, and logical operators that are not implemented.

## AUTHORS
Kolton Rhodes and Carlos Alarcon
