/*
    @file sort.c
    @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    if(x.rank>y.rank) {
        return false;
    }
    return true;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

void quick_sort_rec (player_t a[], unsigned int lft, unsigned rgt){
    unsigned int ppiv;
    if (lft<rgt) {
        ppiv=partition(a, lft, rgt);
        if(ppiv!=0u){
            quick_sort_rec(a, lft, ppiv-1);
        }
        quick_sort_rec(a, ppiv+1, rgt);
    }
}


unsigned int partition(player_t a[], unsigned int lft, unsigned int rgt) {
    unsigned int i,j,pivot;
    pivot=lft;
    i=lft+1;
    j=rgt;
    while (i<=j) {
        if (goes_before(a[i],a[pivot])) {
            i=i+1;
        }
        else if (goes_before(a[pivot],a[j])) {
            j=j-1;
        }
        else if (goes_before(a[pivot],a[i]) && goes_before(a[j],a[pivot])) {
            swap(a,i,j);
        }
    }
    swap(a,pivot,j);
    pivot=j;
    return pivot;
}

void swap (player_t a[], unsigned int lft, unsigned int rgt){
    player_t aux;
    aux=a[lft];
    a[lft]=a[rgt];
    a[rgt]=aux;

}
