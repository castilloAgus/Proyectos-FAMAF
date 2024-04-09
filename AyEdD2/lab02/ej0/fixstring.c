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
    // printf("el length del arreglo es %u\n",length_array);
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

