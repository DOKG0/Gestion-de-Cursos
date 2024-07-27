#include "Traduccion.h"


Traduccion::Traduccion(int contador, std::string Frase, std::string descripcion, std::string FraseCorrectaT){
    this->Frase = Frase;
    this->FraseCorrectaT = FraseCorrectaT;
    this->Descripcion = descripcion;
    this->contador = contador;
}

//Operaciones Padre

void Traduccion::setFrase(std::string Frase){
    this->Frase = Frase;
}

std::string Traduccion::getFrase(){
    return this->Frase;
}

std::string Traduccion::getDescripcion(){
    return this->Descripcion;
}
//setter  & getter

void Traduccion::setFraseCorrecta(std::string FraseCorrectaT){
    this->FraseCorrectaT = FraseCorrectaT;
}

std::string Traduccion::getFraseCorrecta(){
    return this->FraseCorrectaT;
}

int Traduccion::getContador(){
    return this->contador;
}

bool Traduccion::getAprobado(){
    return this->aprobado;
}

void Traduccion::setAprobado(bool aprob){
    this->aprobado = aprob;
}