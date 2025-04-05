#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Process not created.\n");
    } else if (pid == 0) {
        printf("Child process: %d\n", getpid());
    } else {
        printf("Process ID: %d\n", getpid());
        wait(0);
        exit(0);
    }

    return 0;
}
