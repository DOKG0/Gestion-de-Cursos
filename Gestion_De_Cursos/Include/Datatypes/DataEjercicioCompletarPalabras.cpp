#include "DataEjercicioCompletarPalabras.h"

DataEjercicioCompletarPalabras::DataEjercicioCompletarPalabras(std::string Frase, std::string descripcion,  std::string Palabras){
    this->Frase = Frase;
    this->Palabras = Palabras;
    this->Descripcion = descripcion;
}

std::string DataEjercicioCompletarPalabras::getFrase(){
    return this->Frase;
}

std::string DataEjercicioCompletarPalabras::getDescripcion(){
    return this->Descripcion;
}

std::string DataEjercicioCompletarPalabras::getPalabras(){
    return this->Palabras;
}
