#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "about.h"

About::About()
{
    etiqueta = new QLabel("Este programa fue desarrollado por los estudiantes: \n Alvaro Hurtado \n de la Universidad Técnica de Oruro \n Copyright UTO 2014-2020. Todos los derechos reservados");
    aceptar = new QPushButton("Aceptar");

    aceptar->setDefault(true);

//
    connect(aceptar,SIGNAL(clicked()),this,SLOT(botonAceptarClicked()));

    QVBoxLayout * miLayout = new QVBoxLayout;
    miLayout->addWidget(etiqueta);
    miLayout->addWidget(aceptar);

    this->setLayout(miLayout);

    setWindowTitle("SM 1.0.1 Simulacion motores");
}

void About::botonAceptarClicked()
{
    this->close();
}
