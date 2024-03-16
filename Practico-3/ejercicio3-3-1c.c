#include <stdio.h>

int main(){
    int x,y;
    printf("ingrese un numero para x:  \n");
     scanf("%d", &x);
    printf("ingrese un numero para y: \n");
     scanf("%d", &y);
      y=y+y;  
    printf("ahora el valor de y es:%d\n",y);
      x=x+y;
    printf("y ahora el valor de x es:%d\n",x);  
    return 0;
}
/* ingrese un numero para x:
3
ingrese un numero para y:
4
ahora el valor de y es:8
y ahora el valor de x es:11

ingrese un numero para x:
5
ingrese un numero para y:
6
ahora el valor de y es:12
y ahora el valor de x es:17

ingrese un numero para x:
2
ingrese un numero para y:
3
ahora el valor de y es:6
y ahora el valor de x es:8
 */
