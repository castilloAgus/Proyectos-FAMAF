#include <stdio.h>
#include <stdbool.h>

typedef char clave_t;
typedef int valor_t;

typedef struct {
    clave_t clave;
    valor_t valor;
} asoc;

bool asoc_existe(int tam, asoc a[], clave_t c){
    for (int i=0; i<tam; i++){
        if (a[i].clave == c){
            return true;
        }   
    }
    return false;
}

int main(void){
    int tam;
    printf("ingresa un tamano para el arreglo: \n");
        scanf("%d",&tam);
    asoc a[tam];
    int i=0;
    clave_t clave;
        while (i<tam){
            printf("ingresa un char la clave %d del arreglo: \n",i+1);
                scanf(" %c",&a[i].clave);
            printf("ingresa un numero pra la clave %c del arreglo: \n",a[i].clave);
                scanf("%d",&a[i].valor);
            i=i+1;
        }
    printf("ingresa la clave a buscar: \n");
        scanf(" %c",&clave);
    
    if (asoc_existe(tam,a,clave)){
        printf("la clave %c esta en el arreglo\n",clave);
        }
    else {
        printf("no esta en el arreglo\n");
    }
    return 0;
}
