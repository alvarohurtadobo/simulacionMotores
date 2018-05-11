#ifndef GENERADOR_H
#define GENERADOR_H

#include <cstdlib>

#include <cmath>

// A diferencia del otro "Generador" este no es heredero de "ElementoControl", el único parámetro q tuvo que ser declarado es "salida"
// Generador no se encargará del conteo del tiempo!!!
// El método actualizar fue redefinido como virtual

class Generador
{
public:
    Generador();
    virtual void actualizar(double sampleTime, int counter) = 0;

    // Ruido
    void activarRuido();
    void desactivarRuido();

    //Estado
    void encender();
    void apagar();

    double getSalida();

protected:
    bool ruido;
    bool estado;
    double salida;

};

#endif // GENERADOR_H
