#include <stdlib.h>
#include <assert.h>
#include "stack.h"


typedef struct _s_stack{ 
        stack_elem elem;
        struct _s_stack *next;
    } stack_t;


stack stack_empty(){
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack stack_new = malloc(sizeof(struct _s_stack));
    stack_new->elem = e;
    stack_new->next = s;
    s = stack_new;
    return s;
}


stack stack_pop(stack s){
    assert(s != NULL);  // Verifica que la pila no esté vacía
    stack temp = s;
    s = s->next;
    free(temp);
    return s;
}


unsigned int stack_size(stack s){
    unsigned int length = 0;
    if (stack_is_empty(s)) {
        return 0;
    }
    
    else {
        while (s != NULL) {
            s = s->next;
            length++;
        }
    }
    return length;
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
    if (!stack_is_empty(s)){
        arr = calloc(stack_size(s), sizeof(stack_elem));
        stack act_stack = s;
        unsigned int len = stack_size(s);
        for (int i = len - 1; i >= 0; --i){
            arr[i] = stack_top(act_stack);
            act_stack = act_stack->next;
        }
    }
    return arr;
}

stack stack_destroy(stack s){
    free(s);
    return NULL;
}
