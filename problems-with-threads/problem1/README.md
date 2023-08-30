# problem-statement

Develop a multi-threaded application that implements the following behavior:
The program receives from outside the number N - the number of operations, the next N lines look like: "number1" "number2" "operation".

Operations can be as follows:
s - addition
m - multiplication
ss - sum of squares

The program creates N threads that perform the required operations on numbers,
each thread creates a file called out_i, where i is the thread number (i = 1,2,3 .. N), and writes the following result there: "num_1" "operation" "num_2 " = result. for example: "1 s 2 = 3".

Input example:
4
1 2 s
5 6 m
2 2 ss
0 1 m

result:
out_1 out_2 out_3 out_4

out_1: "1 s 2 = 3"
out_2: "5 m 6 = 30"
out_3: "2ss 2 = 8"
out_4: "0 m 1 = 0" 

For compiling use -pthread
-> g++ -o test file_name.cpp -pthread

