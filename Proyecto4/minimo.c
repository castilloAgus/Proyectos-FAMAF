#include <stdio.h>
#include <assert.h>

 int minimo (int n, int m){
    int res;
    if (n<m){
        res = n;
    }
    else {
        res = m;
    }
    assert ((n>=0 || n<0) && (m>=0 || m<0) );
    return res;

 }

 int main(void){
    int x,y;
    int result;
    printf("ingresa valores para x e y: \n");
        scanf("%d %d",&x,&y);
    result = minimo(x,y);
    printf("el minimo es %d\n",result);
    return 0;
 }
