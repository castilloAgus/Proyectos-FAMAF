#include <stdio.h>

void multiple2 (int x, int y, int z){
    int m;
    int n;
    m=y;
    n=x;
    x=m;
    y=m+z;
    z=m+n;
    printf("el resultado es: x=%d, y=%d y z=%d\n",x,y,z);
}

int main(void){
    int x,y,z;
    printf("ingresa valores para x,y y z:_\n");
        scanf("%d %d %d",&x,&y,&z);
    multiple2(x,y,z);
    return 0;
}
