#ifndef CUR_H
#define CUR_H

#include "../Sistema/Curso/Curso.h"
#include "../ico.h"
#include "Enum.h"

class CursoEstadistica : public ICollectible {
public:
    Curso* curso;
    double porcentajeAvance;
    std::string descripcionCurso;
    TipoDificultad dificultadCurso;
    int ejerciciosAprobados;

    CursoEstadistica(Curso* curso, double porcentajeAvance, std::string descripcionCurso, TipoDificultad dificultadCurso, int ejerciciosAprobados) 
        : curso(curso), porcentajeAvance(porcentajeAvance), descripcionCurso(descripcionCurso), dificultadCurso(dificultadCurso), ejerciciosAprobados(ejerciciosAprobados) {}
};

#endif