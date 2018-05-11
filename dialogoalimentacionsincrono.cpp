#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "dialogoalimentacionsincrono.h"

#include <cmath>

DialogoAlimentacionSincrono::DialogoAlimentacionSincrono(MotorInduccion * miMotor)
{
    elMotor = miMotor;

    etiquetaAmplitud = new QLabel("Ingrese la amplitud");
    etiquetaFrecuencia = new QLabel("Ingrese la frecuencia");
    datoAmplitud = new QLineEdit;
    datoFrecuencia = new QLineEdit;
    aceptar = new QPushButton("Aceptar");
    verGrafica = new QPushButton("Mostrar gráfica");

    aceptar->setDefault(true);
    verGrafica->setDefault(true);

    connect(aceptar,SIGNAL(clicked()),this,SLOT(botonAceptarClicked()));
    connect(verGrafica,SIGNAL(clicked()),this,SLOT(botonGenerarClicked()));

    QHBoxLayout * amplitud = new QHBoxLayout;
    amplitud->addWidget(etiquetaAmplitud);
    amplitud->addWidget(datoAmplitud);

    QHBoxLayout * frecuencia = new QHBoxLayout;
    frecuencia->addWidget(etiquetaFrecuencia);
    frecuencia->addWidget(datoFrecuencia);

    QHBoxLayout * opciones = new QHBoxLayout;
    opciones->addWidget(verGrafica);
    opciones->addWidget(aceptar);

    QVBoxLayout * total = new QVBoxLayout;
    total->addLayout(amplitud);
    total->addLayout(frecuencia);
    total->addLayout(opciones);

    this->setLayout(total);
    setWindowTitle("Alimentación");
}

void DialogoAlimentacionSincrono::botonAceptarClicked()
{
    elMotor->alimentar(datoAmplitud->text().toDouble(),datoFrecuencia->text().toDouble());
    emit close();
}

void DialogoAlimentacionSincrono::botonGenerarClicked()
{
    double amplitude = datoAmplitud->text().toDouble();
    double frecuencia = datoFrecuencia->text().toDouble();

    elMotor->alimentar(datoAmplitud->text().toDouble(),datoFrecuencia->text().toDouble());

    Graficador* curvaTorqueDelizamiento = new Graficador;
    curvaTorqueDelizamiento->setNombre("Alimentacion");

// SE PONE EL INTERVALO DE MUESTREO
    curvaTorqueDelizamiento->setTiempoMuestreo(0.001);

// SE PONDE LOS PUNTOS A LA GRÁFICA
    for(int i = 0; i<400; i++)
        curvaTorqueDelizamiento->agregarPunto(amplitude*sin(2*3.141592658*frecuencia*i*0.001));

// SE ESTABLECEN LAS CONFUGURACIONES NECESARIAS
    curvaTorqueDelizamiento->setRangoX(0,5/frecuencia);
    curvaTorqueDelizamiento->setRangoY(-1.2*amplitude,1.2*amplitude);
    curvaTorqueDelizamiento->EtiquetaX("Tiempo [S]");
    curvaTorqueDelizamiento->EtiquetaY("Vs [V]");

// SE MUESTRA LA GRÁFICA
    curvaTorqueDelizamiento->show();
}
