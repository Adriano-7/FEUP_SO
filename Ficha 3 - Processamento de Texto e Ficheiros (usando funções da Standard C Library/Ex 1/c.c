#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]){
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);

    int count = 0;
    const char *tmp = p2;
    
    while((tmp = strstr(tmp, p1)))
    {
        count++;
        tmp++;
    }

    printf("The string %s is found %d times in %s \n", p1, count, p2);
    return 0;
}
