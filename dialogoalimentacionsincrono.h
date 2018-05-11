#ifndef DIALOGOALIMENTACIONSINCRONO_H
#define DIALOGOALIMENTACIONSINCRONO_H

#include <QDialog>              // Ten cuidado al ir a LINUX

#include <graficador.h>
#include <motorinduccion.h>
#include <sistemacontrol.h>

#include <stdlib.h>

class QLabel;
class QLineEdit;
class QPushButton;

class DialogoAlimentacionSincrono : public QDialog
{
    Q_OBJECT

public:
    DialogoAlimentacionSincrono(MotorInduccion * miMotor);

private slots:
    void botonAceptarClicked();
    void botonGenerarClicked();

private:
    QLabel * etiquetaAmplitud;
    QLabel * etiquetaFrecuencia;

    QLineEdit * datoAmplitud;
    QLineEdit * datoFrecuencia;

    QPushButton * aceptar;
    QPushButton * verGrafica;

    MotorInduccion * elMotor;
};

#endif // DIALOGOALIMENTACIONSINCRONO_H
