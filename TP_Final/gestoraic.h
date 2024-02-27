#ifndef GESTORAIC_H
#define GESTORAIC_H
#include "gestordearchivos.h"

class GestorAIC: public GestorDeArchivos
{
public:
    GestorAIC();
    Imagen leer(string ruta) override;
};

#endif // GESTORAIC_H
