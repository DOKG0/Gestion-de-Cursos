#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>
#include "../../ico.h"

class Idioma: public ICollectible{
    private:
        std::string NombreIdioma;
    public:
        Idioma(std::string NombreIdioma);
        //setter & getter
        void setNombreIdioma(std::string NombreIdioma);
        std::string getNombreIdioma();
};

#endif