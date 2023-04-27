#ifndef S_H
#define S_H
#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
using namespace std;

class InterfazUsuario
{
public:
    InterfazUsuario();

    int obtenerOpcionCarpetas();
    void mostrarNombresImagenes(int num_carpeta);
    void mostrarNombresCarpetas();
};

#endif // S_H
