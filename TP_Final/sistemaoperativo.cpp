#include "sistemaoperativo.h"


SistemaOperativo::SistemaOperativo()
{

}

void SistemaOperativo::correr()
{
    int opcionCarpeta = obtenerOpcionCarpetas();
    int opcionImagen = obtenerOpcionImagenes(opcionCarpeta);
    //llamar al visualizador
}
//un metodo obtener opciones que integre las dos facilitando despues mi clase sistema.
int SistemaOperativo::obtenerOpcionImagenes(int num_carpeta)
{
   // system("cls");//para limpiar la consola {que el otro limpie mi mierda}


    int opcion;

    EspacioTrabajo espaciodetrabajo;
    vector<string> imagen = espaciodetrabajo.devolverImagenes(num_carpeta);


    cout<<"Elija la imagen a la que desea ingresar:"<<endl;
    for (unsigned int i=0;i<imagen.size();i++){
        cout<< i+1 <<". "<< imagen[i]<<endl;
    }
    cin>> opcion;
    return opcion;


}

int SistemaOperativo::obtenerOpcionCarpetas()
{
    system("cls");

    EspacioTrabajo espaciodetrabajo;
    vector<string> carpeta = espaciodetrabajo.devolverCarpetas();
    int opcion;

    cout<<"Elija la carpeta a la que desea ingresar:"<<endl;
    for (unsigned int i=0;i<carpeta.size();i++){
        cout<< i+1 <<". "<< carpeta[i]<<endl;
    }

    cin>> opcion;
    return opcion;
}


