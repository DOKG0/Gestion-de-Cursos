#ifndef ENUMERACION_H
#define ENUMERACION_H
#include <string>
#include "../ico.h"
enum TipoDificultad{
    Principiante, Medio, Avanzado
};

struct Date {
    int day;
    int month;
    int year;

    // Constructor por defecto
    Date() : day(1), month(1), year(1970) {}

    // Constructor parametrizado
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};
#endif