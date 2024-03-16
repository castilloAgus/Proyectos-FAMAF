#include <stdio.h>

int pedir_entero(void){

    int n;
    printf("ingresa los valores de las variables: \n");
    scanf("%d",&n);

     return n;
}

void imprimirentero (int x){

    printf("el estado final es: %d\n",x);
}

int main(void){
    int x,y,z,m;

    x=pedir_entero();
    y=pedir_entero();
    z=pedir_entero();
    m=pedir_entero();

    if(x<y){
        m=x;
    }
    else {
        m=y;
    }
    imprimirentero(x);
    imprimirentero(y);
    imprimirentero(z);
    imprimirentero(m);

    if (m<z){

    }
    else{
        m=z;
    }
    imprimirentero(x);
    imprimirentero(y);
    imprimirentero(z);
    imprimirentero(m);


    return 0;
}
