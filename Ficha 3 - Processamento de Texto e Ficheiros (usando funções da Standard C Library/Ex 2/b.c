#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64


int main(int argc, char* argv[]){
    
    char* namefile = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    for(int i=1; i<argc; i++){

        strcpy(namefile, argv[i]);
        char ch;
        FILE* ptr = fopen(namefile, "r");

        if(ptr==NULL){printf("Cant't open the file\n");}

        do{
            ch = fgetc(ptr);
            printf("%c", ch);

        }while(ch!=EOF);
        printf("\n");

        fclose(ptr);
    }
    return 0;
}