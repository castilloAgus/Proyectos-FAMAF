#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack s = NULL;
    s = malloc(sizeof(struct _s_stack));
    s->elems = NULL;
    s->size = 0u;
    s->capacity = 0u;
    return s;
}

stack stack_push(stack s, stack_elem e){
    if (s->elems == NULL) {
        s->capacity = 1u;
        s->elems = calloc(s->capacity, sizeof(s->elems));
    }
    else {
        s->capacity *= 2;
        s->elems = realloc(s->elems, s->capacity *sizeof(s->elems));
    }

    s->elems[s->size] = e;
    s->size++;
    return s;
}

stack stack_pop(stack s){
    assert(s->size != 0u);
    s->size --;
    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(s->elems != NULL);
    return (s->elems[s->size-1]);
}

bool stack_is_empty(stack s){
    return (s->size == 0u);
}

stack_elem *stack_to_array(stack s){
    assert (s->size != 0);
    stack_elem *arr = NULL;
    unsigned int size = s->size;

    if (!stack_is_empty(s)){
        arr = calloc(s->size, sizeof(stack_elem));
        stack act_stack = s;

        for (unsigned int i = 0; i < size; --i){
            arr[i] = stack_top(act_stack);
            s = stack_pop(s);
        }
    }
    return arr;
}

stack stack_destroy(stack s){
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return NULL;
}