#include "espaciotrabajo.h"
#include <iostream>
using namespace std;
EspacioTrabajo::EspacioTrabajo()
{

}

string EspacioTrabajo::devolverRuta(int num_imagen, int num_carpeta)
{
    string imagenSeleccionada = raiz + carpetas[num_carpeta-1] + "/" +  devolverImagenes(num_carpeta).at(num_imagen-1);

    return imagenSeleccionada;
}

vector<string> EspacioTrabajo::devolverImagenes(int num_carpeta)
{
    string carpetaSeleccionada = raiz + carpetas[num_carpeta-1];
    vector<string> imagenes;
    DIR *dir = opendir(carpetaSeleccionada.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                imagenes.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    return imagenes;
}

vector<string> EspacioTrabajo::devolverCarpetas()
{
    return carpetas;
}

string EspacioTrabajo::leerExtencion(string ruta)
{
    string extension,pnm_aic;

    extension = ruta.substr(ruta.length()-3);

    if (extension == "pnm" or extension =="pbm" or extension =="pgm" or extension =="ppm")
    {
        pnm_aic = "pnm";
    }
    else if (extension == "aic")
    {
        pnm_aic = "aic";
    }
//    else: levantar un error


    return extension;
}
