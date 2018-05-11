#ifndef CONVERTIDORACDCCOMPLETO_H
#define CONVERTIDORACDCCOMPLETO_H

#include <convertidor.h>
#include <cmath>

class ConvertidorACDCCompleto : public Convertidor
{
public:
    ConvertidorACDCCompleto();

    void actualizar(double sampleTime, int counter);

    void setAnguloDisparo(double angle);
    double getAnguloDisparo();

private:
    double anguloDisparo;
};

#endif // CONVERTIDORACDCCOMPLETO_H
