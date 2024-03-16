#include <stdio.h>
#include <assert.h>

int absoluto(int x){
    
    if (x>=0){
        x = x;
    }
    else {
        x=-x;
    }
    assert (x>=0 || x<0);
    return x;
}

int main(void){
    int res;
    int i;
    printf("ingresa un valor para i: \n");
        scanf("%d",&i);
    res = absoluto(i);
    printf("el valor absoluto de %d es %d\n",i,res);
    return 0;
}
