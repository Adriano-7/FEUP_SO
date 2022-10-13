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

    int result = strcmp(p1, p2);

    if(result==0){
        printf("The strings are the same\n");
    }
    else{
        printf("The strings aren't the same\n");
    }

    return 0;
}