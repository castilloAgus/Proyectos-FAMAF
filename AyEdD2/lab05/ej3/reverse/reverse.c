/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "../stack.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
            "Sort an array given in a file in disk.\n"
            "\n"
            "The input file must have the following format:\n"
            " * The first line must contain only a positive integer,"
            " which is the length of the array.\n"
            " * The second line must contain the members of the array"
            " separated by one or more spaces. Each member must be an integer."
            "\n\n"
            "In other words, the file format is:\n"
            "<amount of array elements>\n"
            "<array elem 1> <array elem 2> ... <array elem N>\n\n",
            program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    if (length == 0) {
      printf("el array original esta vacio\n");
    }
    else{
      printf("Original: ");
      array_dump(array, length);
    }
    
    

    //primero paso los valores del array a un nuevo array pero de tal manera que me deje manipularlo con funciones de stack
    int *new_array= NULL;
    new_array = (int *)malloc(length*sizeof(int));

    stack pila_vacia = stack_empty();
    if (new_array == NULL) {
      printf("el arreglo no tiene elementos\n");
      pila_vacia = stack_destroy(pila_vacia);
      return (EXIT_SUCCESS);
    }
    

    for (size_t i = 0; i < length; i++) {
      pila_vacia = stack_push(pila_vacia, array[i]);
    }
    
    // stack pila_invertida = stack_empty();

    for (size_t j = 0; j < length; j++) {
      if (!stack_is_empty(pila_vacia)) {
        new_array[j] = stack_top(pila_vacia);
        pila_vacia = stack_pop(pila_vacia);
      }
      
    }

    if (new_array == NULL) {
      return (EXIT_SUCCESS);
    }
    
    if (length == 0) {
      printf("el array reversed esta vacio\n");
    }
    else {
      printf("Reversed: ");
      array_dump(new_array, length);
    }
    
    free(new_array);
    pila_vacia = stack_destroy(pila_vacia);
    return (EXIT_SUCCESS);
}
