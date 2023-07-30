# problem-statement

Write a program that implements the following behavior of shell:  p1; p2; ...pn;
This design means sequential launch of programs: before starting the next program, you need to wait for the completion of the previous one.
That is, first a son process is created, which replaces its body with the p1 program, the father waits for its completion. 
Then a process is created for p2, and so on. When searching for programs, the PATH environment variable must be used (you need to use the correct exec for this).
Program names (p1, p2, ..., pn) are passed to your program as command line arguments.
* Example (a.out is your program's executable):
./a.out pwd ls date
As a result, 3 sons will be created (not immediately, sequentially), the current working directory will be displayed, after that the contents of the current directory, and at the end the current date.

