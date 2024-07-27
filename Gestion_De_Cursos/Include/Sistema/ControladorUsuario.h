#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "InterfazUsuario.h"
#include "HandlerIdioma.h"
#include "ControladorCurso.h"
#include <string>
#include "../ico.h"
#include "../Datatypes/Enum.h"
#include "Usuario/Usuario.h"
#include "Usuario/Estudiante.h"
#include "Usuario/Profesor.h"
#include "Curso/Idioma.h"
#include "ctime"
#include "../Datatypes/cur.h"


class ControladorUsuario: public InterfazUsuario{

    private:
        static ControladorUsuario *instance;
        ControladorUsuario();
        std::string NicknameUser;
        std::string DescripcionUser;
        std::string ContraseniaUser;

        std::string Pais;
        Date FechaNac;

        std::string Instituto;

        IDictionary* estudiantes;
        IDictionary* profesores;

        //////
        Profesor * profesorActual;
        Estudiante * estudianteActual;
        //////
        
    public:
        static ControladorUsuario* getInstance();

        // 1 - Alta Usuario
        void ConfirmarAltaEstudiante(std::string nickname, std::string nombre, std::string descripcion, std::string contrasenia, std::string pais, Date fechaNac);
        void ConfirmarAltaProfesor(std::string nickname, std::string nombre,std::string descripcion, std::string contrasenia, std::string instituto);
        void AgregarIdioma(std::string nombreidioma);
        bool ExisteEstudiante(std::string nickname);
        bool ExisteProfesor(std::string nickname);
        bool IdiomaPerteneceAProfesor(std::string nicknameProfesor, std::string nombreIdioma);
        Estudiante * ObtenerEstudiante(std::string nickname);
        Profesor * ObtenerProfesor(std::string nickname);
        void SetProfesorActual(Profesor* profesor);
        void SetEstudianteActual(Estudiante* estudiante);
        // 2 - Consulta Usuarios
        IDictionary * ObtenerUsuarios();
        DataUsuario * InformacionUsuario(std::string nickname);
        // 4 - Alta Curso
        IDictionary* ListarProfesores();
        // 11 - Inscribir Usuario
        IDictionary* ListarEstudiantes();
        // Inscribir A curso
        IDictionary * ListarCursosHabiEstudiantes(std::string nickname);
        void InscribirCurso(std::string nickname, std::string nombrecurso, Date fechaRegistro);
        // 12 - Realizar Ejercicio
        IDictionary* ListarCursosInscriptoNoAprobados(std::string nickname);
        void CargarAprobado(std::string nickname, std::string curso, std::string leccion, std::string ejercicio);
        // 13 - Consultar Estadisticas estudiante
        IDictionary * ConsultarEstadisticasEstudiante(std::string nickname);
        IDictionary* consultarEstadisticasProfesor(std::string nickname);
        
        





};

#endif