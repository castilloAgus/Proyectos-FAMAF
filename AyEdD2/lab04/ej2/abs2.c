#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x>=0) {
        *y = x;
    }
    else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;

    absolute(a, &res);
    printf("res=%d\n", res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

//●¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
/* es de tipo in/out */
//● ¿Qué tipo de parámetros tiene disponibles C para sus funciones?
/* 
para los parametros "in": son aquellos que se pasan a una funcion para ser utilizados, pero no modificados dentro de la funcion
para los parametros "out": a diferencia del parametro "in", este se utiliza para devolver valores que se calculan en la funcion
para los parametros "in/out": se usan tanto ser utilizados como para devolver valores calculados */