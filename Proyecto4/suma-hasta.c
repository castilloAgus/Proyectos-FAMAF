#include <stdio.h>

int suma_hasta(int n){

   n=(n*(n+1))/2;
   return n;
}

int main (void){
    int n;
    int res;
    printf("ingresa un valor para n: \n");
        scanf("%d",&n);
    if(n>=0){
        res = suma_hasta(n);
        printf("el resltado es: %d\n",res); 
    }
    else {
        printf("error =(");
    }
    return 0;
}
