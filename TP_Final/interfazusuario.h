#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H
#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
using namespace std;

class InterfazUsuario
{
public:
    InterfazUsuario();
    int obtenerOpcionImagenes(int num_carpeta);
    int obtenerOpcionCarpetas();
    void mostrarNombresImagenes(int num_carpeta);
    void mostrarNombresCarpetas();
};

#endif // INTERFAZUSUARIO_H
