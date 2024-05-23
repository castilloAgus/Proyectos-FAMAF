#ifndef _STRFUNCS_
#define _STRFUNCS_

#include <stdio.h>
#include <stdbool.h>

#define FIXSTRING_MAX 100

size_t string_length(const char *str);
/*
calcula la longitud de la cadema apuntada por str
*/
char *string_filter(const char *str, char c);
/*
devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str
que son distintos del caracter c
*/

bool string_is_symmetric(const char *str);
/*
indica si la cadena apuntada por str es simétrica en cuanto que el primer caracter coincide con el
último, el segundo con el penúltimo, etc; como por ejemplo las cadenas "aba", "abcba", "a", ""
*/

#endif