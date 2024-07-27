#ifndef CURSO_H
#define CURSO_H

class Profesor;
class Estudiante;
class Registro;
#include "../Registro.h"
#include <string>
#include "../../ico.h"
#include "../../Datatypes/Enum.h"
#include "Idioma.h"
#include "Leccion.h"



class Curso: public ICollectible{
    private:
        std::string NombreCurso;
        std::string DescripcionCurso;
        TipoDificultad Dificultad;
        bool Habilitado;
        Idioma * idiomaCurso = nullptr;
        Profesor * profesorCurso = nullptr;
        IDictionary * CursosPrevios = new OrderedDictionary();
        IDictionary * leccionesCurso = new OrderedDictionary();
        IDictionary * estudiantesCurso = new OrderedDictionary();
        IDictionary * registrosInscripcion = new OrderedDictionary();

    
    public:
        Curso();
        Curso(std::string NombreCurso, std::string DescripcionCurso, TipoDificultad Dificultad);
        ~Curso();
        //setter & getter local
        void setNombreCurso(std::string NombreCurso);
        void setDescripcionCurso(std::string DescripcionCurso);
        void setDificultad(TipoDificultad Dificultad);
        void setHabilitado(bool Habilitado);
        std::string getNombreCurso();
        std::string getDescripcionCurso();
        TipoDificultad getDificultad();
        bool getHabilitado();
        void setIdioma(Idioma * idiomaCurso);
        //
        void AgregarIdiomaCurso(Idioma * i);
        std::string GetIdiomaCurso();
        //
        void setProfesorCurso(Profesor * p);
        std::string getProfesorCurso();
        //
        IDictionary * getLecciones();
        void AgregarLeccionCurso(Leccion * l);
        //
        void AgregarCursoPrevioCurso(Curso * c);
        IDictionary * getCursosPreviosCurso();
        bool TieneLeccionConEjercicios();
        //estudiante inscribir
        void agregarEstudiante(Estudiante * e);
        int getCantidadLecciones();
        //
        void agregarRegistroInscripcion(Registro * registro);
        IDictionary * getRegistroInscripcion();
        //
        int getTotalEejercicios();
        //12
        Leccion* ultimaLeccionNoAprobada(Estudiante * estudiante, std::string nombrecurso);
        Leccion* ObtenerLeccion(std::string tema);
        //
        IDictionary * getEst();
        //eliminarleccion
        void EliminarLecciones();


};

#endif