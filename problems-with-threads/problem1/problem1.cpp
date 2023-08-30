#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int global_argc;
char** global_argv;
int n;

void* thread(void* arg) {
	int index = *(int*)arg;
        int num1 = atoi(global_argv[index + 2]);
        int num2 = atoi(global_argv[index + 1]);
        int res;
        std::string op = global_argv[index + 3];
        if (op == "s") {
           res = num1 + num2;
        }

        else if (op == "m") {
           res = num1 * num2;
        }

        else if (op == "ss") {
           res = num1 * num1 + num2 * num2;
	}

        free(arg);
        std::string file = "out_";
        file += std::to_string(((index - 1) / 3) + 1);
        std::string text = "";
        text += global_argv[index + 1] + op + global_argv[index + 2] + " = " + std::to_string(res);
        int fd = open(file.c_str(), O_RDWR | O_CREAT, 0644);
        write(fd, text.c_str(), text.size());
        close(fd);

        return nullptr;
}

int main(int argc, char* argv[]){
        global_argc = argc;
        global_argv = argv;
        n = atoi(argv[1]);
        pthread_t th[n];
        int i = 1;
        while (i <= n * 3) {
             int* a = new int;
             *a = i;
             pthread_create(&th[(i - 1) / 3], NULL, &thread, a);
             i += 3;
	}
        i = 1;
        while (i <= n * 3) {
             pthread_join(th[(i - 1) / 3], NULL);
             i += 3;
        }
        return 0;
}

