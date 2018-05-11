#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QWidget>

namespace Ui {
class Graficador;
}

class Graficador : public QWidget
{
    Q_OBJECT
    
public:
    explicit Graficador(QWidget *parent = 0);
    ~Graficador();

// SETTER's AND GETTER's
    void setMultiplicador(double multiplier);
    double getMultiplicador();
    void setTiempoMuestreo(double sampleTime);
    double getTiempoMuestreo();
    void setNombre(QString graphName);

    void setRangoX(double x0, double x1);
    void setRangoY(double y0, double y1);



    void agregarPunto(double value,double time);
    void agregarPunto(double value);

    void mostrar();
    void ocultar();

    void EtiquetaX(QString labelX);                    // Unica Diferencia
    void EtiquetaY(QString labelY);                    // Unica Diferencia
    void EliminarPuntos();

private:
    Ui::Graficador *ui;
    double rangoX[2];
    double rangoY[2];

    double multiplicador;
    double tiempoMuestreo;
    double contador;

    /*******************************************Qt*********************************************/
    QString nombreGrafica;


};

#endif // GRAFICADOR_H
