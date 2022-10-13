#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]){
    char ch;
    if(argc == 2){
        FILE *ptr = fopen(argv[1], "r");
        int nchar = 0;
        while((ch = fgetc(ptr)) != EOF){nchar++;}
        printf("%d", nchar);
        fclose(ptr);
    }
    else{

        FILE *ptr = fopen(argv[2], "r");
        int nchar=0;
        int nlines=0;
        int nwords=0;

        while((ch = fgetc(ptr)) != EOF){
            nchar++;
            if (ch == '\n' || ch == '\0')nlines++;
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')nwords++;
        }

        if(strcmp(argv[1], "-c")==0){printf("%d\n", nchar);}
        if(strcmp(argv[1], "-w")==0){printf("%d\n", nwords);}
        if(strcmp(argv[1], "-l")==0){printf("%d\n", nlines);}

        fclose(ptr);
    }
}