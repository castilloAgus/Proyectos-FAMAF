#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820

//PROBLEMA:
/*
lo que tenemos en este codigo es que devuelve un puntero, en el cual esta ocupando memoria  y no la esta liberando, tambien en este caso output esta apuntando a basura, ya que que se pierde los valores de la variable clon en el cual fue inicializada
*/

char *string_clone(const char *str, size_t length) {
    char clon[MAX_LENGTH];
    char *output=clon;
    for (size_t i=0; i<length;i++) {
        output[i] = str[i];
    }
    output[length] = '\0';

    return output;
}

//hago de nuveo la funcion para que no produzca memory leaks
/*char *string_clone(const char *str, size_t length){
    char *clon = (char *)malloc(length + 1); //pongo length+1 para el valor que cuente el valor nulo ('\0')

    for (size_t i = 0; i < length; i++) {
        clon[i] = str[i];
    }
    clon [length] = '\0';
    return clon;

}*/


int main(void) {
    
    char *original=""
            "______ time ago in a galaxy far, far away...\n\n\n"
         ANSI_BRGOLD
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                           Episode II \n\n"
         "                      ATTACK OF THE CLONES\n\n"
         "                There is  unrest in the Galactic\n"
         "                Senate. Several  thousand  solar\n"
         "                systems  have   declared   their\n"
         "                intentions to leave the Republic.\n\n"
         "                This      separatist     movement,\n"
         "                under  the   leadership   of  the\n"
         "                mysterious   Count   Dooku,   has\n"
         "                made it difficult for the limited\n"
         "                number   of   Jedi   Knights   to\n"
         "                maintain   peace   and  order  in\n"
         "                the galaxy.\n\n"
         "                Senator   Amidala,   the   former\n"
         "                Queen   of  Naboo,  is  returning\n"
         "                to  the  Galactic  Senate to vote\n"
         "                on the critical issue of creating\n"
         "                an    ARMY    OF   THE   REPUBLIC\n"
         "                to    assist    the   overwhelmed\n"
         "                Jedi....\n" ANSI_WHITE;
    char *copy=NULL;

    copy = string_clone(original, strlen(original));
    //copy string_clone(original, sizeof(original)/sizeof(*original))

    printf("Original:\n" ANSI_CYAN " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
            " %s\n", copy);

    return EXIT_SUCCESS;
}

/*
si cambiamos la variable "original[]" por "*original" entonces no va a funcionar si se mantiene copy string_clone(original, sizeof(original)/sizeof(*original)), ya que no me va a calcular el largo de la cadena por que ahora original esta declarada como puntero
para que me calcule el largo de la cadena uso la funcion strlen(original)
*/
