#include <iostream>
#include <string>
#include "Menu/Menu.h"

int main(){

    int op = 0;
    do{
        op = obteneropcionMenu();

        switch (op){
		case 1:
			//Alta Usuario
			AltaUsuario();
			break;

		case 2:
			//Consultar Usuarios
            ConsultaUsuarios();
			break;

		case 3:
			//Alta Idioma
			AltaIdioma();
			break;

		case 4:
			//Consultar Idiomas
			ConsultarIdiomas();
			break;

		case 5:
			//Alta Curso
			AltaCurso();
			break;

		case 6:
			//Agregar Leccion
			AgregarLeccion();
			break;

		case 7:
			//Agregar Ejercicio
			AgregarEjercicio();
			break;

		case 8:
			//Habilitar Curso
			HabilitarCurso();
			break;
		
		case 9:
			//EliminarCurso
			EliminarCurso();
			break;

		case 10:
			//Consultar Curso
			ConsultarCurso();
			break;
			
		case 11:
			//Inscribirse a Curso
			InscribirseACurso();
			break;
		
		case 12:
			//Realizar Ejercicio
			RealizarEjercicio();
			break;

		case 13:
			//ConsultarEstadisticas
			ConsultarEstadisticas();
			break;

		case 14:
            //Pre-Cargar datos en el sistema
            CargarDatos();
			break;
        
		case 15:
			//Salir del sistema
            salirSistema();
			break;
        }
    }while (op != 15);

    return 0;
}