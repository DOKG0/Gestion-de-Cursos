#ifndef TRADUCCION_H
#define TRADUCCION_H

#include "Ejercicio.h"
#include <string>

class Traduccion: public Ejercicio{
    private:
        std::string FraseCorrectaT;
    public:
        Traduccion(int contador, std::string Frase, std::string descripcion, std::string FraseCorrectaT);
        //Operaciones Padre
        void setFrase(std::string);
        std::string getFrase();
        std::string getDescripcion();
        //setter & getter
        std::string getFraseCorrecta();
        void setFraseCorrecta(std::string FraseCorrectaT);
        int getContador();
        bool getAprobado();
        void setAprobado(bool aprob);
        
};

#endif