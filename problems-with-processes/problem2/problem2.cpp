#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main() {
  pid_t pid = fork();

  if (pid == -1) {
    std::cout << "Error" << std::endl;
  }

  if (pid == 0) {
    kill(getppid(), 9);
  }

  else {
    wait(NULL);
  }
}
