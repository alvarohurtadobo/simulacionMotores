#include "generador.h"
#include <stdlib.h>

Generador::Generador()
{
    ruido = 0;
    estado = 0;
}

void Generador::activarRuido()
{
    ruido = 1;
}

void Generador::desactivarRuido()
{
    ruido = 0;
}

void Generador::encender()
{
    estado = 1;
}

void Generador::apagar()
{
    estado = 0;
}

double Generador::getSalida()
{
    return salida;
}
