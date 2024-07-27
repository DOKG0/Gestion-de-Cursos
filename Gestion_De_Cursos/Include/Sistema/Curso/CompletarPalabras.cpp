#include "CompletarPalabras.h"


CompletarPalabras::CompletarPalabras(int contador, std::string Frase, std::string descripcion,  std::string Palabras){
    this->Frase = Frase;
    this->Palabras = Palabras;
    this->Descripcion = descripcion;
    this->contador = contador;
}


//Operaciones Padre

void CompletarPalabras::setFrase(std::string Frase){
    this->Frase = Frase;
}

std::string CompletarPalabras::getFrase(){
    return this->Frase;
}

std::string CompletarPalabras::getDescripcion(){
    return this->Descripcion;
}

//Getter & setter local

void CompletarPalabras::setPalabras(std::string Palabras){
    this->Palabras = Palabras;
}

std::string CompletarPalabras::getPalabras(){
    return this->Palabras;
}

int CompletarPalabras::getContador(){
    return this->contador;
}

bool CompletarPalabras::getAprobado(){
    return this->aprobado;
}

void CompletarPalabras::setAprobado(bool aprob){
    this->aprobado = aprob;
}