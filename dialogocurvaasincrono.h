#ifndef DIALOGOCURVAASINCRONO_H
#define DIALOGOCURVAASINCRONO_H

#include <QDialog>              // Ten cuidado al ir a LINUX

#include <graficador.h>
#include <motorinduccion.h>
#include <sistemacontrol.h>
#include <dialogoalimentacionsincrono.h>


#include <stdlib.h>

#define MAX_OP 10

class QLabel;
class QLineEdit;
class QPushButton;
class QSlider;
class QDial;
class QSpinBox;
class QCustomPlot;
class QDoubleSpinBox;

class DialogoCurvaAsincrono : public QDialog
{
    Q_OBJECT

public:
    DialogoCurvaAsincrono(QWidget *parent = 0);
    ~DialogoCurvaAsincrono();
    void setMotorInduccion(MotorInduccion * miMotor);

signals:
    bool ResistenciaEstatorIntroducido();

private slots:
    void botonGenerarClicked();
    void botonAceptarClicked();
    void botonCancelarClicked();
    void botonAlimentacionClicked();
    void arrancarClicked();

    void actualizarGrafica();

    void valor1Changed(double val1);
    void valor2Changed(double val2);
    void valor3Changed(double val3);
    void valor4Changed(double val4);
    void valor5Changed(double val5);

private:
// ALIMENTACION
    QLabel * etiquetaAmplitud;
    QLabel * etiquetaFrecuencia;

    QDial * sliderAlimentacion;
    QSlider * sliderFrecuencia;

    QSpinBox * datoAmplitud;
    QSpinBox * datoFrecuencia;

// CIRCUITO EQUIVALENTE
    QLabel * etiquetas[MAX_OP];
    QDoubleSpinBox * misEntradas[MAX_OP];
    QPushButton * generarCurvaTD;
    QPushButton * botonAceptar;
    QPushButton * botonCancelar;
    QPushButton * botonAgregarAlimentacion;
    QPushButton * arranque;

    QLabel * labDes;
    QLabel * labPar;
    QLabel * labVel;
    QLabel * labBet;

    QLineEdit * outDes;
    QLineEdit * outPar;
    QLineEdit * outVel;
    QLineEdit * outBet;

//PLACA
    QLabel * labVoltajeNominal;
    QLabel * labPotenciaNominal;
    QLabel * labVelocidadNominal;
    QLabel * labFrecuenciaNominal;
    QLabel * labNumeroPolos;

    QDoubleSpinBox * inVoltajeNominal;
    QDoubleSpinBox * inPotenciaNominal;
    QDoubleSpinBox * inVelocidadNominal;
    QDoubleSpinBox * inFrecuenciaNominal;
    QDoubleSpinBox * inNumeroPolos;


// Otros
    QLabel * labelPlaca;
    QLabel * labelCaracteristicas;
    QLabel * labelAlimentacion;
    QLabel * labelSalida;
    QCustomPlot * laGrafica;

// EL MOTOR

    MotorInduccion * miMotorInduccion;

// LA GRÁFICA
    Graficador * curvaTorqueDelizamiento;

    DialogoAlimentacionSincrono * alimentacion;
};

#endif // DIALOGOCURVAASINCRONO_H
