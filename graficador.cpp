#include "graficador.h"
#include "ui_graficador.h"

Graficador::Graficador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graficador)
{
    ui->setupUi(this);
    nombreGrafica = "Por defecto";

    setWindowTitle(nombreGrafica);
    ui->grafica->yAxis->setLabel("Ordenada");
    ui->grafica->xAxis->setLabel("Tiempo t[s]");

    // El rango por defecto será
    rangoX[0]=0;
    rangoX[1]=12;
    rangoY[0]=0;
    rangoY[1]=12;    
    ui->grafica->xAxis->setRange(rangoX[0],rangoX[1]);
    ui->grafica->yAxis->setRange(rangoY[0],rangoY[1]);

    // Parámetros por defecto:
    multiplicador = 1;
    tiempoMuestreo = 1;
    contador=0;

    // Se agrega por defecto la primera gráfica
    ui->grafica->addGraph();

    ui->grafica->replot();
}

Graficador::~Graficador()
{
    delete ui;

}

void Graficador::EtiquetaX(QString labelX)
{
    ui->grafica->xAxis->setLabel(labelX);
}

void Graficador::EtiquetaY(QString labelY)
{
    ui->grafica->yAxis->setLabel(labelY);
}

void Graficador::EliminarPuntos()
{
    //this->clearMask();
}

void Graficador::mostrar()
{
    //Se oculta la gráfica y se re grafica:
    ui->grafica->hide();
    ui->grafica->replot();
}

void Graficador::ocultar()
{
    //Se oculta la gráfica:
    ui->grafica->hide();
}

void Graficador::agregarPunto(double time,double value)
{
    /******************************************************Qt************************************************************************/
    // Se crea un vector momentaneo para agregar un punto, el graficador no tiene menoria
    QVector<double> x(1), y(1);
    x[0] = time;
    y[0] = multiplicador*value;

    if(time>rangoX[1])
    {
        rangoX[1]=1.2*time;
        ui->grafica->xAxis->setRange(rangoX[0],rangoX[1]);
    }

    if(multiplicador*value>rangoY[1])
    {
        rangoY[1]=1.2*multiplicador*value;
        ui->grafica->yAxis->setRange(rangoY[0],rangoY[1]);
    }

    ui->grafica->graph(0)->addData(x,y);
}

void Graficador::agregarPunto(double value)
{
    /******************************************************Qt************************************************************************/
    // Se crea un vector momentaneo para agregar un punto, el graficador no tiene menoria
    QVector<double> x(1), y(1);
    x[0] = ((double)contador)*tiempoMuestreo;
    y[0] = multiplicador*value;

    if(((double)contador)*tiempoMuestreo>rangoX[1])
    {
        rangoX[1]=1.2*((double)contador)*tiempoMuestreo;
        ui->grafica->xAxis->setRange(rangoX[0],rangoX[1]);
    }

    if(multiplicador*value>rangoY[1])
    {
        rangoY[1]=1.2*multiplicador*value;
        ui->grafica->yAxis->setRange(rangoY[0],rangoY[1]);
    }

    contador++;
    ui->grafica->graph(0)->addData(x,y);
}

void Graficador::setMultiplicador(double multiplier)
{
    multiplicador=multiplier;
}

double Graficador::getMultiplicador()
{
    return multiplicador;
}

void Graficador::setTiempoMuestreo(double sampleTime)
{
    tiempoMuestreo = sampleTime;
}

double Graficador::getTiempoMuestreo()
{
    return tiempoMuestreo;
}

void Graficador::setNombre(QString graphName)
{
    nombreGrafica = graphName;
    setWindowTitle(nombreGrafica);
}

void Graficador::setRangoX(double x0, double x1)
{
    rangoX[0]=x0;
    rangoX[1]=x1;
    ui->grafica->xAxis->setRange(rangoX[0],rangoX[1]);
}

void Graficador::setRangoY(double y0, double y1)
{
    rangoY[0]=y0;
    rangoY[1]=y1;
    ui->grafica->yAxis->setRange(y0,y1);
}
