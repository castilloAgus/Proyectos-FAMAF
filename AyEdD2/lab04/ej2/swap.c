#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(void){
    int x,y;
    x = 6;
    y = 4;
    printf(" before x=%d, y=%d\n", x,y);
    swap(&x,&y);
    printf(" after x=%d, y=%d\n", x,y);
    return 0;
}
