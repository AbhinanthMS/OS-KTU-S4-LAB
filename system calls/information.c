#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    struct stat sf;

    stat("directory.c", &sf);  // file name may be changed accordingly

    printf("Size: %ld\n", sf.st_size);
    printf("Mode: %o\n", sf.st_mode);
    printf("UID: %d\n", sf.st_uid);

    return 0;
}
