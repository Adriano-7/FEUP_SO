#include <stdio.h>
#include "matrix.h"

int main(){
    matrix* mymatrix = matrix_new_random(3, 3, 1, 5);
    matrix_print(mymatrix);
    return 0;
}