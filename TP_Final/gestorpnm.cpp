#include "gestorpnm.h"

GestorPNM::GestorPNM()
{

}

Imagen GestorPNM::leer(string ruta)
{
    Imagen img;
    string identificador,comentario="",linea;
    int c,f,rango;
    int posicion;

    ifstream archivo;
    archivo.open(ruta);

    archivo>>identificador;

    while (getline(archivo,linea))
    {
        if (linea[0]!= '#')
        {
            stringstream ss(linea);//hace como que estas leyendo el archivo
            ss >> c >>f;
            break;
        }
        comentario = comentario + linea;
    }
    if (identificador != "P1" and identificador != "P4")
    {
    archivo>>rango;
    }
    else (rango = 1);

    posicion = archivo.tellg();
    archivo.close();

    img.setFila(f);
    img.setColumna(c);
    img.setRango(rango);
    img.setComentario(comentario);
    img.setIdentificador(identificador);

    string todavianose;
    unsigned char pixelbin;
    unsigned char rojo,verde,azul;
    Pixel auxPixel;
    switch (identificador[1])
    {
        case '1':
            todavianose;
            //img monocrom y pixeles como texto;
        case '2':
            archivo.open(ruta);
            archivo.seekg(posicion);
            int nivelGris;
            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo>>nivelGris;
                    auxPixel.setRGB(nivelGris,nivelGris,nivelGris);
                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();
        case '3':
            todavianose;
        case '4':
            todavianose;
        case '5':
            archivo.open(ruta,ios::binary);
            archivo.seekg(posicion);

            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo.read((char*)&pixelbin, sizeof(pixelbin));

                    auxPixel.setRGB((int)pixelbin,(int)pixelbin,(int)pixelbin);
                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();

        case '6':
            archivo.open(ruta,ios::binary);
            archivo.seekg(posicion);

            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo.read((char*)&rojo, sizeof(pixelbin));
                    archivo.read((char*)&verde, sizeof(pixelbin));
                    archivo.read((char*)&azul, sizeof(pixelbin));

                    auxPixel.setRGB((int)rojo,(int)verde,(int)azul);
                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();




    return img;


}
