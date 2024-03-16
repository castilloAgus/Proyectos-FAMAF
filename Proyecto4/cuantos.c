#include <stdio.h>

typedef struct {
int menores;
int iguales;
int mayores;
} comp_t ;

comp_t cuantos(int tam, int a[], int elem){
    comp_t res;
    int menor=0, igual=0, mayor=0;
    for (int i=0; i<tam; i++){
        if (a[i] < elem){
            menor = menor +1;
        }
        else if (a[i] == elem){
            igual = igual +1;
        }
        else {
            mayor = mayor +1;
        }
    }
    res.menores = menor;
    res.iguales = igual;
    res.mayores = mayor;
    return res;
}
int main(void){
    comp_t resultado;
    int tam;
    int elem;
    printf("ingresa un tamano para el arreglo: \n");
        scanf("%d",&tam);
    printf("ingresa un valor a comparar: \n");
        scanf("%d",&elem);
    int a[tam];
    int i=0;
    while (i<tam){
        printf("ingresa un valor para la posicion %d del arreglo: \n",i);
            scanf("%d",&a[i]);
        i=i+1;
    }
    resultado = cuantos (tam,a,elem);
    printf("eleemntos menores es: %d\n",resultado.menores);
    printf("eleemntos iguales es: %d\n",resultado.iguales);
    printf("eleemntos mayores es: %d\n",resultado.mayores);
    return 0;
}

