#include <stdio.h>
#include <stdio.h>
#include <limits.h>
#include "weather_utils.h"
#include "array_helpers.h"

int min_temperature (WeatherTable a){
    int min_temp= INT_MAX;
    int aux;
    for (int i_years = 0; i_years < YEARS; i_years++) { //recorre todos los anios

        for (int j_months = 0; j_months < MONTHS; j_months++) { //recorre todos los meses del anio

            for (int k_days = 0; k_days < DAYS; k_days++) { //recorre todos los dias del anio
                aux=a[i_years][j_months][k_days]._min_temp; //la variable aux toma el valor de la minima temperatura del primer anio, mes y dia 
                if ( aux < min_temp) { 
                    min_temp=aux;
                }
                
            }
            
        }
        
    }
    return min_temp;
}

void maximum_temperature (WeatherTable a, int output[YEARS]) {

    for (int year = 0; year < YEARS; year++) {
        output[year]=INT_MIN;
        for (int month = 0; month < MONTHS; month++) {

            for (int day = 0; day < DAYS; day++) {
                if (output[year]<a[year][month][day]._max_temp) {
                    output[year]=a[year][month][day]._max_temp;
                }

            }
            
        }

    }
}

void maximum_rainfall (WeatherTable a, int output[YEARS]){
    

    for ( int year = 0; year < YEARS; year++) {
        int max_month=0;
        int max_rainfall=INT_MIN;

        for ( int month = 0; month < MONTHS; month++) {
            int sum_rainfall=0;
            for ( int day = 0; day < DAYS; day++) {
                sum_rainfall=a[year][month][day]._rainfall+sum_rainfall; //sumamos todas las rainfall del mes
            }
            if (sum_rainfall>max_rainfall ) {
                max_rainfall=sum_rainfall;
                max_month=month+1;
            }
        }
        output[year]= max_month;
    }
    
}