#include<stdio.h>
#include<limits.h>
#include<float.h>

typedef struct _persona {
char nombre [50]; //lo pongo con 50 por que me tiraba un error si no lo hacia.
int edad;
float altura;
float peso;
} persona_t;

float peso_promedio(unsigned int longitud, persona_t arr[]){
    unsigned int i=0;
    float sum=0;
    float res;
    while(i<longitud){
        if (arr[i].altura){
            sum=sum+arr[i].peso;
        }
        i=i+1;
    }
    res = sum/longitud;
    return res;
}
persona_t persona_de_mayor_edad(unsigned int longitud, persona_t arr[]){
    persona_t result;
    unsigned int i=0;
    int max_edad=INT_MIN;
    while (i<longitud){
        if (arr[i].edad>max_edad){
            max_edad=arr[i].edad;
            result=arr[i];
        }
        i=i+1;
    }
    return result;
}
persona_t persona_de_menor_altura(unsigned int longitud, persona_t arr[]){
    persona_t result;
    unsigned int i=0;
    float min_altura= FLT_MIN;
    while (i<longitud){
        if (arr[i].edad>min_altura){
            min_altura=arr[i].altura;
            result=arr[i];
        }
        i=i+1;
    }
    return result;
}

int main(void) {
persona_t p1 = {.nombre="Paola", .edad=21, .altura=1.85, .peso=75};
persona_t p2 = {.nombre="Luis", .edad=54, .altura=1.75, .peso=69};
persona_t p3 = {.nombre="Julio", .edad=40, .altura=1.70, .peso=80};
unsigned int longitud = 3;
persona_t arr[] = {p1, p2, p3};

printf("El peso promedio es %f\n", peso_promedio(longitud, arr));

persona_t p = persona_de_mayor_edad(longitud, arr);

printf("El nombre de la persona con mayor edad es %s\n", p.nombre);

p = persona_de_menor_altura(longitud, arr);

printf("El nombre de la persona con menor altura es %s\n", p.nombre);
return 0;
}
