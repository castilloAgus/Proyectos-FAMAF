#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t p;
    p.values[0]=x;
    p.values[1]=y;
    return p;
}

int pair_first(pair_t p){
    int res=p.values[0];
    return res;
}

int pair_second(pair_t p){
    int res=p.values[1];
    return res;
}

pair_t pair_swapped(pair_t p){
    int aux;
    aux = p.values[0];
    p.values[0] = p.values[1];
    p.values[1] = aux;
    return p;
}

pair_t pair_destroy(pair_t p){
    return p;
}