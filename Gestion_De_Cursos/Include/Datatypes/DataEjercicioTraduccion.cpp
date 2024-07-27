#include "DataEjercicioTraduccion.h"

DataEjercicioTraduccion::DataEjercicioTraduccion(std::string Frase, std::string descripcion, std::string FraseCorrectaT){
    this->Frase = Frase;
    this->FraseCorrectaT = FraseCorrectaT;
    this->Descripcion = descripcion;
}

std::string DataEjercicioTraduccion::getFrase(){
    return this->Frase;
}

std::string DataEjercicioTraduccion::getDescripcion(){
    return this->Descripcion;
}

std::string DataEjercicioTraduccion::getFraseCorrecta(){
    return this->FraseCorrectaT;
}