#ifndef DATAPROFESOR_H
#define DATAPROFESOR_H

#include "DataUsuario.h"
#include <string>
#include "../ico.h"
#include "Enum.h"


class DataProfesor: public DataUsuario{
    private:
        std::string Nickname;
        std::string Descripcion;
        std::string Instituto;
        IDictionary * idiomasprofesor;
    public:
        DataProfesor();
        DataProfesor(std::string Nickname, std::string Instituto);
        DataProfesor(std::string Nickname, std::string Descripcion, std::string Instituto);
        DataProfesor(std::string Nickname, std::string Descripcion, std::string Instituto, IDictionary * idiomasprofesor);
        std::string getNickname();
        std::string getInstituto();
        std::string getDescripcion();
};

class DataEstadisticaProfesor: public DataUsuario{
    private:
    std::string nombreCurso;
    double promedioAvance;
    std::string descripcionCurso;
    TipoDificultad dificultadCurso;

public:
    DataEstadisticaProfesor(const std::string& nombreCurso, double promedioAvance, TipoDificultad dificultadCurso, std::string descripcionCurso);
    std::string getNombreCurso() const;
    double getPromedioAvance() const;
    std::string getDescripcion();
    TipoDificultad getDificultad();
};

#endif