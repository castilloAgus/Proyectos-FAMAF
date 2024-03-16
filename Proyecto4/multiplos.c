#include <stdio.h>
#include <stdbool.h>

bool todos_pares (int tam, int a[]){
    for (int i=0; i<tam; i++){
        if( a[i] % 2 ==0){
            return 1;
        }
    }   

 return 0; 
}   
bool existe_multiplo (int m, int tam, int a[]){

    for (int i=0; i<tam; i++ ){
        if (a[i] % m == 0){
            return 1;
        }
    }
    return 0;
}

int main (void){
    bool result;
    int y;
    int tam;
    printf("ingresa un tamano para el arreglo; \n");
        scanf("%d",&tam);
    printf("ingresa 1 para ver si son todos pares o ingresa 2 si queres ver si existe un multiplo: \n");
        scanf("%d",&y);
    int a[tam];
    int i=0;
    while (i<tam){
        printf("ingresa un valor para la posisicion %d del arreglo: \n",i);
            scanf("%d",&a[i]);
            i=i+1; 
     }
    if (y==1){
        result = todos_pares(tam,a);
        printf("1=true, 0=false: %d\n",result);
    }

    else if (y==2){
        int m;
        printf("ingresa un valor para m: \n");
            scanf("%d",&m);
        result = existe_multiplo(m,tam,a);
        printf("1=true, 0=false: %d\n",result);
    }

    else {
        printf("error\n");
    }
    return 0;
}

