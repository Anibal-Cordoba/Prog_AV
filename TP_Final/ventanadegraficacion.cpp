#include "ventanadegraficacion.h"
#include <iostream>
#include <QOpenGLFunctions>

using namespace std;

VentanaDeGraficacion::VentanaDeGraficacion()
{

}

//void VentanaDeGraficacion::cargarImagen(Imagen imagen_pasada)
//{
//    imagen = imagen_pasada;
//}


void VentanaDeGraficacion::keyPressEvent(QKeyEvent *event)
{
    //bool flecha_derecha = event->key() == Qt::Key_Right;
    //bool ctrl = event->modifiers() & Qt::ControlModifier;


    //leer lo del control
    if (event->key() == Qt::Key_Right and (event->modifiers() and Qt::ControlModifier))
    {
        EspacioTrabajo  espacioTrabajo;

        opcionImagen++;
        if (opcionImagen>(espacioTrabajo.cantidadImagenes(opcionCarpeta)))
            opcionImagen=1;


        cargarImagen(opcionCarpeta,opcionImagen);
        repaint();
    }
    if (event->key() == Qt::Key_Left and (event->modifiers() and Qt::ControlModifier))
    {
        EspacioTrabajo  espacioTrabajo;

        opcionImagen--;
        if (opcionImagen<1)
            opcionImagen=(espacioTrabajo.cantidadImagenes(opcionCarpeta));


        cargarImagen(opcionCarpeta,opcionImagen);
        repaint();
    }
}
void VentanaDeGraficacion::cargarImagen(int n_opcionCarpeta , int n_opcionImagen)
{
    //colaboraciones:
    GestorDeArchivos* archivo;
    EspacioTrabajo  espacioTrabajo;

    opcionCarpeta = n_opcionCarpeta;
    opcionImagen = n_opcionImagen;
    string ruta = espacioTrabajo.devolverRuta(opcionImagen, opcionCarpeta);
    cout<<endl<<ruta<<endl;
    system("cls");



    //
    string extension = espacioTrabajo.leerExtension(ruta);
    if (extension == "pnm" )
        archivo = new GestorPNM;
    else if (extension == "aic")
        archivo = new GestorAIC;
    else
        cout<<"tengo que levantar un error"<<endl;

    imagen = archivo->leer(ruta);


}
void VentanaDeGraficacion::initializeGL()
{
    initializeOpenGLFunctions();
    // Se define el color del fondo para los lugares en que no se grafica
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void VentanaDeGraficacion::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Relación entre pixeles_ventana/metros_imagen (para el alto y el ancho)
    float relAncho = ((float)width())  / ((float)imagen.getColumna());
    float relAlto  = ((float)height()) / ((float)imagen.getFila());

    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    // Probar comentando y descomentando el siguiente cálculo: //relacion de aspecto RESPETO RELACION DE ASPECTO DE IMAGEN ORIGINAL
    if(relAncho < relAlto)
    {
        escala = relAncho;  // se establece la MENOR.
        desply = (height() - imagen.getFila()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - imagen.getColumna()*escala)*0.5f;
    }
    GraficarImagen();
}

void VentanaDeGraficacion::resizeGL(int ancho, int alto)
{
    anch=ancho;
    alt=alto;
        //
    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        //dejar -1,1
//    glOrtho(0, imagen.getColumna(), 0  , imagen.getFila(), -1, 1);
    glOrtho(0, width(), 0, height(), -1, 1); //Al poner esto creo que la relación queda con respecto al ancho de la ventana y el alto. Además permite que el paintgl tenga bien hecho y ande el reescalado con respecto a la reación de aspecto.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void VentanaDeGraficacion::GraficarImagen()
{
    int fila, columna;
    Pixel pixelaux;

    glPushMatrix();
    glTranslatef(desplx, desply, 0.0f);
    glScalef(escala, escala, 1.0f);

    // Graficación de pixeles
    glBegin(GL_QUADS);
    for (fila = 0;fila<imagen.getFila();fila++)
    {
        for (columna = 0;columna<imagen.getColumna() ;columna++)
        {
            pixelaux = imagen.getPixel(fila,columna);
            //Que tanto de cada color depende del rango, no todas las imagenes tienen el mismo rango
            glColor3f((float)pixelaux.getRojo()/imagen.getRango(),
                      (float)pixelaux.getVerde()/imagen.getRango(),
                      (float)pixelaux.getAzul()/imagen.getRango());

            if ((fila==1) and (columna<4)){
            cout<<"oGL: "<<fila<<" "<<columna<<pixelaux<<endl;}

            //Ahora escribimos los 4 vertices del pixel en el plano
//            int x = columna;
//            int y = imagen.getFila();

//            glVertex2i(x, y-fila);
//            glVertex2i(x, y -(fila+1));
//            glVertex2i(x + 1, y -(fila+1));
//            glVertex2i(x + 1, y-fila);

            glVertex3i(columna, imagen.getFila()-fila, 0);
            glVertex3i(columna, imagen.getFila()-(fila+1), 0);
            glVertex3i(columna+1, imagen.getFila()-(fila+1), 0);
            glVertex3i(columna+1, imagen.getFila()-fila, 0);

//            int y = imagen.getFila() - fila - 1; //invertido el eje y para que el origen este en la esquina izq . Lo que pasa es que opengl dibuja de la fila 0 para arrba y nosotros ponemos la imagen fila 0 como de arriba a abajo.
//            glVertex2i(x, y);
//            glVertex2i(x, y + 1);
//            glVertex2i(x + 1, y + 1);
//            glVertex2i(x + 1, y);

        }
    }

    glEnd();

    glPopMatrix();

//    update(); Esto es mejor si va cambiando la imagen
}
