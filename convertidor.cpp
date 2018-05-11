#include "convertidor.h"

Convertidor::Convertidor()
{
    entrada = 0;
    salida = 0;
    alimentacion = 0;
}

void Convertidor::setEntrada(double income)
{
    entrada = income;
}

double Convertidor::getEntrada()
{
    return entrada;
}

void Convertidor::setSalida(double outcome)
{
    salida = outcome;
}

double Convertidor::getSalida()
{
    return salida;
}

void Convertidor::setAmplitud(double amplitude)
{
    amplitud = amplitude;
}

double Convertidor::getAmplitud()
{
    return amplitud;
}
void Convertidor::setFrecuencia(double frequency)
{
    frecuencia = frequency;
}

double Convertidor::getFrecuencia()
{
    return frecuencia;
}
