#include "imagen.h"
#include <vector>


Imagen::Imagen()
{
}

void Imagen::setFila(int nFila)
{
    fila = nFila;
}

int Imagen::getFila()
{
    return fila;
}

void Imagen::setColumna(int nColumna)
{
    columna = nColumna;
}

int Imagen::getColumna()
{
    return columna;
}

void Imagen::setPixel(int fila, int columna, Pixel pixel)
{
    imagen[fila][columna] = pixel;
}

void Imagen::setTamanioImagen(int fila, int columna)
{
    //aca lo que hago es primero hago un vector de la cantidad de columnas y luegoa cada columna le hago un rezise con la cantidad de filas.
    imagen.resize(columna);
    for (unsigned int i=0; i<imagen.size(); ++i)
    {
        imagen[i].resize(fila);
    }

}
