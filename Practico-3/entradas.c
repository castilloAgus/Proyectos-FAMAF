#include <stdio.h>

int pedir_entero(char n){
    
    int x;
    printf("se ingreso un dato que se almacena %c =",n);
    scanf("%d",&x);
    

    return x;
}

void imprimir_entero(char n, int x){

    printf("el entero almacenado en %c es %d\n",n,x);

}

int main(){
    
    int x;
    char n = 'm';
    
    x=pedir_entero(n);
    imprimir_entero(n,x);

    return 0;
}
