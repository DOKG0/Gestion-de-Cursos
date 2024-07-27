#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Curso;
class Registro;
#include "../Registro.h"
#include <string>
#include "Usuario.h"

#include "../Curso/Curso.h"
#include "../../ico.h"
//#include "../../Datatypes/Datatypes.h"
#include "../../Datatypes/Enum.h"

class Estudiante: public Usuario{
    private:
        std::string Pais;
        Date FechaNac;
        IDictionary * registros = new OrderedDictionary();
        
    public:
        Estudiante(std::string Nickname, std::string Nombre, std::string Contrasenia, std::string Descripcion, std::string Pais, Date FechaNac);
        Estudiante(std::string Nickname, std::string Descripcion, std::string Pais, Date FechaNac);
        //Operaciones padre
        void setNickname(std::string);
        void setContrasenia(std::string);
        void setDescripcion(std::string);
        std::string getNickname();
        std::string getContrasenia();
        std::string getDescripcion();
        std::string getNombre();
        //setter & getter local
        void setPais(std::string Pais);
        void setFechaNac(Date FechaNac);
        std::string getPais();
        Date getFechaNac();
        bool estaInscripto(std::string nombreCurso);
        bool TienePreviasAprobadas(Curso * curso);
        void agregarRegistro(std::string nombreCurso, Registro * r);
        Registro * getRegistro(std::string nombrecurso);
        bool cursoAprobado(std::string nombreCurso);
        IDictionary * getCursosInscripto();
        IDictionary * getCursosAprobados();
        IDictionary * getCursosNoAprobados();
        //Del
        void eliminarEstudiantedeCurso(Registro * r);
        //
        IDictionary * getRegistro2();
        //13


};

#endif