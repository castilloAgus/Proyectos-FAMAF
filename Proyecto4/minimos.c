#include <stdio.h>
#include <limits.h>

int minimo_pares(int tam, int a[]){
    int result = INT_MAX;
    for (int i=0; i<tam; i++){
        if (a[i] % 2 ==0 && a[i]<result ){
            result = a[i];
        }
        
    }
    return result;
}
int minimo_impares(int tam, int a[]){
    int result = INT_MAX;
    for (int i=0; i<tam; i++){
        if (a[i] % 2!=0 && a[i]<result){
            result=a[i];
        }
    }
    return result;
}
int main(void){
    int minpar;
    int minimpar;
    int tam;
    printf("ingresa un tamano del arreglo: \n");
        scanf("%d",&tam);
    int a[tam];
    for (int i=0; i<tam; i++){
        printf("ingresa un valor para la posicion %d del arreglo: \n",i);
            scanf("%d",&a[i]);
    }
    minpar = minimo_pares (tam,a);
    if (minpar % 2 == 0){
    printf(" el minimo par es: %d\n",minpar);
    }
    else {
        printf("no hay par\n");
    }
    minimpar = minimo_impares(tam,a);
     if (minimpar % 2 != 0){
        printf("el minimo impar es: %d\n",minimpar);
     }
     int minimo_total = minpar<minimpar ? minpar : minimpar;
     printf("el minimo del arreglo es: %d\n",minimo_total); 
    return 0;
    
}
