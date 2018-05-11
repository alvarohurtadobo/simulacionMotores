#include "carga.h"

Carga::Carga()
{
}

double Carga::getDeslizamiento(double sampleTime, int counter)
{
    // Aquí se colocarán las características de arranque del motor. Por defecto vacio, tiempo de arranque 5 segundos
/*
    if(sampleTime*counter <= 5)
        return 1 - 0.19*counter*sampleTime;
    else
        return 0.05;
*/
    return 1/(5*counter*sampleTime+1);
}
