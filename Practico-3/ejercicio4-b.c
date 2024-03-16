//este programa va cambiando los valores de m dependiendo de las sentencias

#include <stdio.h>

int main(void){
    int x,y,z,m;
    printf("ingrese un valor para x,y,z,m: \n");
    scanf("%d %d %d %d",&x,&y,&z,&m);
     
     if (x<y){
        m=x;
         printf("el nuevo valor de m es: %d\n",m);
     }
     if (x>=y){
        m=y;
         printf("el valor de m sera: %d\n",m);

     }    
         printf("el valor de m actual de m es: %d\n",m); 
     
    printf ("el estado actual es: %d %d %d %d\n",x,y,z,m);
      
      if (m<z){
        printf("queda el mismo estado: %d %d %d %d\n",x,y,z,m);
      }
      if (m>=z){
        m=z;
        printf ("el nuevo valor para m es: %d\n",m);

      }

      printf("el estado final es: %d %d %d %d\n",x,y,z,m);
    return 0;    
}
/* ingrese un valor para x,y,z,m:
5 4 8 0
el valor de m sera: 4
el valor de m actual de m es: 4
el estado actual es: 5 4 8 4
queda el mismo estado: 5 4 8 4
el estado final es: 5 4 8 4
 */
