#include <stdio.h>

int main(void){
    int x;
    printf("ingrese un valor para x: \n");
    scanf("%d",&x);

    while (x!=0){
        printf("el estado actual es: %d\n",x);
        x=x-1;
        printf("el estaro sera: %d\n",x);

    }
        printf("el estado final es: %d\n",x);

    return 0;
}
