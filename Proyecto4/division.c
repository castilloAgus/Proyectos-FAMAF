#include <stdio.h>


typedef struct {
int cociente;
int resto
} div_t;

div_t division(int x, int y){

 div_t res;
    res.cociente = x/y;
    res.resto = x%y;
    return res;
       

}

int main(void){
    int x,y;
    div_t result;
    printf("ingresa valores para x e y: \n");
        scanf("%d %d",&x,&y);

    if (y>0 || y<0){
        result = division(x,y);
        printf("la division da %d\n",result.cociente);
        printf("el resto es %d\n",result.resto);
    }    
    else{
        printf("error\n");
    }
    return 0;
}
