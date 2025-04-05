#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    int shmid = shmget(123, 1024, 0666 | IPC_CREAT);
    char *a = (char *)shmat(shmid, NULL, 0);

    printf("Write data: ");
    scanf("%s", a);

    printf("Data written: %s\n", a);
    return 0;
}
