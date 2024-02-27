#include "gestorpnm.h"

GestorPNM::GestorPNM()
{

}

Imagen GestorPNM::leer(string ruta)
{
    Imagen img;
    string identificador, comentario="", linea;
    int c = 0 ,f = 0 , rango;
    int posicion;

    ifstream archivo;
    archivo.open(ruta);

    //lectura identificador
    getline(archivo, linea);
    identificador = linea;
    //lectura de comentarios
    while (getline(archivo,linea))
    {
        if (linea[0] == '#')
             comentario = comentario + linea;
        else
            break;
    }

    //lectura dimensiones

    cout<<"linea filaColumna:" <<linea<<endl;
    stringstream ss(linea);
    ss >> c >>f;

    cout<<"cantidad de columna**:"<<c<<endl;
    cout<<"cantidad fila**:"<<f<<endl;

    if (identificador != "P1" and identificador != "P4")
    {
        getline(archivo, linea);
        rango = stoi(linea);
    }
    else rango = 1;
    cout<<"rango:"<<rango<<endl;

    //getline(archivo, linea, '\n');

    posicion = archivo.tellg();
    archivo.close();

    img.setFila(f);
    img.setColumna(c);
    img.setRango(rango);
    img.setComentario(comentario);
    img.setIdentificador(identificador);

    img.setTamanioImagen();

    int blancoOnegro;
    unsigned char pixelbin;
    unsigned char rojo,verde,azul;

    Pixel auxPixel;
    switch (identificador[1])
    {
        case '1':
            //“P1”: es un archivo de imagen monocromática y pixeles como texto
            archivo.open(ruta);
            archivo.seekg(posicion);
            //no tiene rangos es solo  0 y 1
            //int blancoOnegro;
            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo>>blancoOnegro;
                    if (blancoOnegro==0)
                        auxPixel.setRGB(1,1,1);
                    else
                        auxPixel.setRGB(0,0,0);


                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();
            break;
        case '2':
            //“P2”: es un archivo de imagen en escala de grises y pixeles como texto
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
            break;
        case '3':
            //“P3”: es un archivo de imagen color RGB y pixeles como texto
            archivo.open(ruta);
            archivo.seekg(posicion);

            int rojo, verde, azul;

            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo>>rojo>>verde>>azul;

                    auxPixel.setRGB(rojo,verde,azul);
                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();


            break;
        case '4':
            //“P4”: es un archivo de imagen monocromática y pixeles en binario
            archivo.open(ruta,ios::binary);
            archivo.seekg(posicion);


            for(int fila = 0; fila<f; fila++)
            {
                for(int columna = 0; columna<c;columna++)
                {
                    archivo.read((char*)&pixelbin, sizeof(pixelbin));


                    if ((int)pixelbin==0)
                        auxPixel.setRGB(1,1,1);
                    else
                        auxPixel.setRGB(0,0,0);


                    img.setPixel(fila,columna,auxPixel);
                }
            }
            archivo.close();
            break;
        case '5':
            //“P5”: es un archivo de imagen en escala de grises y pixeles en binario
            cout<<"entre aca";
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
            break;

        case '6':
            //“P6”: es un archivo de imagen color RGB y pixeles en binario

            archivo.open(ruta,ios::binary);

            //control:
            /*
            cout<<"cantidad de columna:"<<c<<endl;
            cout<<"cantidad fila:"<<f<<endl;
            cout<<"cantidad fila:"<<sizeof(pixelbin)<<endl;
            */

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
            break;

    }
    return img;

}
