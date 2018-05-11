#ifndef VARIADORFRECUENCIA_H
#define VARIADORFRECUENCIA_H

#include <convertidor.h>
#include <generador.h>

class VariadorFrecuencia : public Convertidor
{
public:
    VariadorFrecuencia();
    VariadorFrecuencia(double amplitude, double frequency, double phase);

    void actualizar(double sampleTime, int counter);

// GETTER's and SETTER's
    void setFrecuenciaHz(double frequency);
    double getFrecuenciaHz();
    void setAmplitud(double amplitude);
    double getAmplitud();
    void setFase(double phase);
    double getFase();

private:
    double frecuenciaHz;
    double amplitud;
    double fase;
    double tipo;
};

#endif // VARIADORFRECUENCIA_H
