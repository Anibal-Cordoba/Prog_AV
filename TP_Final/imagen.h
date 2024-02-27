#ifndef IMAGEN_H
#define IMAGEN_H
#include "pixel.h" //composicion
#include <vector>
#include <string>
using namespace std;

class Imagen
{
    public:
        Imagen();
        //tengo que leer fila y columna para poder hacer mi rezise del vector de vector entonces asi crear mi arreglo con pixeles con datos basura y luego leo y seteo los valores de cada pixel

        void setFila(int nFila);

        int getFila();

        void setColumna(int nColumna);

        int getColumna();

        void setRango(int nRango);

        int getRango();

        void setComentario(string coment);

        string getComent();

        void setIdentificador(string ident);

        string getIdentif();

        void setPixel(int p_fila, int p_columna,Pixel p_pixel);

        Pixel getPixel(int p_fila, int p_columna);

        void setTamanioImagen();

    private:
        int filas, columnas, rango;
        string identificador, comentario;
        vector <vector<Pixel>> pixeles;
};

#endif // IMAGEN_H
