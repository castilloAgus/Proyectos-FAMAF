
#include <stdio.h>
#include <stdbool.h>

int main(void){
    int x,i;
    bool res;
    printf("ingrese valores para x,i, res: \n");
    scanf("%d %d",&x,&i);

    i=2;
    res= true; 

    while (i<x && res){
        res=res && (x%i!=0);
        i=i+1;

        printf("el estado sera: %d %d %d\n",x,i,res);
    }

    //por completitud agrego el estado final.
    printf("el estado final es: %d %d %d",x,i,res);

    return 0;
      
}

/*
ingrese valores para x,i, res:
5 0 0
el estado sera: 5 3 1
el estado sera: 5 4 1
el estado sera: 5 5 1
el estado final es: 5 5 1

 [|σ01: (x→5,y→3,i→1) , σ11: (x→5 ,y→4 ,i→1 ) ,
luego de iter. 1,       luego de iter. 2

σ21: (x→ 5,y→5 ,i→1 ) 
luego de iter. 3,   
 */
