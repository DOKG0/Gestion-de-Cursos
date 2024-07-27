#ifndef DATAEJERCICIO_H
#define DATAEJERCICIO_H

#include "../ico.h"


class DataEjercicio: public ICollectible{
    protected:
        std::string Frase;
        std::string Descripcion;
    public:
        DataEjercicio();
        virtual std::string getFrase() = 0;
        virtual std::string getDescripcion() = 0;

};

#endif