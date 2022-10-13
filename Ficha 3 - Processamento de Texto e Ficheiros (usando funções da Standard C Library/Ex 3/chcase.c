#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]){

    FILE* ptr = fopen(argv[1], "r");
    char ch;

    if(ptr==NULL){printf("Cant't open the file\n");}

    if(argc==2){
        while(!feof(ptr)){
            ch=fgetc(ptr);
            printf("%c", ch);
        }
        printf("\n");
        return 0;
    }

    if(!strcmp(argv[2], "-u")){
        while(!feof(ptr)){
            ch=fgetc(ptr);
            printf("%c", toupper(ch));
        }
    }
    else if(!strcmp(argv[2], "-l")){
        while(!feof(ptr)){
            ch=fgetc(ptr);
            printf("%c", tolower(ch));
        }
    }

    printf("\n");
    fclose(ptr);
    return 0;
}