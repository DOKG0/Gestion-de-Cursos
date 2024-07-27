#include "Registro.h"

Registro::Registro(){
    PorcentajeAprobacion = 0.0;
};

Registro::~Registro(){
IIterator* itEjercicios = this->EjerciciosAprobados->getIterator();
    while (itEjercicios->hasCurrent()) {
        ICollectible* elem = itEjercicios->getCurrent();
        delete elem;
        itEjercicios->next();
    }
    delete itEjercicios;
    delete this->EjerciciosAprobados;

    IIterator* itLecciones = this->LeccionesAprobadas->getIterator();
    while (itLecciones->hasCurrent()) {
        ICollectible* elem = itLecciones->getCurrent();
        delete elem;
        itLecciones->next();
    }
    delete itLecciones;
    delete this->LeccionesAprobadas;
}

Date Registro::getFechaRegistro(){
    return this->FechaRegistro;
}

double Registro::getPorcentajeAprobacion(){
    return this->PorcentajeAprobacion;
}

//
IDictionary * Registro::getEjerciciosAprobados(){
    if(this->EjerciciosAprobados == nullptr){
        return nullptr;
    }else{
        return this->EjerciciosAprobados;
    }
}

IDictionary * Registro::getLeccionesAprobadas(){
    if(this->LeccionesAprobadas == nullptr){
        std::cout << "N/A" << std::endl;
    }else{
        return this->LeccionesAprobadas;
    }
}

void Registro::calcularPorcentajeAprobacion(int totalEjerciciosCurso){
    if (totalEjerciciosCurso > 0) {
        PorcentajeAprobacion = (static_cast<double>(this->EjerciciosAprobados->getSize()) / totalEjerciciosCurso) * 100;
    } else {
        PorcentajeAprobacion = 0.0;
    }
}

void Registro::setFechaRegistro(Date fecha){
    this->FechaRegistro = fecha;
}

void Registro::setPorcentajeAprobacion(double porcentaje){
    this->PorcentajeAprobacion = porcentaje;
}

//
Curso * Registro::getCurso(){
    return this->curso;
}

void Registro::setCurso(Curso * curso){
    this->curso = curso;
}

Estudiante * Registro::getEstudiante(){
    return this->estudiante;
}

void Registro::setEstudiante(Estudiante * e){
    this->estudiante = e;
}

void Registro::agregarEjercicioAprobado(Ejercicio * ejercicio){
    OrderedKey * key = new String(ejercicio->getDescripcion());
    EjerciciosAprobados->add(key, ejercicio);
    //delete key;
}

void Registro::agregarLeccionAprobada(Leccion * leccion){
    if(!leccion){
        return;
    }
    OrderedKey * key = new String(leccion->getTema());
    LeccionesAprobadas->add(key,leccion);
}

bool Registro::esLeccionAprobada(std::string tema){
    OrderedKey * key = new String(tema);
    return LeccionesAprobadas->member(key);
}


//

bool Registro::esEjercicioAprobado(Ejercicio* ejercicio) {
    IIterator* it = EjerciciosAprobados->getIterator();
    while (it->hasCurrent()) {
        Ejercicio* ejAprobado = dynamic_cast<Ejercicio*>(it->getCurrent());
        if (ejAprobado->getContador() == ejercicio->getContador()) {
            delete it;
            return true;
        }
        it->next();
    }

    delete it;
    return false;
}


void Registro::eliminarRegistrodeCurso(Registro * r){


    Estudiante * estudiante = this->getEstudiante();
    estudiante->eliminarEstudiantedeCurso(r);
    
   // BORRAR REGISTRO, NO SE SI TENGO QUE BORRAR LO QUE CONTIENEN LOS ATRIBUTOS ETC

}