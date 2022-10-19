#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>


int main(int argc, char* argv[]) {
    struct stat info;
    
    if (argc <= 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }



    int total_bytes = 0;
    int total_blocks = 0;

    for(int i = 1 ; i<argc; i++){
        if (stat(argv[i], &info) == -1) {
        fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
        return EXIT_FAILURE;
        }
        total_bytes+=info.st_size;
        total_blocks += info.st_blocks;

        printf("%s last modification: %s, owner: %ld\n",
            argv[i], ctime(&info.st_mtime), (long) info.st_uid);
    }

    printf("Total stats - size: %d bytes, disk_block: %d\n", (int)info.st_size, (int)info.st_blocks);
    return EXIT_SUCCESS;
}