#include <QApplication>
#include "mainwindow.h"
#include <graficador.h>

#include <pantallainicio.h>

#include <motorinduccion.h>
#include <carga.h>
#include <convertidoracdccompleto.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    pantallaInicio inicio;
    inicio.show();

    return a.exec();
}
