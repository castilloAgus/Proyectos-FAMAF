#include <stdio.h>
#include <limits.h>


typedef struct  {
float maximo;
float minimo;
float promedio;
} datos_t;

 datos_t stats(int tam, float a[]){
    float sum=0,min=INT_MAX, max=INT_MIN;
    datos_t result;
    for(int i=0; i<tam; i++){
        if(a[i]<= min){
            min = a[i];
            sum = sum+a[i];
        }
        else if (a[i]>=max){
            max=a[i];
            sum = sum + a[i];
        }
    }
    result.maximo = max;
    result.minimo = min;
    result.promedio = sum/tam;
    return result;
}

int main(void){
    int tam;
    printf("ingresa un tamaño para el arreglo: \n");
        scanf("%d",&tam);
    float a[tam];
    int i=0;
    while (i<tam){
        printf("ingresa un valor para la posicion %d del arreglo: \n",i);
            scanf("%f",&a[i]);
        i=i+1;
    }
    datos_t result =stats(tam,a);
    printf("el minimo es: %2.f\n",result.minimo);
    printf("el maximo es: %2.f\n",result.maximo);
    printf("el promedio es: %2.f\n",result.promedio);
    
    return 0;
}
