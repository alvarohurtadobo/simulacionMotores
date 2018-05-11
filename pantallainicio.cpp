#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "pantallainicio.h"
#include <convertidoracdccompleto.h>

pantallaInicio::pantallaInicio()
{
    miSistemaEstudio = new SistemaControl;

    // CREACIÓN DE OBJETOS DE QT:
// Se crean las etiquetas

    miEtiqueta=new QLabel("Desea simular un:");

// Se crean los botones

    botonAceptar = new QPushButton("Aceptar");
    botonCancelar = new QPushButton("Cancelar");
    motorAleterna = new QPushButton("Motor AC") ;
    motorContinua = new QPushButton("Motor DC") ;

// Se detean los botones por defecto
    botonAceptar->setDefault(true);
    botonCancelar->setDefault(true);
    motorAleterna->setDefault(true);
    motorContinua->setDefault(true);


// Se conectan los botones
    connect(botonAceptar,SIGNAL(clicked()),this,SLOT(botonAceptarClicked()));
    connect(botonCancelar,SIGNAL(clicked()),this,SLOT(botonCancelarClicked()));
    connect(motorAleterna,SIGNAL(clicked()),this,SLOT(botonAlternaClicked()));
    connect(motorContinua,SIGNAL(clicked()),this,SLOT(botonContinuaClicked()));

// Se crean los layout:
    QHBoxLayout * etiqueta = new QHBoxLayout;
    etiqueta->addWidget(miEtiqueta);

    QHBoxLayout * seleccion = new QHBoxLayout;
    seleccion->addWidget(motorAleterna);
    seleccion->addWidget(motorContinua);

    QHBoxLayout * opciones = new QHBoxLayout;
    opciones->addWidget(botonAceptar);
    opciones->addWidget(botonCancelar);

    QVBoxLayout * total = new QVBoxLayout;
    total->addLayout(etiqueta);
    total->addLayout(seleccion);
    total->addLayout(opciones);

    this->setLayout(total);
    setWindowTitle("Bienvenido");
}

void pantallaInicio::botonAlternaClicked()
{
    miSistemaEstudio->setMotorInduccion();
    DialogoCurvaAsincrono * miVentana = new DialogoCurvaAsincrono;

// Se carga el motor del sistema de control a la ventana de muestra
    miVentana->setMotorInduccion(miSistemaEstudio->getMotorInduccion());
    miVentana->show();
}

void pantallaInicio::botonContinuaClicked()
{
    Graficador * graficaConvertidor = new Graficador;
    ConvertidorACDCCompleto * miConvertidor = new ConvertidorACDCCompleto;

    graficaConvertidor->setTiempoMuestreo(0.00001);
    graficaConvertidor->setNombre("En construcción!!! Pronto: Convertidores y motores DC!!");
    graficaConvertidor->EtiquetaY("Salida convertidor");

    miConvertidor->setFrecuencia(50);
    miConvertidor->setAmplitud(220*1.414);
    miConvertidor->setAnguloDisparo(25);

    for(int i = 0; i<10000; i++)
    {
        miConvertidor->actualizar(0.00001,i);
        graficaConvertidor->agregarPunto(miConvertidor->getSalida());
    }
    graficaConvertidor->setRangoX(0,0.04);
    graficaConvertidor->setRangoY(-320,320);

    graficaConvertidor->show();
}

void pantallaInicio::botonAceptarClicked()
{
    acercaDe = new About;
    acercaDe->show();
    emit close();
}

void pantallaInicio::botonCancelarClicked()
{
    emit close();
}
