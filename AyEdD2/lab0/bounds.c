#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#define N 4

typedef struct {
bool is_upperbound;
bool is_lowerbound;
bool exists;
unsigned int where;
} bound_data;

bound_data check_bound(int value, int arr[], unsigned int length){
    unsigned int i=0, pos=0;
    bound_data result;
    bool mayor=false, menor=false, exist=false;
    while (i<length){
        if (value>arr[i]){
            mayor=true;
            menor=false;
        }
        else if (value<arr[i]){
            menor=true;
            mayor=false;
        }
        else if (value==arr[i]){
            exist=true;
            pos=i;
        }
        i=i+1;
    }
    result.is_upperbound=mayor;
    result.is_lowerbound=menor;
    result.exists=exist;
    result.where=pos;
    return result;
}

int main (void){
    int arr[N]={0,-1,9,4};
    unsigned int i=0;
    int value=9;
    while (i<N){
        printf("ingrese un valor para la pos %d del arreglo: \n",i);
        scanf("%d",&arr[i]);
        i=i+1;
    }
    bound_data result;
    result=check_bound(value, arr, N);
    printf("es mayor a todos? %d\n",result.is_upperbound);
    printf("es menor que todos? %d\n",result.is_lowerbound);
    printf("existe? %u\n",result.exists);
    printf("en que pos esta? %u\n",result.where);
    return EXIT_SUCCESS;
}
