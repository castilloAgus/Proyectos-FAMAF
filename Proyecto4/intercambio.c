#include <stdio.h>

void intercambio (int x, int y){

    int z;
    z = x;
    x = y;
    y = z;
    printf("el intercamio entre x=%d e y=%d es: x=%d, y=%d\n",z,x,x,z);
}

int main(void){
    int x,y;
    printf("ingresa valores para x e y: \n");
        scanf("%d %d",&x,&y);
    intercambio(x,y);    
    return 0;
}
