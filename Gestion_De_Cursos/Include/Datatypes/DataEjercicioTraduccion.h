#ifndef DATAEJERCICICIOTRADUCCION_H
#define DATAEJERCICICIOTRADUCCION_H

#include "DataEjercicio.h"
#include <string>

class DataEjercicioTraduccion: public DataEjercicio{
    private:
        std::string FraseCorrectaT;
    
    public:
        DataEjercicioTraduccion(std::string Frase, std::string descripcion, std::string FraseCorrectaT);
        std::string getFrase();
        std::string getDescripcion();
        std::string getFraseCorrecta();

};

#endif
