# problem-statement
Write a program that implements the following shell behavior:
pr arg1 arg2 ...
echo Finish
That is, implement the execution of the program pr with arguments arg1, arg2, and so on (the number of arguments is not fixed), waiting for the completion of pr and printing the Finish line.
The name of the program and its arguments (pr and arg1, arg2, etc.) are passed to your program as command line arguments.
Printing the Finish line is implemented using printf.
Example:
./a.out cat file1 file2
Running your program this way should produce a son that will replace its body with the cat program with file1 and file2 arguments (PATH must also be used here). cat will print the contents of file1 and file2, exit. Your parent process waits for cat to complete and prints Finish. Don't forget the end-of-line character at the end.
