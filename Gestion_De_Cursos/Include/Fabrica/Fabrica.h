#ifndef FABRICA_H
#define FABRICA_H

#include "../Sistema/ControladorCurso.h"
#include "../Sistema/ControladorUsuario.h"
//#include "../Sistema/HandlerIdioma.h"


class Fabrica {
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstance();
        ~Fabrica();
        InterfazCurso *Curso();
        InterfazUsuario *Usuario();  
};
#endif