#include <stdio.h>

void pedir_arrreglo (int n_max, int a[]){
      int i=0;
    while (i<n_max){
        printf("ingresa un valor en la posicion %d del arreglo: \n",i);
            scanf("%d",&a[i]);
        i=i+1;    
    }
}

void imprimir_arreglo (int n_max, int a[]){
    int i=0;
    printf("el arreglo ingresado: \n");
    while (i<n_max){
        printf("en el elemento %d del arreglo se le asigna %d\n",i,a[i]);
        i=i+1;
    }
}


int main (void){
    int n;
    printf("ingresa un tamano para el arreglo: \n");
        scanf("%d",&n);
    int a[n];
    pedir_arrreglo(n,a);
    imprimir_arreglo(n,a);
    return 0;
}
