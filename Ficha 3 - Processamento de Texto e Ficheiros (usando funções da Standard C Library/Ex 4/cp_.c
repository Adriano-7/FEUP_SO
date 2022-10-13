#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]){

    FILE* from = fopen(argv[1], "r");
    FILE* to = fopen(argv[2], "w");

    if(from==NULL){printf("Couldn't open file 1"); exit(1);}
    
    char c;

    while ((c = getc(from)) != EOF) {
    putc(c, to);
    }

    fclose(from);
    fclose(to);
}