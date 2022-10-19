#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    /* check if exactly one argument is present */
    if (argc <= 2) {
        printf("usage: cat filename\n");
        return EXIT_FAILURE;
    }

    for(int i=1; i<argc; i++){
        int fd = open(argv[i], O_RDONLY);
        if(fd == -1){
            printf("error: couldn't open the %d file", i);
            return EXIT_FAILURE;
        }

        char buffer[BUFFER_SIZE];
        int bytesin;
        while((bytesin = read(fd, buffer, BUFFER_SIZE))>0){
            write(STDOUT_FILENO, buffer, bytesin);
        }
        close(fd);
    }
    return EXIT_SUCCESS;
}