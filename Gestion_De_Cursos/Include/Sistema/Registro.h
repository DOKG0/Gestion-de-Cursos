#ifndef REGISTRO_H
#define REGISTRO_H

class Leccion;

#include "../Datatypes/Enum.h"
#include "../ico.h"
#include "Curso/Curso.h"
#include "ctime"
#include "Usuario/Estudiante.h"
#include "Curso/Ejercicio.h"
#include "Curso/CompletarPalabras.h"
#include "Curso/Traduccion.h"

class Registro: public ICollectible{

    private:
       Date FechaRegistro;
       double PorcentajeAprobacion;
       Curso * curso;
       Estudiante * estudiante; //
       IDictionary * EjerciciosAprobados = new OrderedDictionary();
       IDictionary * LeccionesAprobadas = new OrderedDictionary();

    public:
        Registro();
        ~Registro();
        //setters&getters
        Date getFechaRegistro();
        void setFechaRegistro(Date fecha);

        double getPorcentajeAprobacion();
        void setPorcentajeAprobacion(double porcentaje);
        //
        void calcularPorcentajeAprobacion(int totalEjerciciosCurso);
        IDictionary * getEjerciciosAprobados();
        IDictionary * getLeccionesAprobadas();
        //
        Curso * getCurso();
        void setCurso(Curso * curso);
        //
        Estudiante * getEstudiante();
        void setEstudiante(Estudiante * e);
        //
        void agregarEjercicioAprobado(Ejercicio * ejercicio);
        void agregarLeccionAprobada(Leccion * leccion);
        bool esLeccionAprobada(std::string tema);
        //
        bool esEjercicioAprobado(Ejercicio* ejercicio);
        //del
        void eliminarRegistrodeCurso(Registro * r);

};


#endif