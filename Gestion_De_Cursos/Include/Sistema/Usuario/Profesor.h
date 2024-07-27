#ifndef PROFESOR_H
#define PROFESOR_H

#include "../Curso/Curso.h"
#include <string>
#include "Usuario.h"
#include "../../ico.h"
#include "../../Datatypes/Datatypes.h"
#include "../Curso/Idioma.h"




class Profesor: public Usuario{
    private:

        std::string Instituto;
        //coleccion idiomas en los que se especializa el profesor
        IDictionary * idiomasprofesor = new OrderedDictionary();
        //coleccion de cursos que dicta el profesor
        IDictionary * CursosProfesor = new OrderedDictionary();

    public:

        Profesor(std::string Nickname,std::string Nombre, std::string Descripcion,std::string Contrasenia, std::string Instituto);
        //Operaciones padre
        void setNickname(std::string);
        void setContrasenia(std::string);
        void setDescripcion(std::string);
        std::string getNickname();
        std::string getContrasenia();
        std::string getDescripcion();
        std::string getNombre();
        //setter & getter local
        void setInstituo(std::string Instituto);
        std::string getInstituto();
        //agregar idioma al profesor
        void AgregarIdiomaProfesor(Idioma * i);
        IDictionary * getIdiomasProfesor();
        //agregar curso al profesor
        void AgregarCursoProfesor(Curso * c);
        IDictionary * getCursosProfesor();
};

#endif