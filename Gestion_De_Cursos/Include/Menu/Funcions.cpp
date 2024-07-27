#include "Functions.h"
#include <iostream>
#include <stdio.h>




//************************************************************************************//



//************************************************************************************//
void limpiarBuffer(){
    while (getchar() != '\n'){
        //pass
    }
}

//************************************************************************************//
void pausa(std::string msg){
    std::cout << std::endl;
    std::cout << msg;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /* while(getchar() != '\n'){
        //para generar pausa
    } */
}

//************************************************************************************//
int pedirInt(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    int valor;
    std::cin >> valor;
    return valor;
};
//************************************************************************************//
float pedirFloat(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    float valor;
    std::cin >> valor;

    return valor;
}

//************************************************************************************//
std::string pedirString(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    std::string valor;
    const int bufferSize = 100;
    char buffer[bufferSize];
    std::cin.getline(buffer, bufferSize); 
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//agregada probando alta curso
    valor = buffer;
    //system("clear");
    std::transform(valor.begin(), valor.end(), valor.begin(), [](unsigned char c){ return std::tolower(c); });
    return valor;
};



//************************************************************************************//

std::string pedirContrasenia(std::string msg) {
    std::string valor;
    while (true) {
        std::cout << "Ingrese " << msg << " (6 o más caracteres): ";
        std::cin >> valor;
        if (valor.length() >= 6) {
            break;
        } else {
            std::cout << "La contraseña debe tener al menos 6 caracteres. Intente nuevamente." << std::endl;
        }
    }
    std::transform(valor.begin(), valor.end(), valor.begin(), [](unsigned char c){ return std::tolower(c); });
    return valor;
}

//************************************************************************************//
int obteneropcion() {
    int opcion = 0;
    std::cout << ">... ";
    while (!(std::cin >> opcion) || opcion < 1 || opcion > 7) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese una opción válida\n" << std::endl;
        std::cout << ">... ";
    }
    limpiarBuffer();
    return opcion;
}

int obteneropcion2() {
    int opcion = 0;
    std::cout << ">... ";
    while (!(std::cin >> opcion) || opcion < 1 || opcion > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese una opción válida\n" << std::endl;
        std::cout << ">... ";
    }
    limpiarBuffer();
    return opcion;
}

//************************************************************************************//
void printTitleInBox(const std::string& title) {
    int length = title.length();

    std::cout << "+";
    for(int i = 0; i < length + 2; i++)
        std::cout << "-";
    std::cout << "+\n";

    std::cout << "| " << title << " |\n";

    std::cout << "+";
    for(int i = 0; i < length + 2; i++)
        std::cout << "-";
    std::cout << "+\n";
    std::cout <<"\n";
}

//************************************************************************************//

Date pedirFecha(const std::string& mensaje) {
    std::string fechaStr;
    int dia, mes, anio;
    char sep1, sep2;

    while (true) {
        std::cout << "Ingrese " << mensaje << " (formato DD/MM/AAAA): ";
        std::getline(std::cin, fechaStr);
        std::istringstream iss(fechaStr);
        if ((iss >> dia >> sep1 >> mes >> sep2 >> anio) && sep1 == '/' && sep2 == '/' && 
            dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && anio > 1900 && anio <= 2023) {
            return Date(dia, mes, anio);
        } else {
            std::cout << "Fecha no válida. Por favor, intente de nuevo." << std::endl;
        }
    }
}

//************************************************************************************//
std::string dateToString(const Date& date) {
    std::ostringstream oss;
    oss << (date.day < 10 ? "0" : "") << date.day << "/"
        << (date.month < 10 ? "0" : "") << date.month << "/"
        << date.year;
    return oss.str();
}

//************************************************************************************//

void loading(std::string msg) {
    std::cout << std::endl;
    const int total = 20;
    for (int i = 0; i <= total; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
        std::cout << "\r" << msg << ": [";
        for (int j = 0; j < total; j++) {
            if (j < i)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << "] " << (i * 5) << "%";
        std::cout.flush();
    }
}

//************************************************************************************//

std::string obtenerTipoDificultad(TipoDificultad dificultad) {
    switch (dificultad) {
        case 0: Principiante:
            return "Principiante";
            break;
        case 1: Medio:
            return "Medio";
            break;
        case 2: Avanzado:
            return "Avanzado";
            break;
    }
}

std::string ObtenerBool(bool booleano){
    if(booleano){
        return "True";
    }else{
        return "False";
    }
}

Date ObtenerFechaActual(){
    std::time_t t = std::time(nullptr);
    std::tm * now = std::localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}



