#ifndef PANTALLAINICIO_H
#define PANTALLAINICIO_H

#include <QDialog>              // Ten cuidado al ir a LINUX

#include <graficador.h>
#include <motorinduccion.h>
#include <sistemacontrol.h>

// Dialog windows:
#include <about.h>
#include <dialogocurvaasincrono.h>

class QLabel;
class QLineEdit;
class QPushButton;

class pantallaInicio : public QDialog
{
    Q_OBJECT

public:
    pantallaInicio();

signals:

private slots:
    void botonAlternaClicked();
    void botonContinuaClicked();
    void botonAceptarClicked();
    void botonCancelarClicked();

private:
    QLabel * miEtiqueta;

    QPushButton * motorAleterna;
    QPushButton * motorContinua;
    QPushButton * botonAceptar;
    QPushButton * botonCancelar;

    About * acercaDe;

    SistemaControl * miSistemaEstudio;
};

#endif // PANTALLAINICIO_H
