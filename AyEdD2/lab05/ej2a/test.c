#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(void) {
    printf("primera prueba: si funciona la funcion stack_empty\n");
    stack stack_vacio;
    stack_vacio = stack_empty(); //creo un stack vacio
    bool res = stack_is_empty(stack_vacio);
    if (res != false) {
        printf("el stack esta vacio\n\n");
    }
    else {
        printf("el stack no esta vacio\n\n");
    }

    //ahora intento agregar elementos al stack_vacio
    
    printf("segunda prueba: agregar un elemento al stack_vacio\n");
    stack elem;
    elem = stack_push(stack_vacio, 4); //agrego el valor 4 a la pila
    stack_vacio = elem;
    
    //verifiquemos que el stack_con_elementos no este vacio, si pasa eso, enotnces el stack_push funciona correctamente
    bool res2 = stack_is_empty(stack_vacio);
    if (res2 != false) {
        printf("el stack_vacio esta vacio\n\n");
    }
    else {
        printf("el stack_vacio no esta vacio\n");
        unsigned int len = stack_size(stack_vacio);
        printf("el stack_vacio tiene %u elementos\n\n",len);
    }

    //probemos el stack_pop
    printf("tercera prubea: si funciona la funcion stack_pop con un elemento\n");
    stack stack_con_elemento = elem; //le asigno al stack_con_elemento un stack que tiene un elemento
    stack quitar_elem_stack = stack_pop(stack_con_elemento);

    // quitar_elem_stack = stack_pop(stack_con_elementos);
    if (stack_is_empty(quitar_elem_stack)) {
        printf("la funcion stack_pop funciona correctamente!!\n");
        printf("el stack con elementos ahora esta vacio\n\n");
    }
    else{
        printf("el stack con elementos sigue con elementos\n\n");
    }

    printf("cuarta prueba: La función stack_to_array() devuelve NULL para una pila vacía? ¿Devuelve los elementos en el orden correcto?\n");

    stack stack_vacio2 = stack_empty();
    stack_elem *s = stack_to_array(stack_vacio2);
    if (s == NULL) {
        printf("la funcion stack_to_array devuelve NULL para una pila vacia!\n\n");
    }
    else {
        printf("la funcion stack_to_array devuelve NULL para una pila vacia!\n\n");
    }
    
    stack stack_array, element; 
    stack_array = stack_empty(); 

    // Agrego tres elementos: 
    element = stack_push(stack_array, 4);
    element = stack_push(element, 5);
    stack_array = element;
    unsigned int lenght = stack_size(stack_array);
    stack_elem *orden_array;
    orden_array = stack_to_array(stack_array);

    // Imprimimos el array para ver el orden 
    for(unsigned i = 0; i<lenght; i++){
        printf("Elemento %u = %d \n", i, orden_array[i]);
    }

    return (EXIT_SUCCESS);
}