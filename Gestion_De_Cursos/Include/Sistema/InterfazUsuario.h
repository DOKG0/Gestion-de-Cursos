#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include <iostream>
#include <string>
#include "../Datatypes/Enum.h"
#include "../Datatypes/Datatypes.h"
#include "Usuario/Profesor.h"
#include "Usuario/Estudiante.h"
#include "ControladorUsuario.h"

class InterfazUsuario{
    
    public:
        // 1 - Alta Usuario
        virtual void ConfirmarAltaEstudiante(std::string nickname, std::string nombre, std::string descripcion, std::string contrasenia, std::string pais, Date fechaNac) = 0;
        virtual void ConfirmarAltaProfesor(std::string nickname, std::string nombre, std::string descripcion, std::string contrasenia, std::string instituto) = 0;
        virtual void AgregarIdioma(std::string nombreidioma) = 0;
        virtual bool ExisteEstudiante(std::string nickname) = 0;
        virtual bool ExisteProfesor(std::string nickname) = 0;
        virtual bool IdiomaPerteneceAProfesor(std::string nicknameProfesor, std::string nombreIdioma) = 0;
        virtual Estudiante * ObtenerEstudiante(std::string nickname) = 0;
        virtual Profesor * ObtenerProfesor(std::string nickname) = 0;
        virtual void SetProfesorActual(Profesor* profesor) = 0;
        virtual void SetEstudianteActual(Estudiante* estudiante) = 0;
        // 2 - Consulta Usuario
        virtual IDictionary * ObtenerUsuarios() = 0;
        virtual DataUsuario * InformacionUsuario(std::string nickname) = 0;
        // 5 - Alta Curso
        virtual IDictionary* ListarProfesores() = 0;
        // 11 - Inscribir a Curso
        virtual IDictionary* ListarEstudiantes() = 0;
        virtual IDictionary * ListarCursosHabiEstudiantes(std::string nickname) = 0;
        virtual void InscribirCurso(std::string nickname, std::string nombrecurso, Date fechaRegistro) = 0;
        // 12 - Realizar ejercicio
        virtual IDictionary* ListarCursosInscriptoNoAprobados(std::string nickname) = 0;
        virtual void CargarAprobado(std::string nickname, std::string curso, std::string leccion, std::string ejercicio) = 0;
        // 13 - Consultar Estadisticas
        virtual IDictionary * ConsultarEstadisticasEstudiante(std::string nickname) = 0;
        virtual IDictionary* consultarEstadisticasProfesor(std::string nickname) = 0;



};


#endif