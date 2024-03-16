#include <stdio.h>
#define N 3

int prim_iguales (int tam, int a[]){

    int res=0;
    for ( int i=0; i<tam; i++){
        if (a[i] == a[i+1]){
            res = res + 1;
        }
        else {
            break;
        }
    }
    return res;
    
}

int main(void){
    int a[N];
    int result;

    int i=0;
    while (i<N){
        printf("ingresa %d valores para la posicion %d del arreglo: \n",N,i);
            scanf("%d",&a[i]);
            i=i+1;
    }
    result = prim_iguales (N,a)+1;
    printf("el tramo mas largo del arreglo es: %d",result);
    return 0;
}
