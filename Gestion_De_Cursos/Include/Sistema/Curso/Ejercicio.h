#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>
#include "../../ico.h"

class Ejercicio: public ICollectible {
    protected:
        std::string Frase;
        std::string Nombre;
        std::string Descripcion;
        int contador;
        bool aprobado = false;
    public:
        Ejercicio();
        Ejercicio(int contador, std::string Frase, std::string Descripcion);
        ~Ejercicio();

        //setter & getters local
        virtual void setFrase(std::string Frase) = 0;
        virtual std::string getFrase() = 0;
        virtual std::string getDescripcion() = 0;
        virtual int getContador() = 0;
        virtual bool getAprobado() = 0;
        virtual void setAprobado(bool aprob) = 0;
};

#endif