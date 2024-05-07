#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include <assert.h>

typedef struct node_of_T *list;

typedef int list_elem;

list empty(void);
/*
create an empty list
*/

list addl(list_elem e, list l);
/*
add the element e to the left of the list
*/

bool is_empty(list l);
/*
return true if the list l si empty
*/

list_elem head(list l);
/*
return the first element of the list l
PRE: not is_empy(l)
*/

list tail(list l);
/*
delete the first element of the list l
PRE: not is_empty(l)
*/

list addr(list l, list_elem e);
/*
add the element e to the end of the list l
*/

int length(list l);
/*
return the number of elements in the list l
*/

list concat(list l1, list l2);
/*
add all elements of l2 to the end of list l in the same order
*/

list_elem index(list l, list_elem n);
/*
return the n element of the list
PRE: length(l)>n
*/

list take(list l, list_elem n);
/*
keep only the first n elements in l, removing the rest
*/

list drop(list l, list_elem n);
/*
delete the first n elements of l
*/

list copy_list(list l);
/*
copy all elements from l into a new list "l2"
*/

list destroy(list l);
/*
frees memory for l
*/

#endif