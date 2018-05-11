#include "fuentedc.h"

FuenteDC::FuenteDC()
{
}

FuenteDC::FuenteDC(double amplitude)
{
    amplitud = amplitude;
}

void FuenteDC::actualizar(double sampleTime, int counter)
{
    if(!estado)
    {
        salida = 0;
        return;
    }
    if(ruido)
        salida = amplitud+0.01*(rand()%101-50);
    else
        salida = amplitud;

}

void FuenteDC::setAmplitud(double amplitude)
{
    amplitud = amplitude;
}

double FuenteDC::getAmplitud()
{
    return amplitud;
}
