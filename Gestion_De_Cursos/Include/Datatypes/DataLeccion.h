#ifndef DATALECCION_H
#define DATALECCION_H

#include "../ico.h"
#include <string>

class DataLeccion: public ICollectible{
    private:
        std::string Tema;
        std::string Objetivo;
        IDictionary * ejerciciosleccion = new OrderedDictionary();

    public:
        DataLeccion();
        DataLeccion(std::string Tema, std::string Objetivo);
        DataLeccion(std::string Tema, std::string Objetivo, IDictionary * ejerciciosleccion);

        std::string getTema();
        std::string getObjetivo();
        IDictionary * getEjerciciosLeccion();
};


#endif