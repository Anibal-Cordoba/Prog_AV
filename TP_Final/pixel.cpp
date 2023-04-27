#include "pixel.h"


Pixel::Pixel()
{

}

int Pixel::getRojo()
{
    return rojo;
}

int Pixel::getVerde()
{
    return verde;
}

int Pixel::getAzul()
{
    return azul;
}



void Pixel::setRGB(int intensidadRojo, int intensidadVerde, int intensidadAzul)
{
        rojo = intensidadRojo;
        verde = intensidadVerde;
        azul = intensidadAzul;

}
/*
void Pixel::establecerRojo(int intensidadRojo)
{
    rojo = intensidadRojo;
}

void Pixel::establecerVerde(int intensidadVerde)
{
    verde = intensidadVerde;
}

void Pixel::establecerAzul(int intensidadAzul)
{
    azul = intensidadAzul;
}
*/
