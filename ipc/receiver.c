#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    int shmid = shmget(123, 1024, 0666);
    char *a = (char *)shmat(shmid, NULL, 0);

    printf("Data read from memory: %s\n", a);
    return 0;
}
