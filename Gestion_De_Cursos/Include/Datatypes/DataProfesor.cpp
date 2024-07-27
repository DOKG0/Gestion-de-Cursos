#include "DataProfesor.h"

DataProfesor::DataProfesor(){}

DataProfesor::DataProfesor(std::string Nickname, std::string Instituto){
    this->Nickname = Nickname;
    this->Instituto = Instituto;
}

DataProfesor::DataProfesor(std::string Nickname, std::string Descripcion, std::string Instituto){
    this->Nickname = Nickname;
    this->Descripcion = Descripcion;
    this->Instituto = Instituto;
}

DataProfesor::DataProfesor(std::string Nickname, std::string Descripcion, std::string Instituto, IDictionary * idiomasprofesor){
    this->Nickname = Nickname;
    this->Descripcion = Descripcion;
    this->Instituto = Instituto;
    this->idiomasprofesor = idiomasprofesor;
}

std::string DataProfesor::getInstituto(){
    return this->Instituto;
}

std::string DataProfesor::getNickname(){
    return this->Nickname;
}

std::string DataProfesor::getDescripcion(){
    return this->Descripcion;
}

//
DataEstadisticaProfesor::DataEstadisticaProfesor(const std::string& nombreCurso, double promedioAvance, TipoDificultad dificultadCurso, std::string descripcionCurso){
    this->nombreCurso = nombreCurso;
    this->promedioAvance = promedioAvance;
    this->descripcionCurso = descripcionCurso;
    this->dificultadCurso = dificultadCurso;
}
std::string DataEstadisticaProfesor::getNombreCurso() const{
    return this->nombreCurso;
}
double DataEstadisticaProfesor::getPromedioAvance() const{
    return this->promedioAvance;
}

std::string DataEstadisticaProfesor::getDescripcion(){
    return this->descripcionCurso;
}

TipoDificultad DataEstadisticaProfesor::getDificultad(){
    return this->dificultadCurso;
}
