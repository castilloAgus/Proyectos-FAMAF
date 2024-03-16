#include <stdio.h>
int main(void){
    int x,y,z;

    printf("ingresa un numero para x\n"); 
    scanf("%d", &x);
    printf("ingresa otro numero para y\n");
    scanf("%d", &y);
    printf("ingresa otro numero para z\n");
    scanf("%d", &z);
    printf("se ingreso x=%d y=%d; entonces x+y+1=%d\n",x,y,(x+y+1));
    printf("se ingreso x=%d y=%d z=%d; entonces (z*z)+(y*45)-(15*x)=%d\n",x,y,z,(z*z)+(y*45)-(15*x));
    printf("se ingreso x=%d y=%d; entonces y/2*x=%d\n",x,y,(y/2*x));
    printf("se ingreso x=%d y=%d z=%d; entonces y<x*z=%d\n\n",x,y,z,(y<x*z));

    printf("se ingreso x=%d y=%d; entonces y-2==(x*3+1)%5 = %d\n",x,y,y-2==(x*3+1) % 5);
    return 0;
}


/* Expresion             |(x7→7, y7→3, z7→5)  | (x7→1, y7→10, z7→8)|
x + y + 1                |     11             |     12           |   
z * z + y * 45 - 15 * x  |     55             |     499          |   
y - 2 == (x * 3 + 1) % 5 |      7             |       5          |   
y / 2 * x                |      1             |       0          |   
y < x * z                |      0             |       0          |   

0=flase, 1=true
 */
