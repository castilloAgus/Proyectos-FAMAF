#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

//defino una tupla
struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t p=NULL;
    p=malloc(sizeof(int));

    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p){
    int res = p->fst;
    return res;
}


int pair_second(pair_t p){
    int res = p->snd;
    return res;
}

pair_t pair_swapped(pair_t p){
    pair_t new_pair = pair_new(p->snd, p->fst);
    return new_pair;
}


pair_t pair_destroy(pair_t p){
    free(p);
    // p=NULL;
    return NULL;
}