#include "Idioma.h"

Idioma::Idioma(std::string NombreIdioma){
    this->NombreIdioma = NombreIdioma;
}

//getter  & setter

void Idioma::setNombreIdioma(std::string NombreIdioma){
    this->NombreIdioma = NombreIdioma;
}

std::string Idioma::getNombreIdioma(){
    return NombreIdioma;
}
