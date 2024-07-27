#include "DataLeccion.h"


DataLeccion::DataLeccion(){}

DataLeccion::DataLeccion(std::string Tema, std::string Objetivo){
    this->Tema = Tema;
    this->Objetivo = Objetivo;
}

DataLeccion::DataLeccion(std::string Tema, std::string Objetivo, IDictionary * ejerciciosleccion){
    this->Tema = Tema;
    this->Objetivo = Objetivo;
    this->ejerciciosleccion = ejerciciosleccion;
}

std::string DataLeccion::getTema(){
    return this->Tema;
}

std::string DataLeccion::getObjetivo(){
    return this->Objetivo;
}

IDictionary * DataLeccion::getEjerciciosLeccion(){
    return this->ejerciciosleccion;
}
