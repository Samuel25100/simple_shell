simple_shell
simple shell

Table of Contents
Description
Purpose
Requirements
File Structure
Usage
Examples
Bugs
Authors
License
Description
simple_shell is a simple command line interpreter based on the first Unix shell 'sh', created by Ken Thompson in 1971. simple_shell is intentionally minimalistic and contains functionality for only the most basic shell tasks - accepting input, parsing the input into a command and its arguments, and executing that input. Error checking is simple and follows Bash conventions.

Purpose
The purpose of the simple shell project is to understand:

how a shell works
PID and PPIDs
how processes are created
the three prototypes of main
how the shell uses the PATH to find and execute programs
the EOF/"end-of-file" condition
Requirements
Must follow Betty style and document guidelines
Allowed editors: vi, vim, emacs
Must have a README.md file
All header files must be include guarded
No more than 5 functions per files
File Structure
AUTHORS - list of contributors
check_helpers.c - helper functions that check for builtins
exit_check - checks if user_input is exit
blank_check - checks if user_input is \n
env_check - checks if user_input is env
env_helpers.c - helper functions related to PATH and other environment variables
get_path_count - gets count of path parts
get_path_array - tokenizes path to 2d array
find_path - finds and checks path for given command
print_env - shell builtin that prints current environment
error_helpers.c - helper functions that print appropriate error messages
command_error - command not found error
exec_error - command could not execute error
access_error - user does not have permission to execute command
exit_error - user has entered an invalid exit code
fork_wait_exec.c - process and execution function
memory_helpers.c - helper functions related to memory management
free_array - 2D array freeing function
man_1_simple_shell - manual page
number_helpers.c - helper functions pertaining to integers
_atoi - turns a numerical string into an integer
print_number - prints an integer to standard output
parse_input.c - command and argument parsing function
shell.c - main function
shell.h - header file
string_helpers.c - helper functions pertaining to string handling
_strlen - finds length of a string
_strcmp - compares two strings
_strdup - duplicates two strings (including memory management)
_putchar - writes a single character to standard output
Compilation
gcc -Wall -Wextra -Werror -pedantic *.c -o hsh

GCC 4.8.4 or later only

Usage Examples
Interactive Mode
~/me$ ./hsh
hella_shell$ echo & the bunnymen
& the bunnymen
hella_shell$ pwd
/home/me/hella_shell
hella_shell$
hella_shell$ exit
~/me$
Non-Interactive Mode
~/me$ cat hella_shell.txt | ./hsh
got me feelin' hella shell so let's just keep on codin'
~/me$
Bugs
At this time, there are no known bugs.

