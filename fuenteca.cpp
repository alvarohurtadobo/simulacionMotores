#include "fuenteca.h"

FuenteCA::FuenteCA()
{
    frecuenciaHz = 50;
    amplitud = 220;
    fase = 0;
    tipo = 3; // Indica que es trifásico
}

FuenteCA::FuenteCA(double amplitude, double frequency, double phase)
{
    frecuenciaHz = frequency;
    amplitud = amplitude;
    fase = phase;
    tipo = 3; // Indica que es trifásico
}

void FuenteCA::actualizar(double sampleTime, int counter)
{
    if(!estado)
    {
        salida = 0;
        return;
    }
    if(ruido)
        salida = amplitud*sin(2*3.141592658*frecuenciaHz*sampleTime*counter+fase)+0.01*(rand()%101-50);
    else
        salida = amplitud;

}

void FuenteCA::setAmplitud(double amplitude)
{
    amplitud = amplitude;
}

double FuenteCA::getAmplitud()
{
    return amplitud;
}

void FuenteCA::setFrecuenciaHz(double frequency)
{
    frecuenciaHz = frequency;
}

double FuenteCA::getFrecuenciaHz()
{
    return frecuenciaHz;
}

void FuenteCA::setFase(double phase)
{
    fase = phase;
}

double FuenteCA::getFase()
{
    return fase;
}
