#include <stdio.h>
#define N 4
int sumatoria(int tam, int a[]){
    int i=0;
    int res=0;
    while (i<tam){
        res = a[i]+res;
        i=i+1;
    }

    return res;
}


int main (void){
    int result;
    
    int a[N];
      
    for(int i=0;i<N;i++){
        printf("ingresa un valor para el elemento %d del arreglo:  \n",i);
            scanf("%d",&a[i]);
    }

    result=sumatoria(N,a);
    printf("el resultado es: %d\n",result);
    return 0;
}
