#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H
#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include "espaciotrabajo.h"
using namespace std;

class SistemaOperativo
{
public:
    SistemaOperativo();
    void correr();
    int obtenerOpcionImagenes(int num_carpeta);
    int obtenerOpcionCarpetas();

};

#endif // SISTEMAOPERATIVO_H
