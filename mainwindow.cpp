#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
}

void MainWindow::on_pushButton_3_clicked()
{
    alimentacion = new(Graficador);
    alimentacion->setTiempoMuestreo(0.01);

    for(int i = 0; i<630;i++)
    {
        alimentacion->agregarPunto(220*sin(0.01*i));
    }

    alimentacion->setRangoX(0,6.3);
    alimentacion->setRangoY(-300,300);
    alimentacion->show();
    alimentacion->setNombre("Alimentacion");
}

void MainWindow::on_pushButton_clicked()
{

    miGrafica = new(Graficador);
    miGrafica->setTiempoMuestreo(0.001);
    miGrafica->setNombre("Curva Torque Deslizamiento");

    for(int i = 0; i<1000; i++)
    {
        miGrafica->agregarPunto(miMotor.respuestaTorqueDeslizamiento(0.001*i));
    }
    miGrafica->setRangoX(0,1);
    miGrafica->EtiquetaX("Desplazamiento");
    miGrafica->show();

}
