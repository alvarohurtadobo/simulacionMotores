#ifndef MOTORINDUCCION_H
#define MOTORINDUCCION_H

#include <cmath>

class MotorInduccion
{
public:
    MotorInduccion();

// Se alimenta y luego inmediatamente se actualiza:
    void alimentar(double voltage, double frequency);

// El motor tampoco se encarga del transcurso del tiempo
    void actualizar(double sampleTime,int counter);

// El deslizamiento como parámetro externo
    void actualizar(double sampleTime,int counter, double glide);

    double respuestaTorqueCorriente(double current);
    double respuestaTorqueDeslizamiento(double glide);
    double respuestaTorqueDeslizamiento(double glide,double frequency);

    void setResistenciaEstator(double Rs);
    double getResistenciaEstator();
    void setResistenciaRotor(double Rr);
    double getResistenciaRotor();
    void setReactanciaEstator(double Xs);
    double getReactanciaEstator();
    void setReactanciaRotor(double Xr);
    double getReactanciaRotor();
    void setReactanciaMotor(double Xm);
    double getReactanciaMotor();

    double getTorqueMaximo();
    double getDeslizamientoMaximo();
    double getVelocidadMaxima();

    double getFrecuenciaTrabajo();
    double getFrecuenciaNominal();

    double getBeta();


// Salidas
    double getSalida();

    double voltajeNominal;
    double potenciaNominal;
    double velocidadNominal;
    double frecuenciaNominal;
    int numeroPolos;

private:
// CARACTERÍSTICAS CONSTRUCTIVAS
    double resistenciaRotor;
    double resistenciaEstator;
    double reactanciaRotor;
    double reactanciaEstator;
    double reactanciaMotor;

// PARÁMETROS DE PLACA


// OTROS PARÁMETROS
    double temperatura;

// ENTRADAS ACTUALES
    double tensionFase;
    double corriente;
    double frecuencia;
    int tipoConexion;                       // 0 -> Estrella (defecto); 1 -> Triangulo

// SALIDAS ACTUALES
    double velocidad;
    double torque;

// OTROS PARÁMETROS ELÉCTRICOS
    double impedanciaEntrada;
    double deslizamiento;
    double beta;
    double relacionVF;

// CARACTERÍSTICAS DE RENDIMIENTO
    double potenciaEntrada;
    double perdidasCobreEstator;
    double perdidasCobreRotor;
    double perdidasCobreNucleo;

// MÉTODOS PRIVADOS
    double calcularImpedanciaEntrada();

};

#endif // MOTORINDUCCION_H
