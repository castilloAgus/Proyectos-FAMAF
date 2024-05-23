#include <stdlib.h>
#include <assert.h>
#include "stack.h"


stack stack_empty(){
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack stack_new = malloc(sizeof(struct _s_stack));
    stack_new->elem = e;
    stack_new->size = (s == NULL) ? 1 : s->size+1;
    stack_new->next = s;
    s = stack_new;
    stack_new = NULL;
    return s;
}


stack stack_pop(stack s){
    assert(s != NULL);  // Verifica que la pila no esté vacía
    s->size--;
    return s->next;
}


unsigned int stack_size(stack s){
    return (s == NULL) ? 0 : s->size;
}

stack_elem stack_top(stack s){
    assert(s!=NULL);
    return s->elem;
}

bool stack_is_empty(stack s){
    return (s==NULL);
}

stack_elem *stack_to_array(stack s){
    stack_elem *arr = NULL;
    unsigned int size = s->size;

    if (!stack_is_empty(s)){
        arr = (stack_elem *)calloc(s->size, sizeof(stack_elem));
        stack act_stack = s;

        for (unsigned int i = 0; i < size; --i){
            arr[i] = stack_top(act_stack);
            s = stack_pop(s);
        }
    }
    return arr;
}

stack stack_destroy(stack s){
    stack p = NULL;
    while (s != NULL) {
        p = s;
        s = s->next;
        p->next = NULL;
        free(p);
    }
    return s;
}
