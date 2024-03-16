#include <stdio.h>

int main(void){
    int x,y,i;
    i=0;

    printf("ingrese valores para x,y,i: \n");
    scanf("%d %d %d",&x,&y,&i);

    while(x>=y){
        x=x-y;
        i=i+1;
        printf("el estado actual es: %d %d %d\n",x,y,i);

    }
    //por completitud agrego el estado final del programa
    printf("el estado final es: %d %d %d\n",x,y,i);

    return 0;
}
/* ejemplo:
ingrese valores para x,y,i:
13 3 0
el estado actual es: 10 3 1
el estado actual es: 7 3 2
el estado actual es: 4 3 3
el estado actual es: 1 3 4
el estado final es: 1 3 4
 */


/* 
[|σ01: (x→10,y→3,i→1) , σ11: (x→7 ,y→3 ,i→2 ) ,
luego de iter. 1,       luego de iter. 2

σ21: (x→ 4,y→3 ,i→3 ) , σ31: (x→1 ,y→3 ,i→4 ) |]
luego de iter. 3,         luego de iter. 4

 */
