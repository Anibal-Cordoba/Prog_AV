#include <QCoreApplication>
#include "sistemaoperativo.h"
#include <QMainWindow>
#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SistemaOperativo sistema;
    sistema.correr(&app);
    return app.exec();
}
//hay que ver lo del qapplication que funcione main->so->ventana, en ventana no funca pasandole el parametro asique tengo q hacer un setup
