#include "Fabrica.h"

#include "../Sistema/ControladorCurso.h"
#include "../Sistema/ControladorUsuario.h"
#include "../Sistema/InterfazCurso.h"
#include "../Sistema/InterfazUsuario.h"


Fabrica* Fabrica::instancia = 0;

Fabrica::Fabrica(){}

Fabrica::~Fabrica(){}

Fabrica * Fabrica::getInstance(){
    if(instancia == nullptr){
        instancia = new Fabrica();
    }
    return instancia;
}

//Controlador Usuario

InterfazUsuario * Fabrica::Usuario(){
    return ControladorUsuario::getInstance();
}
//Controlador Curso

InterfazCurso * Fabrica::Curso(){
    return ControladorCurso::getInstance();
}

