#include "imagen.h"
#include <vector>


Imagen::Imagen()
{
}

void Imagen::setFila(int nFila)
{
    filas = nFila;
}

int Imagen::getFila()
{
    return filas;
}

void Imagen::setColumna(int nColumna)
{
    columnas = nColumna;
}

int Imagen::getColumna()
{
    return columnas;
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

void Imagen::setPixel(int p_fila, int p_columna, Pixel p_pixel)
{
    pixeles[p_fila][p_columna] = p_pixel;
}

Pixel Imagen::getPixel(int p_fila, int p_columna)
{
    return pixeles[p_fila][p_columna];
}



void Imagen::setTamanioImagen()
{
    //aca lo que hago es primero hago un vector de la cantidad de fila y luegoa cada columna le hago un rezise con la cantidad de columna.
    //hago un resize para que pueda setear los pixeles, como ya pase f y c la primera parte es para consistencia la segunda es la q se usa
    if (filas != 0 and columnas != 0)
    {
        pixeles.resize(filas);
        for (int i=0; i<filas; ++i)

        {
            pixeles[i].resize(columnas);
        }
    } else//deberia levantar un error si la imagen no tiene dimensiones
    {
        pixeles.resize(1);
        for (int i=0; i<filas; ++i)
        {
            pixeles[i].resize(1);
        }
    }


}
