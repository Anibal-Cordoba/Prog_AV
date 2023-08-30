  #ifndef ESPACIOTRABAJO_H
#define ESPACIOTRABAJO_H
#include <vector>
#include <string>
#include <dirent.h>
using namespace std;

class EspacioTrabajo
{
public:
    EspacioTrabajo();
    string devolverRuta(int num_imagen,int num_carpeta); //la ruta apunta a una imagen en una carpeta o directorio
    vector<string> devolverImagenes(int num_carpeta); //una vez que seleccione la capeta esto me devuelve las imagenes dentro de la carpeta
    vector<string> devolverCarpetas(); //me permite que la llame con la interfaz grafica para poder obtener las carpetas que tengo
    string leerExtencion(string ruta);
private:
    vector<string> carpetas = {
        "grupo_imagenes_1",
        "grupo_imagenes_2",
        "grupo_imagenes_3_corruptas",
        "ij_image_samples"
        "imagenes_agregadas"
    };
    string raiz = "./Imagenes/";

};

#endif // ESPACIOTRABAJO_H
