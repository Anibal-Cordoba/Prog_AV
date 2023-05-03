#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include "imagen.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class GestordeArchivos
{
public:
    //pnm y aic
    virtual Imagen leer(string ruta) = 0;
};

#endif // GESTORDEARCHIVOS_H
