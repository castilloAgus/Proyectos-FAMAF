#include <stdio.h>


void intercambiar(int tam, int a[], int i, int j){
int z;
int y=0;
    if (i>=0 && j>=0 && tam>y){
       z= a[i];
       a[i]=a[j];
       a[j]=z;
    }
    else {
        printf("eror\n");
    }
}

int main (void){
    int tam;
    printf("ingresa un tamano para el arreglo: \n");
        scanf("%d",&tam);
    int a[tam];
    int l=0;
    while (l<tam){
        printf("ingresa un valor para la posicion %d del arreglo: \n",l);
            scanf("%d",&a[l]);
        l=l+1;
    }
    int i,j;
    printf("ingresa un valor i para cambiar con j de 0 a %d: \n",tam-1);
        scanf("%d",&i);
    printf("ingresa un valor j para camniarla con i de 0 a %d: \n",tam-1);
        scanf("%d",&j);
    
    intercambiar (tam,a,i,j);
    printf("el intercamnio es: \n");
    for (int k=0; k<tam; k++){
       printf("%d\n",a[k]);
    }
    
    return 0;
}
