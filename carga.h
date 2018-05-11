#ifndef CARGA_H
#define CARGA_H

class Carga
{
public:
    Carga();

    double getDeslizamiento(double sampleTime, int counter);

private:
    double Torque;
    double velocidad;

    double deslizamiento;
};

#endif // CARGA_H
