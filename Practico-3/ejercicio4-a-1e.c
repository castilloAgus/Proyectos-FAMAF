#include <stdio.h>

int main(void){
    int x,y;
    printf("ingrese un numero para x: \n");
     scanf("%d", &x);
    printf("ingrese otro numero para y: \n");
     scanf("%d", &y);

    if (x>=y){
        x=0;
        printf("el valor para x va a ser: %d\n",x);
    }  

    else
    x=2;
    printf("el valor de x sera: %d\n",x);

    printf("el valor final de x es: %d\n",x);
    printf("el valor final de y: %d\n",y);
    return 0;
}
