#include "DataEstudiante.h"


DataEstudiante::DataEstudiante(){}

DataEstudiante::DataEstudiante(std::string Nickname, std::string Pais, Date FechaNac){
    this->Nickname = Nickname;
    this->Pais = Pais;
    this->FechaNac = FechaNac;
}

DataEstudiante::DataEstudiante(std::string Nickname, std::string Descripcion, std::string Pais, Date FechaNac){
    this->Nickname = Nickname;
    this->Descripcion = Descripcion;
    this->Pais = Pais;
    this->FechaNac = FechaNac;
}

DataEstudiante::DataEstudiante(std::string Nickname, std::string Descripcion, std::string Pais, Date FechaNac , IDictionary * cursosInscripto){
    this->Nickname = Nickname;
    this->Descripcion = Descripcion;
    this->Pais = Pais;
    this->FechaNac = FechaNac;
    this->cursosInscripto = cursosInscripto;
}

std::string DataEstudiante::getNickname(){
    return this->Nickname;
}

std::string DataEstudiante::getDescripcion(){
    return this->Descripcion;
}

std::string DataEstudiante::getPais() {
    return this->Pais;
}

Date DataEstudiante::getFechaNac() {
    return this->FechaNac;
}

IDictionary * DataEstudiante::getCursosInscriptoDT(){
    if(cursosInscripto == nullptr){
        std::cout << "N/A" << std::endl;
    }else{
        return this->cursosInscripto;
    }
}