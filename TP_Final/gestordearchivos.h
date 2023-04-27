#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include "imagen.h"
#include <string>

class GestordeArchivos
{
public:
    //pnm y aic
    virtual Imagen leer(string ruta) = 0;
};

#endif // GESTORDEARCHIVOS_H
