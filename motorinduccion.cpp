#include "motorinduccion.h"

MotorInduccion::MotorInduccion()
{
    // Se inicializarán los datos del motor tomando en cuenta al motor del problema 3 de clase:
    // En unidades S.I.

    resistenciaRotor = 0.38;
    resistenciaEstator = 0.66;
    reactanciaRotor = 1.71;
    reactanciaEstator = 1.14;
    reactanciaMotor = 33.2;

// PARÁMETROS DE PLACA
    voltajeNominal = 460;                               // [V]
    potenciaNominal = 11200;                            // [W]
    velocidadNominal = 183.260;                         // [rad/s]
    frecuenciaNominal = 50;                             // [1/s]
    numeroPolos = 4;

// ENTRADAS ACTUALES
    tensionFase = 0;
    corriente = 0;
    frecuencia = 50;
    tipoConexion = 0;

// SALIDAS ACTUALES
    velocidad = 0;
    torque = 0;

// OTROS PARÁMETROS ELÉCTRICOS
    deslizamiento = 0;
    beta = 1;
    relacionVF = voltajeNominal/frecuenciaNominal;

// OTROS PARÁMETROS
    temperatura = 283;
}


void MotorInduccion::alimentar(double voltage, double frequency)
{
    tensionFase = voltage;
    frecuencia = frequency;
}

void MotorInduccion::actualizar(double sampleTime, int counter)
{
    //
}

void MotorInduccion::actualizar(double sampleTime,int counter, double glide)
{
    double numerador,denominador;
    numerador = (1-exp(-0.5*sampleTime*counter))*tensionFase;
    denominador = sqrt((resistenciaEstator+resistenciaRotor/glide)*(resistenciaEstator+resistenciaRotor/glide)+frecuencia*frecuencia*(reactanciaEstator+reactanciaRotor)*(reactanciaEstator+reactanciaRotor)/(frecuenciaNominal*frecuenciaNominal));
    corriente = numerador/denominador;
}

double MotorInduccion::getSalida()
{
    return corriente;
}
double MotorInduccion::respuestaTorqueDeslizamiento(double glide)
{
    double numerador,denominador;
    numerador = 3*resistenciaRotor*tensionFase*tensionFase;
    denominador = glide*2*3.141592658*frecuenciaNominal*((resistenciaEstator+resistenciaRotor/glide)*(resistenciaEstator+resistenciaRotor/glide)+(reactanciaEstator+reactanciaRotor)*(reactanciaEstator+reactanciaRotor));
    return numerador/denominador;
}

double MotorInduccion::respuestaTorqueDeslizamiento(double glide,double frequency)
{
    frecuencia = frequency;
    double numerador,denominador;
    numerador = 3*resistenciaRotor*tensionFase*tensionFase;
    denominador = glide*2*3.141592658*frequency*((resistenciaEstator+resistenciaRotor/glide)*(resistenciaEstator+resistenciaRotor/glide)+frequency/frecuenciaNominal*(reactanciaEstator+reactanciaRotor)*frequency/frecuenciaNominal*(reactanciaEstator+reactanciaRotor));
    return numerador/denominador;
}

void MotorInduccion::setResistenciaEstator(double Rs)
{
    resistenciaEstator = Rs;
}
double MotorInduccion::getResistenciaEstator()
{
    return resistenciaEstator;
}
void MotorInduccion::setResistenciaRotor(double Rr)
{
    resistenciaRotor = Rr;
}

double MotorInduccion::getResistenciaRotor()
{
    return resistenciaRotor;
}

void MotorInduccion::setReactanciaEstator(double Xs)
{
    reactanciaEstator = Xs;
}

double MotorInduccion::getReactanciaEstator()
{
    return reactanciaEstator;
}

void MotorInduccion::setReactanciaRotor(double Xr)
{
    reactanciaRotor = Xr;
}

double MotorInduccion::getReactanciaRotor()
{
    return reactanciaRotor;
}

void MotorInduccion::setReactanciaMotor(double Xm)
{
    reactanciaMotor = Xm;
}

double MotorInduccion::getReactanciaMotor()
{
    return reactanciaMotor;
}

double MotorInduccion::getTorqueMaximo()
{
    /*double numerador = 3*tensionFase*tensionFase;
    double denominador = 2*2*3.141592658*frecuencia*(resistenciaEstator+sqrt(resistenciaEstator*resistenciaEstator+beta*beta*(reactanciaEstator+reactanciaRotor)*(reactanciaEstator+reactanciaRotor)));
    return numerador/denominador;*/
    return this->respuestaTorqueDeslizamiento(this->getDeslizamientoMaximo(),frecuencia);
}

double MotorInduccion::getDeslizamientoMaximo()
{
    return resistenciaRotor/sqrt(resistenciaEstator*resistenciaEstator+beta*beta*(reactanciaEstator+reactanciaRotor)*(reactanciaEstator+reactanciaRotor));
}

double MotorInduccion::getVelocidadMaxima()
{
    double desliz=getDeslizamientoMaximo();
    //double par=getTorqueMaximo();
    return 2*3.141592658*frecuencia*(1-desliz)/(numeroPolos/2);
}

double MotorInduccion::getFrecuenciaTrabajo()
{
    return frecuencia;
}

double MotorInduccion::getFrecuenciaNominal()
{
    return frecuenciaNominal;
}

double MotorInduccion::getBeta()
{
    beta = frecuencia/frecuenciaNominal;
    return beta;
}
