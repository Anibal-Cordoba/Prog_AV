#include <QCoreApplication>
#include "sistemaoperativo.h"
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SistemaOperativo sistema;
    sistema.correr();
    return a.exec();
}
