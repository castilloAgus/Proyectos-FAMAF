#ifndef _WEATHER_UTILS_
    #define _WEATHER_UTILS_
    #include<stdio.h>
    #include "array_helpers.h"

    int min_temperature (WeatherTable a);

    void maximum_temperature (WeatherTable a, int output[YEARS]);

    void maximum_rainfall (WeatherTable a, int output[YEARS]);
#endif