#ifndef FUENTECA_H
#define FUENTECA_H

#include <generador.h>


class FuenteCA : public Generador
{
public:
    FuenteCA();
    FuenteCA(double amplitude, double frequency, double phase);

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

#endif // FUENTECA_H
