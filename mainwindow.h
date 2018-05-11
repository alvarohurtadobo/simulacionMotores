#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graficador.h>
#include <motorinduccion.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Graficador * miGrafica;
    Graficador * alimentacion;
    MotorInduccion miMotor;

};

#endif // MAINWINDOW_H
