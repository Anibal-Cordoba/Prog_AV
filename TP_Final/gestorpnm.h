#ifndef GESTORPNM_H
#define GESTORPNM_H
#include "gestordearchivos.h"

class GestorPNM: public GestordeArchivos
{
public:
    GestorPNM();
    Imagen leer(string ruta) override;
};

#endif // GESTORPNM_H
