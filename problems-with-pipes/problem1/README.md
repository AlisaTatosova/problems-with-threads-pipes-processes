# problem-statement

Write a program that gets from outside a number N (N > 1 000 000), creates an array of size N and fills it with random integer numbers.
After that program should calculate the sum of array this way:
- Get from outside another number M that would be the number of parallel workers to calculate the sum
- Every parallel worker is a child process. Each process should take two indexes i and j, calculate sub-total sum of array from i to j and return the calculated number to parent.
- Every child process should also print the sub-total value (part of sum it calculated).
- All M processes should work in parallel and parent should wait them all
- After all the child processes completed calculation, the parent process should get all the sub-total values and calculate the final sum, and then, print the total summary.

Requirement: Parent and child communication should be implemented with pipes. Communication includes sending start and end index from parent to child as well as sending sub total from child to parent.


