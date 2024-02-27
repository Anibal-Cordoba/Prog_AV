#ifndef PIXEL_H
#define PIXEL_H
#include <algorithm>
#include <iostream>
using namespace std;

class Pixel
{
    public:
        Pixel();
        //getter para despues graficarlo
        int getRojo();
        int getVerde();
        int getAzul();
        //setter para al leer pasarle los valores
        /*
        void establecerRojo(int intensidadRojo);
        void establecerVerde(int intensidadVerde);
        void establecerAzul(int intensidadAzul);
        */
        //Como se que por convencion es rgb puedo hacer que setee todos los parametros a la vez.
        void setRGB (int intensidadRojo, int intensidadVerde, int intensidadAzul);



    private:
        //Aca paso como atributo los colores del rgb que me permiten formar la imagen
        int rojo;
        int verde;
        int azul;

};
ostream& operator<<(ostream& out, Pixel p_pixel);
#endif // PIXEL_H
