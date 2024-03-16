#include <stdio.h>

int main(void){
    int x,y;
    printf("ingrese un valor para x: \n");
     scanf("%d", &x);
    printf("ingrese un valor para y: \n");
     scanf("%d", &y);

    if (x>=y){
       x=0;
       printf("el valor de x sera: %d\n",x);
} 
    else
    x=2;
    printf("ingresa un nuevo valor para x: %d\n",x);
    
    printf("el valor final de x sera: %d\n",x);
    printf("el valor de final de y sera; %d\n",y);
    return 0;
}
