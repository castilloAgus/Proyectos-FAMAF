#include <stdio.h>

int main()
{
    int x,y;
    printf("ingresa un valor para x: \n");
     scanf("%d", &x);
    printf("ingrese un valor para y: \n");
     scanf("%d", &y); 
    x=x+y;
    printf("ahora el valor de x es: x=%d\n",x);
     y=y+y;
    printf("y el valor de y es: y=%d\n",y);
    return 0;

}

/* 
ingresa un valor para x:
3
ingrese un valor para y:
5
ahora el valor de x es: x=8
y el valor de y es: y=10

ingresa un valor para x:
6
ingrese un valor para y:
8
ahora el valor de x es: x=14
y el valor de y es: y=16

ingresa un valor para x:
1
ingrese un valor para y:
2
ahora el valor de x es: x=3
y el valor de y es: y=4 */
