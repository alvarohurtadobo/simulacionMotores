#include "convertidoracdccompleto.h"

ConvertidorACDCCompleto::ConvertidorACDCCompleto()
{
    anguloDisparo = 0;
}

void ConvertidorACDCCompleto::actualizar(double sampleTime, int counter)
{
    double memoria = salida;
    double nuevaSalida = abs(amplitud*sin(2*3.141592658*frecuencia*sampleTime*counter));
    if((nuevaSalida>memoria)&&(nuevaSalida<amplitud*sin(anguloDisparo*3.14159265/180)))
        salida = -abs(amplitud*sin(2*3.141592658*frecuencia*sampleTime*counter));
    else
        salida = abs(amplitud*sin(2*3.141592658*frecuencia*sampleTime*counter));
}

void ConvertidorACDCCompleto::setAnguloDisparo(double angle)
{
    anguloDisparo = angle;
}

double ConvertidorACDCCompleto::getAnguloDisparo()
{
    return anguloDisparo;
}
