#include <stdio.h>
#include <stdlib.h>
#include "other.h"

/* All Other Function Sotre Here */
void printBorderPattern(int line){
    for(int i =0; i<line+2; i++){
        printf("*");
    }
    printf("\n");
}

