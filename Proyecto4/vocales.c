#include <stdio.h>
#include <stdbool.h>

 char pedir_char(void){
    char l;
    printf("ingresa un char para l: \n");
        scanf("%c",&l);
    return l;
}

bool es_vocal(char letra){

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ){
        return true;
    }
    else {
        return false;
    }
}

int main(void){
    int res;
    char l;
   l= pedir_char();
    res = es_vocal(l);
    printf("si es 1=tre y si es 0=false: %d\n",res);        
    return 0;
}
