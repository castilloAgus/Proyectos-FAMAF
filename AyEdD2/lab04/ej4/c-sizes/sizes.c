#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
        printf("NOMBRE: %s\n"
        "EDAD  : %d años\n"
        "ALTURA: %d cm\n\n",
        d.name, d.age, d.height);
}

int main(void) {

        data_t messi = {"Leo Messi", 36, 169};
        print_data(messi);

        printf("name-size  : %lu bytes\n"
        "age-size   : %lu bytes\n"
        "height-size: %lu bytes\n"
        "data_t-size: %lu bytes\n",sizeof(name_t), sizeof(int), sizeof(int), sizeof(data_t));

        printf("name-size   : la direccion de memoria %p \n"
        		"age-size   : la direccion de memoria %p \n"
        		"height-size: la direccion de memoria %p \n"
        		"data_t-size: la direccion de memoria %p \n", &messi.name, &messi.age, &messi.height, &messi);
        return EXIT_SUCCESS;
}

