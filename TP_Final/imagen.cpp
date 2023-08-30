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

void Imagen::setRango(int nRango)
{
    rango = nRango;
}

int Imagen::getRango()
{
    return rango;
}

void Imagen::setComentario(string coment)
{
    comentario = coment;
}

string Imagen::getComent()
{
    return comentario;
}

void Imagen::setIdentificador(string ident)
{
    identificador = ident;
}

string Imagen::getIdentif()
{
    return identificador;
}

void Imagen::setPixel(int fila, int columna, Pixel pixel)
{
    imagen[fila][columna] = pixel;
}

void Imagen::setTamanioImagen(int nFila, int nColumna)
{
    //aca lo que hago es primero hago un vector de la cantidad de columnas y luegoa cada columna le hago un rezise con la cantidad de filas.
    if (nFila != 0 and nColumna != 0){
        imagen.resize(nColumna);
        for (unsigned int i=0; i<imagen.size(); ++i)
        {
            imagen[i].resize(nFila);
        }
    } else
    {
        imagen.resize(columna);
        for (unsigned int i=0; i<imagen.size(); ++i)
        {
            imagen[i].resize(fila);
        }
    }


}
