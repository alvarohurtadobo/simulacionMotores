#ifndef FUENTEDC_H
#define FUENTEDC_H

#include <generador.h>

class FuenteDC : public Generador
{
public:
    FuenteDC();
    FuenteDC(double amplitude);

    void actualizar(double sampleTime, int counter);

//SETTER's AND GETTER's
    void setAmplitud(double amplitude);
    double getAmplitud();

private:
    double amplitud;

};

#endif // FUENTEDC_H
