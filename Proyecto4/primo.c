#include<stdio.h>
#include <stdbool.h>

bool es_primo(int x){
    int i=2;
    while (x%i !=0 && x>1){
        i=i+1;        
    }
    return (i==x);
    
}

int nesimo_primo(int N){
int primerprimo = 2;
int num = 3;
int contador=1; 
    if (N==1){
        return primerprimo;
    }
    
    while (contador < N){
        if (nesimo_primo(es_primo(N))){
            contador = contador+1;
        }
        if (contador < N){
            num = num +2;
        }
    }
    return num;
}

int main(void){ 
    int N;
    do {
        printf("ingrese un enterto no negativo: \n");
        scanf("%d",&N);
        if(N<0){
            printf("no es posible, elegi un numero no negativo.\n");
        }
        else if (N==0){
            printf("el primer primo es 2. \n");
        }
        else {
            int primo = nesimo_primo(N);
            printf("el %d-esimo primo es: %d\n",N,primo);
        }
    }
    while (N<0);
       
    return 0;
}
