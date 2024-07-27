#ifndef HANDLERIDIOMA_H
#define HANDLERIDIOMA_H

#include "../ico.h"
#include "Curso/Idioma.h"
#include <string>

class HandlerIdioma{
    private:
        static HandlerIdioma * instancia;
        IDictionary * idiomash;
        HandlerIdioma();
        
    public:
        
        static HandlerIdioma * getInstance();
        ~HandlerIdioma();
        IDictionary * getIdiomasH();
        void AltaIdioma(std::string idioma);
        IDictionary * ListarIdiomas();
        Idioma * ObtenerIdiomaPorNombre(std::string nombreidioma);
};

#endif