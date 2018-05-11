#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QDial>
#include <QSpinBox>
#include <qcustomplot.h>

#include "dialogocurvaasincrono.h"
#include <carga.h>
#include <cmath>

DialogoCurvaAsincrono::DialogoCurvaAsincrono(QWidget * parent) : QDialog(parent)
{
// INICIALIZACIONES:
// LA GRAFICA NO SE INICIALIZARA POR AHORA
    curvaTorqueDelizamiento = 0;
    miMotorInduccion = new MotorInduccion;

// CREACIÓN DE OBJETOS DE QT:
// ALIMENTACION:

    etiquetaAmplitud = new QLabel("Tensión Alimentación:");
    etiquetaFrecuencia = new QLabel("Frecuencia:");
    sliderAlimentacion = new QDial;
    sliderFrecuencia = new QSlider(Qt::Horizontal);
    datoAmplitud = new QSpinBox;
    datoFrecuencia = new QSpinBox;

    //Tamaño:
    datoAmplitud->setMaximumWidth(50);
    datoFrecuencia->setMaximumWidth(50);
    sliderAlimentacion->setMaximumHeight(75);

// Por Defecto y Rangos:
    sliderAlimentacion->setRange(0,460);
    sliderAlimentacion->setValue(311);
    sliderFrecuencia->setRange(10,250);
    sliderFrecuencia->setValue(50);
    datoAmplitud->setRange(0,460);
    datoFrecuencia->setRange(10,250);

    datoAmplitud->setValue(311);
    datoFrecuencia->setValue(50);

// Se conecta:
    connect(sliderAlimentacion,SIGNAL(valueChanged(int)),datoAmplitud,SLOT(setValue(int)));
    connect(datoAmplitud,SIGNAL(valueChanged(int)),sliderAlimentacion,SLOT(setValue(int)));
    connect(sliderFrecuencia,SIGNAL(valueChanged(int)),datoFrecuencia,SLOT(setValue(int)));
    connect(datoFrecuencia,SIGNAL(valueChanged(int)),sliderFrecuencia,SLOT(setValue(int)));



// CIRCUITO EQUIVALENTE:
// Se crean las etiquetas
    etiquetas[1] = new QLabel("Resistencia Estator:");
    etiquetas[2] = new QLabel("Resistencia Rotor:");
    etiquetas[3] = new QLabel("Reactancia Estator:");
    etiquetas[4] = new QLabel("Reactancia Rotor:");
    etiquetas[5] = new QLabel("Reactancia magnetizacion:");

// Se crean las entradas, las lineas a editar
    misEntradas[1] = new QDoubleSpinBox;
    misEntradas[2] = new QDoubleSpinBox;
    misEntradas[3] = new QDoubleSpinBox;
    misEntradas[4] = new QDoubleSpinBox;
    misEntradas[5] = new QDoubleSpinBox;

// El intervalo de 0.01:
    misEntradas[1]->setSingleStep(0.01);
    misEntradas[2]->setSingleStep(0.01);
    misEntradas[3]->setSingleStep(0.01);
    misEntradas[4]->setSingleStep(0.01);
    misEntradas[5]->setSingleStep(0.01);

// El tamaño máximo será 50
    misEntradas[1]->setMaximumWidth(50);
    misEntradas[2]->setMaximumWidth(50);
    misEntradas[3]->setMaximumWidth(50);
    misEntradas[4]->setMaximumWidth(50);
    misEntradas[5]->setMaximumWidth(50);

// El valor por defecto de las entradas:
    misEntradas[1]->setRange(0,100);
    misEntradas[2]->setRange(0,100);
    misEntradas[3]->setRange(0,100);
    misEntradas[4]->setRange(0,100);
    misEntradas[5]->setRange(0,100);
    misEntradas[1]->setValue(0.15);
    misEntradas[2]->setValue(0.15);
    misEntradas[3]->setValue(1.5);
    misEntradas[4]->setValue(1.5);
    misEntradas[5]->setValue(30);

// Se crean los botones
    botonAceptar = new QPushButton("Aceptar");
    botonCancelar = new QPushButton("Cancelar");
    generarCurvaTD = new QPushButton("Generar Curva Par/Deslizamiento");
    botonAgregarAlimentacion = new QPushButton("PARÁMETROS DE ALIMENTACIÓN:");
    arranque = new QPushButton("Arrancar Motor");

// Se detean los botones por defecto
    botonAceptar->setDefault(true);
    botonCancelar->setDefault(true);
    generarCurvaTD->setDefault(true);
    botonAgregarAlimentacion->setDefault(true);
    arranque->setDefault(true);

// Se conectan los botones
    connect(botonAceptar,SIGNAL(clicked()),this,SLOT(botonAceptarClicked()));
    connect(generarCurvaTD,SIGNAL(clicked()),this,SLOT(botonGenerarClicked()));
    connect(botonCancelar,SIGNAL(clicked()),this,SLOT(botonCancelarClicked()));
    connect(botonAgregarAlimentacion,SIGNAL(clicked()),this,SLOT(botonAlimentacionClicked()));
    connect(arranque,SIGNAL(clicked()),this,SLOT(arrancarClicked()));

// GRAFICA
    laGrafica = new QCustomPlot;
    laGrafica->setMinimumWidth(450);
    laGrafica->addGraph();
    laGrafica->graph(0)->setPen(QPen(Qt::green));
    laGrafica->graph(0)->setBrush(QColor(0,0,255,0));
    laGrafica->xAxis->setRange(0,1);
    laGrafica->xAxis->setLabel("Deslizamiento");
    laGrafica->yAxis->setLabel("Par [N m]");


// Se conectan todas las señales a la grafica:
    connect(sliderAlimentacion,SIGNAL(valueChanged(int)),this,SLOT(actualizarGrafica()));
    connect(sliderFrecuencia,SIGNAL(valueChanged(int)),this,SLOT(actualizarGrafica()));
    connect(misEntradas[1],SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    connect(misEntradas[2],SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    connect(misEntradas[3],SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    connect(misEntradas[4],SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    connect(misEntradas[5],SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    //connect(*,SIGNAL(valueChanged(int)),this,SLOT(actualizarGrafica()));



// Se crean las Layout:

    QHBoxLayout * amplitud = new QHBoxLayout;
    amplitud->addWidget(etiquetaAmplitud);
    amplitud->addWidget(datoAmplitud);
    QHBoxLayout * sliderAlim = new QHBoxLayout;
    sliderAlim->addWidget(sliderAlimentacion);

    QHBoxLayout * frecuencia = new QHBoxLayout;
    frecuencia->addWidget(etiquetaFrecuencia);
    frecuencia->addWidget(datoFrecuencia);
    QHBoxLayout * sliderFrec = new QHBoxLayout;
    sliderFrec->addWidget(sliderFrecuencia);

    labelAlimentacion = new QLabel("PARÁMETROS DE ALIMENTACIÓN:");
    QVBoxLayout * alimentacion = new QVBoxLayout;
    alimentacion->addWidget(labelAlimentacion);
    alimentacion->addLayout(amplitud);
    alimentacion->addLayout(sliderAlim);
    alimentacion->addLayout(frecuencia);
    alimentacion->addLayout(sliderFrec);

// La segunda parte:

    QHBoxLayout * configuracion = new QHBoxLayout;
    //configuracion->addWidget(botonAgregarAlimentacion);
    configuracion->addWidget(arranque);

    QHBoxLayout * placeRs = new QHBoxLayout();
    placeRs->addWidget(etiquetas[1]);
    placeRs->addWidget(misEntradas[1]);

    QHBoxLayout * placeRr = new QHBoxLayout();
    placeRr->addWidget(etiquetas[2]);
    placeRr->addWidget(misEntradas[2]);

    QHBoxLayout * placeXs = new QHBoxLayout();
    placeXs->addWidget(etiquetas[3]);
    placeXs->addWidget(misEntradas[3]);

    QHBoxLayout * placeXr = new QHBoxLayout();
    placeXr->addWidget(etiquetas[4]);
    placeXr->addWidget(misEntradas[4]);

    QHBoxLayout * placeXm = new QHBoxLayout();
    placeXm->addWidget(etiquetas[5]);
    placeXm->addWidget(misEntradas[5]);


    //QHBoxLayout * botones = new QHBoxLayout();
    //botones->addWidget(generarCurvaTD);

    QHBoxLayout * opciones = new QHBoxLayout();
    opciones->addWidget(botonAceptar);
    opciones->addWidget(botonCancelar);

    labelCaracteristicas = new QLabel("CIRCUITO EQUIVALENTE: ");
    QVBoxLayout * caracteristicas = new QVBoxLayout();

    caracteristicas->addLayout(configuracion);
    caracteristicas->addWidget(labelCaracteristicas);
    caracteristicas->addLayout(placeRs);
    caracteristicas->addLayout(placeRr);
    caracteristicas->addLayout(placeXs);
    caracteristicas->addLayout(placeXr);
    caracteristicas->addLayout(placeXm);
    //caracteristicas->addLayout(botones); //OLD GRAPHIC


// SALIDAS
    labDes = new QLabel("Deslizamiento para \n par maximo:");
    labPar = new QLabel("Par maximo [N m]:");
    labVel = new QLabel("Velocidad para \n par maximo [rpm]:");
    labBet = new QLabel("Beta:");

    outDes = new QLineEdit();
    outPar = new QLineEdit();
    outVel = new QLineEdit();
    outBet = new QLineEdit();

    outDes->setMaximumWidth(100);
    outPar->setMaximumWidth(100);
    outVel->setMaximumWidth(100);
    outBet->setMaximumWidth(60);

    QHBoxLayout * beta = new QHBoxLayout();
    beta->addWidget(labBet);
    beta->addWidget(outBet);

    labelSalida = new QLabel("SALIDA PARA TORQUE MÁXIMO:");
    QVBoxLayout * salidas = new QVBoxLayout();
    salidas->addWidget(labelSalida);
    salidas->addWidget(labPar);
    salidas->addWidget(outPar);
    salidas->addWidget(labDes);
    salidas->addWidget(outDes);
    salidas->addWidget(labVel);
    salidas->addWidget(outVel);
    salidas->addLayout(beta);
    salidas->addLayout(opciones);

// PLACA
    labVoltajeNominal = new QLabel("Tensión Nominal [V]:");
    labPotenciaNominal = new QLabel("Potencia Nominal [HP]:");
    labVelocidadNominal = new QLabel("Velocidad Nominal [rpm]:");
    labFrecuenciaNominal = new QLabel("Frecuencia Nominal [Hz]:");
    labNumeroPolos = new QLabel("Número de polos:");

    inVoltajeNominal = new QDoubleSpinBox();
    inPotenciaNominal = new QDoubleSpinBox();
    inVelocidadNominal = new QDoubleSpinBox();
    inFrecuenciaNominal = new QDoubleSpinBox();
    inNumeroPolos = new QDoubleSpinBox();

    inVoltajeNominal->setRange(0,460);
    inPotenciaNominal->setRange(0,100);
    inVelocidadNominal->setRange(0,5000);
    inFrecuenciaNominal->setRange(1,100);
    inNumeroPolos->setRange(2,128);

    inVoltajeNominal->setValue(220);
    inPotenciaNominal->setValue(10);
    inVelocidadNominal->setValue(3000);
    inFrecuenciaNominal->setValue(50);
    inNumeroPolos->setValue(2);

    inVoltajeNominal->setSingleStep(5);
    inPotenciaNominal->setSingleStep(0.25);
    inVelocidadNominal->setSingleStep(10);
    inFrecuenciaNominal->setSingleStep(0.5);
    inNumeroPolos->setSingleStep(2);

    QHBoxLayout * vol =  new QHBoxLayout();
    vol->addWidget(labVoltajeNominal);
    vol->addWidget(inVoltajeNominal);

    QHBoxLayout * pot = new QHBoxLayout();
    pot->addWidget(labPotenciaNominal);
    pot->addWidget(inPotenciaNominal);


    QHBoxLayout * vel = new QHBoxLayout();
    vel->addWidget(labVelocidadNominal);
    vel->addWidget(inVelocidadNominal);

    QHBoxLayout * frec = new QHBoxLayout();
    frec->addWidget(labFrecuenciaNominal);
    frec->addWidget(inFrecuenciaNominal);

    QHBoxLayout * pol = new QHBoxLayout();
    pol->addWidget(labNumeroPolos);
    pol->addWidget(inNumeroPolos);

    labelPlaca = new QLabel("PARÁMETROS DE PLACA:");
    QVBoxLayout * placa = new QVBoxLayout();
    placa->addWidget(labelPlaca);
    placa->addLayout(vol);
    placa->addLayout(pot);
    placa->addLayout(vel);
    placa->addLayout(frec);
    placa->addLayout(pol);


// PLOT
    QVBoxLayout * grafica = new QVBoxLayout();
    grafica->addWidget(laGrafica);

    QVBoxLayout * totalVentana1 = new QVBoxLayout();
    totalVentana1->addLayout(placa);
    totalVentana1->addLayout(alimentacion);

    QVBoxLayout * totalVentana2 = new QVBoxLayout();
    totalVentana2->addLayout(caracteristicas);
    totalVentana2->addLayout(salidas);

    QHBoxLayout * totalVentana = new QHBoxLayout();
    totalVentana->addLayout(totalVentana1);
    totalVentana->addLayout(totalVentana2);
    totalVentana->addLayout(grafica);

    this->setLayout(totalVentana);

    // Ultimas conexiones:
    connect(inNumeroPolos,SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));
    connect(inFrecuenciaNominal,SIGNAL(valueChanged(double)),this,SLOT(actualizarGrafica()));

    setWindowTitle("Motor Inducción");

    actualizarGrafica();
}

DialogoCurvaAsincrono::~DialogoCurvaAsincrono()
{

}

void DialogoCurvaAsincrono::setMotorInduccion(MotorInduccion *miMotor)
{
    miMotorInduccion = miMotor;
}

void DialogoCurvaAsincrono::botonGenerarClicked()
{
//ACTUALIZA LOS VALORES DEL MOTOR A LOS INTRODUCIDOS
    miMotorInduccion->setResistenciaEstator(misEntradas[1]->text().toDouble());
    miMotorInduccion->setResistenciaRotor(misEntradas[2]->text().toDouble());
    miMotorInduccion->setReactanciaEstator(misEntradas[3]->text().toDouble());
    miMotorInduccion->setReactanciaRotor(misEntradas[4]->text().toDouble());
    miMotorInduccion->setReactanciaMotor(misEntradas[5]->text().toDouble());

// CREA EL GRAFICADOR PARA EVITAR EL PROBLEMA DEL BORRADO DE PUNTOS (ARREGLAR)
    curvaTorqueDelizamiento = new Graficador;
    curvaTorqueDelizamiento->setNombre("Curva Torque Deslizamiento");

// SE PONE EL INTERVALO DE MUESTREO
    curvaTorqueDelizamiento->setTiempoMuestreo(0.001);

// SE PONDE LOS PUNTOS A LA GRÁFICA
    for(int i = 0; i<1000; i++)
        curvaTorqueDelizamiento->agregarPunto(miMotorInduccion->respuestaTorqueDeslizamiento(0.001*i));

// SE ESTABLECEN LAS CONFUGURACIONES NECESARIAS
    curvaTorqueDelizamiento->setRangoX(0,1);
    curvaTorqueDelizamiento->EtiquetaX("Desplazamiento");
    curvaTorqueDelizamiento->EtiquetaY("Torque");



// SE MUESTRA LA GRÁFICA
    curvaTorqueDelizamiento->show();
}

void DialogoCurvaAsincrono::botonCancelarClicked()
{
    emit close();
}

void DialogoCurvaAsincrono::botonAceptarClicked()
{
// SE ACTUALIZAN LOS VALORES UNICAMENTE
// QLineEdit ya tiene metodos para convertir a DOUBLE
    miMotorInduccion->setResistenciaEstator(misEntradas[1]->text().toDouble());
    miMotorInduccion->setResistenciaRotor(misEntradas[2]->text().toDouble());
    miMotorInduccion->setReactanciaEstator(misEntradas[3]->text().toDouble());
    miMotorInduccion->setReactanciaRotor(misEntradas[4]->text().toDouble());
    miMotorInduccion->setReactanciaMotor(misEntradas[5]->text().toDouble());

    emit close();
}

void DialogoCurvaAsincrono::botonAlimentacionClicked()
{
    alimentacion = new DialogoAlimentacionSincrono(miMotorInduccion);
    alimentacion->show();
}

void  DialogoCurvaAsincrono::arrancarClicked()
{
    // PRUEBA ARRANQUE

        MotorInduccion motorArranque;
        motorArranque.alimentar(220,50);

        Carga miCarga;

        Graficador *miGrafica = new Graficador;
        miGrafica->setNombre("Corriente [A]");
        miGrafica->setTiempoMuestreo(0.001);
        miGrafica->EtiquetaY("Corriente [A]");

        for(int i = 0; i<10000;i++)
        {
            //motorArranque
                    miMotorInduccion->actualizar(0.001,i,miCarga.getDeslizamiento(0.001,i));
            miGrafica->agregarPunto(miMotorInduccion->getSalida());
        }

        miGrafica->show();
}

void DialogoCurvaAsincrono::actualizarGrafica()
{
    miMotorInduccion->numeroPolos=inNumeroPolos->text().toDouble();
    miMotorInduccion->frecuenciaNominal=inFrecuenciaNominal->text().toDouble();

    miMotorInduccion->setResistenciaEstator(misEntradas[1]->text().toDouble());
    miMotorInduccion->setResistenciaRotor(misEntradas[2]->text().toDouble());
    miMotorInduccion->setReactanciaEstator(misEntradas[3]->text().toDouble());
    miMotorInduccion->setReactanciaRotor(misEntradas[4]->text().toDouble());
    miMotorInduccion->setReactanciaMotor(misEntradas[5]->text().toDouble());
    miMotorInduccion->alimentar(datoAmplitud->text().toDouble(),datoFrecuencia->text().toDouble());

    double yMaximo = 0;
    double frec = datoFrecuencia->text().toDouble();

    QVector<double> x(100), y(100);
    for(int i = 0; i<100; i++)
    {
        x[i]=0.01*(double)i;
        y[i]=miMotorInduccion->respuestaTorqueDeslizamiento(x[i],frec);
        if(yMaximo < y[i])
            yMaximo = y[i];
    }

    laGrafica->graph(0)->setData(x,y);
    laGrafica->yAxis->setRange(0,1.2*yMaximo);
    setWindowTitle("Curva Par-Deslizamiento");
    laGrafica->replot();

    outPar->setText(QString::number(miMotorInduccion->getTorqueMaximo()));
    outDes->setText(QString::number(miMotorInduccion->getDeslizamientoMaximo()));
    outVel->setText(QString::number(miMotorInduccion->getVelocidadMaxima()*30/3.141592658));
    outBet->setText(QString::number(miMotorInduccion->getBeta()));
}

void DialogoCurvaAsincrono::valor1Changed(double val1)
{
    miMotorInduccion->setReactanciaEstator(val1);
}

void DialogoCurvaAsincrono::valor2Changed(double val2)
{
    miMotorInduccion->setReactanciaEstator(val2);
}
void DialogoCurvaAsincrono::valor3Changed(double val3)
{
    miMotorInduccion->setReactanciaEstator(val3);
}
void DialogoCurvaAsincrono::valor4Changed(double val4)
{
    miMotorInduccion->setReactanciaEstator(val4);
}
void DialogoCurvaAsincrono::valor5Changed(double val5)
{
    miMotorInduccion->setReactanciaEstator(val5);
}
