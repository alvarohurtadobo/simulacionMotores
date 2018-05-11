#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>              // Ten cuidado al ir a LINUX

class QLabel;
class QPushButton;

class About : public QDialog
{
    Q_OBJECT
public:
    About();

private slots:
    void botonAceptarClicked();

private:
    QLabel * etiqueta;
    QPushButton * aceptar;

};

#endif // ABOUT_H
