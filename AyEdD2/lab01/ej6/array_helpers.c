#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

void array_dump(int a[], unsigned int length) {
		printf("[");
    for (unsigned int i=0; i<length; i++) {
        printf("%d",a[i]);
		if(i<length-1){
			printf(",");
		}
    }
    printf("]\n");
}

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
	   FILE*archivo;
	   archivo = fopen(filepath, "r");
	   unsigned int arreglo; 
	   fscanf(archivo,"%u", &arreglo);
	   if (max_size <= arreglo) {
	   	return 0;
	   }
	   for (unsigned int i=0; i<arreglo; i++) {
	   	fscanf(archivo,"%d", &array[i]);
	   }
	   fclose (archivo);
	   return arreglo;
	
}

void invertir_array(int a[], unsigned int length){
	for(unsigned int i=0; i<length/2; i++){
			array_swap(a,i,length -i-1);
	}
}

void array_swap(int a[], unsigned int i, unsigned int j){
	unsigned int original;
	original=a[i];
	a[i]=a[j];
	a[j]=original;
}

bool array_is_sorted(int a[], unsigned int length){
	for(unsigned int i=0; i<length-1; i++){
		if(a[i]>a[i+1]){
			return 0;
		}
	}
	return 1;
}