#include <stdio.h>
#include <assert.h>

void hola_hasta(int n){
    int i=0;
    while (i<n){
        printf("hola\n");
        i=i+1;
    }
    
}

int main(void){
    int x;
    printf("ingresa un numero para x: \n");
        scanf("%d",&x);
    assert (x>0);
    hola_hasta(x);
    return 0;
}
