#ifndef DATAEJERCICIOCOMPLETARPALABRAS_H
#define DATAEJERCICIOCOMPLETARPALABRAS_H
#include "DataEjercicio.h"
#include <string>

class DataEjercicioCompletarPalabras: public DataEjercicio{
    private:
        std::string Palabras;       

    public:
        DataEjercicioCompletarPalabras(std::string Frase, std::string descripcion, std::string Palabras);
        std::string getFrase();
        std::string getDescripcion();
        std::string getPalabras();
};

#endif