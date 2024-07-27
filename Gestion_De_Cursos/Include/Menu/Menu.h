#ifndef MENU_H
#define MENU_H


#include <string>
#include "iomanip"
#include <stdlib.h>
#include <cstddef>

#include "../Fabrica/Fabrica.h"
#include "../ico.h"
#include "../Sistema/InterfazCurso.h"
#include "../Sistema/InterfazUsuario.h"
//#include "../Sistema/Curso/Curso.h"
#include "../Sistema/HandlerIdioma.h"
#include "../Datatypes/Datatypes.h"

//Menu
void statusMenu(int opcion);
void mostrarMenu();

int obteneropcionMenu();
void clearBuffer();


//Menu
void AltaUsuario();//1
void ConsultaUsuarios();//2
void AltaIdioma();//3
void ConsultarIdiomas();//4
void AltaCurso();//5
void AgregarLeccion();//6
void AgregarEjercicio();//7
void HabilitarCurso();//8
void EliminarCurso();//9
void ConsultarCurso();//10
void InscribirseACurso();//11
void RealizarEjercicio();//12
void ConsultarEstadisticas();//13
void CargarDatos();//14
void salirSistema();//15




#endif