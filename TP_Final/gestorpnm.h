#ifndef GESTORPNM_H
#define GESTORPNM_H
#include "gestordearchivos.h"





class GestorPNM: public GestorDeArchivos
{
public:
    GestorPNM();
    Imagen leer(string ruta) override;
};

#endif // GESTORPNM_H
