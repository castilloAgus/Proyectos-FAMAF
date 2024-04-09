#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int length_array;
    for(unsigned int i=0; i<FIXSTRING_MAX; i++){
        if(s[i]!='\0'){
            length_array=i+1;
        }
    }
    return  length_array;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    for(unsigned int i=0; i<FIXSTRING_MAX; i++){
        if(s1[i]!=s2[i]){
            return false;
        }
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    for(unsigned int i=0; i<FIXSTRING_MAX; i++){
        if(s1[i]>s2[i]){
            return false;
        }
    }
    return true;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}


