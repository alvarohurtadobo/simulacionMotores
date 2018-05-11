#include "sistemacontrol.h"

SistemaControl::SistemaControl()
{
    miMotorInduccion = 0;
    //alimentacion = 0;
}

MotorInduccion * SistemaControl::getMotorInduccion()
{
    return miMotorInduccion;
}

void SistemaControl::setMotorInduccion()
{
    miMotorInduccion = new MotorInduccion;
}
