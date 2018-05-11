#ifndef SISTEMACONTROL_H
#define SISTEMACONTROL_H

#include <motorinduccion.h>
#include <dialogoalimentacionsincrono.h>

class SistemaControl
{
public:
    SistemaControl();

    MotorInduccion * getMotorInduccion();
    void setMotorInduccion();

private:

// EL MOTOR
    MotorInduccion * miMotorInduccion;

// Gráficas de estudio


};

#endif // SISTEMACONTROL_H
