#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool pedir_booleano (char n){

    int x=2;
    while (!(x==1 || x==0)){
    printf("ingrese 1=true o 0=false : %c  \n",n);
    scanf("%d",&x);
    }
    assert (x==1 || x==0);
    return x;

}

void imprimir_booleano (bool x){
    
     if (x==1){
        printf("verdadero \n");
     }
    else {
    printf("falso \n");
    }
}

    int main(void){

        int x;
        char n = 'm';

        x=pedir_booleano(n);
        imprimir_booleano(x);
    
    return 0;
    }

