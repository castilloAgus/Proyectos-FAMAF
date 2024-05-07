#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

typedef struct node_of_T  {
    list_elem elem;
    struct node_of_T *next;
    
} node;


list empty(void) {
    list l=NULL;
    return l;
}

list addl(list_elem e, list l) {
    list p;
    p = malloc(sizeof(struct node_of_T));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

bool is_empty(list l) {
    return (l==NULL);
}

list_elem head(list l) {
    list_elem e = l->elem;
    return e;
}

list tail(list l){ 
    list p = l;
    l = l->next;
    free(p);
    return l;
}

list addr(list l, list_elem e){
    list p,q;
    q = malloc(sizeof(int));
    q->elem = e;
    q->next = NULL;
    if (!is_empty(l)) {
        p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }
    else {
        l = q;
    }
    return l;
}

int length(list l){
    int num = 0u;
    list p = l;
    while (p != NULL) {
        p = p->next;
        num = num + 1;
    }
    return num;
}

list concat(list l1, list l2){
    list q;
    q = NULL;
    if (l1 == NULL && l2 == NULL){
        q = l1;
    }
    else { 
        q = l1;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = l2;
    }
    return q;
}

list_elem index(list l, list_elem n){
    assert (length(l)>n);
    list p=NULL;
    p = l;
    if (n>1) {
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
    }

    return p->elem;
}

list take(list l, list_elem n){
    if (l == NULL || n<=0) {
        while (l != NULL) {
            list q = l;
            l = l->next;
            free(q);
        }
        
    }
    else {
        list p = NULL;
        p = l;
        list temp;
        for (int i = 0; i < n; i++) {
            if (p->next != NULL) {
                p = p->next;
            }
        }
        while (p != NULL && p->next != NULL) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    return l;
}

list drop(list l, list_elem n){
    list p, temp;
    p = l;
    for (int i = 0; i < n; i++) {
        if (p != NULL) {
            temp = p;
            p = p->next;
            free(temp);
        }
    }
    l = p;
    return l;
}

list copy_list(list l){
    list copy = empty();
    list p = l;
    while (p != NULL) {
        copy = addr(copy, p->elem);
        p = p->next;
    }
    return copy;
}

list destroy(list l) {
    list p=NULL;
    while (l != NULL) {
        p = l;
        l = l->next;
        free(p);
    }
    return l;
}
