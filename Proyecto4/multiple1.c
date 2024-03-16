#include <stdio.h>

void multiple1 (int x, int y){
    int z;
    z=x;
    x=z+1;
    y=z+y;
    printf("el resultado es: %d %d\n",x,y);
}

int main(void){

    int x,y;
    printf("ingresa valores para x e y: \n");
        scanf("%d %d",&x,&y);
    multiple1(x,y);

    return 0;
}
