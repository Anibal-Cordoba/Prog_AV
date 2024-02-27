#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H
#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include "espaciotrabajo.h"
#include "imagen.h"
#include "gestorpnm.h"
#include "ventanadegraficacion.h"
using namespace std;

class SistemaOperativo
{
public:
    SistemaOperativo();
    void correr(QApplication *app);
    int obtenerOpcionImagenes(int num_carpeta);
    int obtenerOpcionCarpetas();
private:
    EspacioTrabajo espaciodetrabajo;
    //VentanaDeGraficacion ventanadegraficacion;
    QApplication* qAppl;
};

#endif // SISTEMAOPERATIVO_H
