#include "Profesor.h"
#include <iostream>
#include <string>


Profesor::Profesor(std::string Nickname, std::string Nombre, std::string Descripcion,std::string Contrasenia, std::string Instituto){
    this->Nickname = Nickname;
    this->Contrasenia = Contrasenia;
    this->Descripcion = Descripcion;
    this->Instituto = Instituto;
    this->Nombre = Nombre;
}

//Operaciones Padre

void Profesor::setNickname(std::string Nickname){
    this->Nickname = Nickname;
}

void Profesor::setContrasenia(std::string Contrasenia){
    this->Contrasenia = Contrasenia;
}

void Profesor::setDescripcion(std::string Descripcion){
    this->Descripcion = Descripcion;
}

std::string Profesor::getNickname(){
    return this->Nickname;
}

std::string Profesor::getContrasenia(){
    return this->Contrasenia;
}

std::string Profesor::getDescripcion(){
    return this->Descripcion;
}

std::string Profesor::getNombre(){
    return this->Nombre;
}
//Setter & getter local

void Profesor::setInstituo(std::string Instituto){
    this->Instituto = Instituto;
}

std::string Profesor::getInstituto(){
    return this->Instituto;
}

//Agregar idioma al profesor

void Profesor::AgregarIdiomaProfesor(Idioma * i){
    OrderedKey * key = new String(i->getNombreIdioma().c_str());
    this->idiomasprofesor->add(key,i);
}

IDictionary * Profesor::getIdiomasProfesor(){
    return this->idiomasprofesor;
}

//Agregar cursos al profesor

void Profesor::AgregarCursoProfesor(Curso * c){
    OrderedKey * key = new String(c->getNombreCurso().c_str());
    this->CursosProfesor->add(key,c);
}

IDictionary * Profesor::getCursosProfesor(){
    return this->CursosProfesor;
}