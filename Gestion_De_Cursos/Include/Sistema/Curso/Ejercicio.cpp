#include "Ejercicio.h"

Ejercicio::Ejercicio(){}

Ejercicio::~Ejercicio(){}

Ejercicio::Ejercicio(int contador, std::string Frase, std::string Descripcion){
    this->Frase = Frase;
    this->Descripcion = Descripcion;
    this->contador = contador;
    this->aprobado = false;
}

//getters & setters

