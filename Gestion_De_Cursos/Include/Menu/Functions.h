#ifndef FUNCTIONS_H
#define FUNCTIONS_H



#include <string>
#include "../ico.h"
#include "../Datatypes/Enum.h"
#include <cctype>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <algorithm>
#include <ctime>

#include "../Sistema/ControladorCurso.h"
#include "../Sistema/ControladorUsuario.h"
#include "../Sistema/InterfazCurso.h"
#include "../Sistema/InterfazUsuario.h"
#include "../Fabrica/Fabrica.h"


//Funciones utiles

void printTitleInBox(const std::string& title);
void limpiarBuffer();
void pausa(std::string msg);
int obteneropcion();
int obteneropcion2();

void loading(std::string msg);
//Funciones generales

std::string pedirString(std::string msg);
std::string pedirContrasenia(std::string msg);
float pedirFloat(std::string msg);
int pedirInt(std::string msg);
Date pedirFecha(const std::string& mensaje);
std::string dateToString(const Date& date);
std::string obtenerTipoDificultad(TipoDificultad dificultad);
std::string ObtenerBool(bool booleano);
Date ObtenerFechaActual();

#endif