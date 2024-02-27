#include "sistemaoperativo.h"


SistemaOperativo::SistemaOperativo(/*QApplication *app*/)
{
//    qAppl = app;
}



void SistemaOperativo::correr(QApplication *app)
{
    while(true)
    {
        int opcionCarpeta = obtenerOpcionCarpetas();
        int opcionImagen = obtenerOpcionImagenes(opcionCarpeta);

        /*
        string ruta = espaciodetrabajo.devolverRuta(opcionImagen, opcionCarpeta);
        cout<<endl<<ruta<<endl;

        system("cls");


        //esto despues es un metodo con el aic
        GestorPNM gestor;
        Imagen imagen = gestor.leer(ruta);
        */

        //llamar al visualizador pasando las opciones
        VentanaDeGraficacion graficador;
        graficador.cargarImagen(opcionCarpeta,opcionImagen);
        graficador.GraficarImagen();
        graficador.show();
        app->exec();
    }
}
//un metodo obtener opciones que integre las dos facilitando despues mi clase sistema.
int SistemaOperativo::obtenerOpcionImagenes(int num_carpeta)
{
    system("cls");//para limpiar la consola {que el otro limpie mi mierda}


    int opcion;

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

    vector<string> carpeta = espaciodetrabajo.devolverCarpetas();
    int opcion;

    cout<<"Elija la carpeta a la que desea ingresar:"<<endl;
    for (unsigned int i=0;i<carpeta.size();i++){
        cout<< i+1 <<". "<< carpeta[i]<<endl;
    }

    cin>> opcion;
    return opcion;
}


