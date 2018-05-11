#include "variadorfrecuencia.h"

VariadorFrecuencia::VariadorFrecuencia()
{
}


VariadorFrecuencia::VariadorFrecuencia(double amplitude, double frequency, double phase)
{
    frecuenciaHz = frequency;
    amplitud = amplitude;
    fase = phase;
    tipo = 3; // Indica que es trifásico
}

void VariadorFrecuencia::actualizar(double sampleTime, int counter)
{
    if(!estado)
    {
        Generador::salida = 0;
        return;
    }
    if(ruido)
        Generador::salida = amplitud*sin(2*3.141592658*frecuenciaHz*sampleTime*counter+fase)+0.01*(rand()%101-50);
    else
        Generador::salida = amplitud;

}

void VariadorFrecuencia::setAmplitud(double amplitude)
{
    amplitud = amplitude;
}

double VariadorFrecuencia::getAmplitud()
{
    return amplitud;
}

void VariadorFrecuencia::setFrecuenciaHz(double frequency)
{
    frecuenciaHz = frequency;
}

double VariadorFrecuencia::getFrecuenciaHz()
{
    return frecuenciaHz;
}

void VariadorFrecuencia::setFase(double phase)
{
    fase = phase;
}

double VariadorFrecuencia::getFase()
{
    return fase;
}

