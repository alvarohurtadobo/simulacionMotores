#ifndef CONVERTIDOR_H
#define CONVERTIDOR_H

#include <generador.h>

class Convertidor: public Generador
{
public:
    Convertidor();

    virtual void actualizar(double sampleTime, int counter) = 0;

// SETTER's and GETTER's
    void setEntrada(double income);
    double getEntrada();
    void setSalida(double outcome);
    double getSalida();
    void setAmplitud(double amplitude);
    double getAmplitud();
    void setFrecuencia(double frequency);
    double getFrecuencia();

protected:
    double amplitud;
    double frecuencia;

    Generador * alimentacion;
    double entrada;
    // double salida;                       Este elemento ya esta definido en generador

// Alimentacion
    bool alimentacionDC;
    bool alimentacionAC;

// Tipo Control
    int controlAC;
    int controlDC;

};

#endif // CONVERTIDOR_H
