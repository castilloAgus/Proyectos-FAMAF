#include <stdio.h>

int main(void)
{
    int x,y,z,b,w;
    printf("ingresa un x\n");
     scanf("%d", &x);
    printf("ingresa otro numero para y\n");
     scanf("%d", &y);
    printf("ingresa otro numero para z\n");
     scanf("%d", &z);
    printf("ingresa otro numero para b\n");
     scanf("%d", &b);
    printf("ingresa otro numero para w\n");
     scanf("%d", &w);

     printf("1: x=%d; entonces ((x mod 4) == 0)=%d\n",x,(x % 4) == 0);
     printf("1: x=%d y=%d z=%d; entonces x+y==0 && y-x==(-1)*z=%d\n", x,y,z,x+y==0 && y-x==(-1)*z);
     printf("0: b=%d w=%d; entonces (!b && w)=%d\n",b,w,(!b && w));
     return 0; 
}
// x->-8, y->8, z->-16, b->1, w->2

