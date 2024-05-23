#include <stdbool.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    size_t length=0;
    size_t i=0;
    while (str[i] !='\0') {
        length++;
        i++;
    }
    return length;
}


char *string_filter(const char *str, char c){
    char *res = (char *)malloc (string_length(str));
    
    if (str == NULL) {
        return NULL;
    }
    size_t i=0;
    size_t j=0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            res[j] = str[i];
            j++;
        }
        i++;
    }
    return res;
}


bool string_is_symmetric(const char *str){
    if (str == NULL) {
        return true;
    }

    size_t length = string_length(str) - 1;
    size_t j = length;
    size_t i=0;
    while (i<j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}