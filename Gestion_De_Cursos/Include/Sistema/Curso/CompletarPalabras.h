#ifndef COMPLETARPALABRAS_H
#define COMPLETARPALABRAS_H
#include "Ejercicio.h"
#include <string>

class CompletarPalabras: public Ejercicio{
    private:
        std::string Palabras;
    public:
        CompletarPalabras(int contador, std::string Frase, std::string descripcion, std::string Palabras);
        //Operaciones Padre
        void setFrase(std::string);
        std::string getFrase();
        std::string getDescripcion();
        //settr & getter local
        void setPalabras(std::string Palabras);
        std::string getPalabras();
        int getContador();
        bool getAprobado();
        void setAprobado(bool aprob);
};


#endif