#include <iostream> 
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){

    	int n = atoi(argv[1]);
    	int arr[n];
    	srand(time(NULL));

    	for (int i = 0; i < n; ++i) {
       		arr[i] = rand() % 5;
    	}

     	for (int i = 0; i < n; ++i) {
       		std::cout << arr[i] << " ";
    	}

    	std::cout << std::endl;

    	int m = atoi(argv[2]);

    	pid_t childs;
    	int pipe1[2];
    	int pipe2[2];
    	int pipe3[2];
        
    	pipe(pipe1);
        for (int i = 0; i < m; ++i) {
           childs = fork();
	   if (childs == -1) {
           	std::cout << "Error" << std::endl;
           }

           else if (childs == 0) {
	   	close(pipe1[0]);
		int j;
		close(pipe2[1]);
		read(pipe2[0], &i, sizeof(int));
		close(pipe3[1]);
		read(pipe3[0], &j, sizeof(int));

		int sum = 0;
                for (j = i * n / m; j < (i + 1) * n / m; j++) {
                    sum += arr[j];
                }
                std::cout << "The sum of " << i + 1 << "th range is " << sum << std::endl;

                if (write(pipe1[1], &sum, sizeof(int)) == -1) {
                   std::cout << "Error at writing\n";
                }

                close(pipe1[1]);
		exit(0);
           }
        }

	close(pipe2[0]);
	int i;
	write(pipe2[1], &i, sizeof(int));
	close(pipe2[1]);
	int j;
	close(pipe3[0]);
	write(pipe3[1], &j, sizeof(int));
	close(pipe3[1]);

	close(pipe1[1]);
	int result_sum = 0;
        for (int i = 0 ; i < m ; ++i) {
        	wait(NULL);
        	int sum;
	        read(pipe1[0], &sum, sizeof(int));
		result_sum += sum;
        }

	std::cout << "The result sum is " << result_sum;

}
