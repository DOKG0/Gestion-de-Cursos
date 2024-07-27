#ifndef DATAESTUDIANTE_H
#define DATAESTUDIANTE_H

#include "DataUsuario.h"
#include "Enum.h"
#include <string>

class DataEstudiante: public DataUsuario{
    private:
        std::string Nickname;
        std::string Descripcion;
        std::string Pais;
        Date FechaNac;
        IDictionary * cursosInscripto = new OrderedDictionary();

    public:
        DataEstudiante();
        DataEstudiante(std::string Nickname, std::string Pais, Date FechaNac);
        DataEstudiante(std::string Nickname, std::string Descripcion, std::string Pais, Date FechaNac);
        DataEstudiante(std::string Nickname, std::string Descripcion, std::string Pais, Date FechaNac, IDictionary * cursosInscripto);
        std::string getNickname();
        std::string getDescripcion();
        std::string getPais();
        Date getFechaNac();
        IDictionary * getCursosInscriptoDT();

};

class DataEstadisticaEstudiante: public DataUsuario{

};

#endif