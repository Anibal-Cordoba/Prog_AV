#ifndef VENTANADEGRAFICACION_H
#define VENTANADEGRAFICACION_H
#include "imagen.h"
#include <QOpenGLFunctions>
#include <QApplication>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QOpenGLWidget>
#include "gestordearchivos.h"
#include "gestorpnm.h"
#include "gestoraic.h"
#include "espaciotrabajo.h"
#include <QKeyEvent>


class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
    public:
        VentanaDeGraficacion();
        void GraficarImagen();
        //void cargarImagen(Imagen imagen_pasada);
        void cargarImagen(int n_opcionCarpeta, int n_opcionImagen);
    protected:
        virtual void initializeGL();
        virtual void paintGL();
        virtual void resizeGL(int ancho, int alto);

        void keyPressEvent(QKeyEvent *event) override;

    private:
        Imagen imagen;
        int opcionImagen, opcionCarpeta;
        float escala, desplx, desply;
        int anch, alt;


};

#endif // VENTANADEGRAFICACION_H


