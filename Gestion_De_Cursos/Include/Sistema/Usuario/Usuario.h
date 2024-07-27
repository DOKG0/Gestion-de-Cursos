#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"

class Usuario : public ICollectible{
    //clase abstracta de usuario, debe tener todo en virtual, se implementa estudiante y profesor por separado

    protected:
        std::string Nickname;
        std::string Nombre;
        std::string Contrasenia;
        std::string Descripcion;
    public:
        //getter & setters -> virtual
        virtual void setNickname(std::string Nombre) = 0;
        virtual void setContrasenia(std::string Contrasenia) = 0;
        virtual void setDescripcion(std::string Descripcion) = 0;
        virtual std::string getNickname() = 0;
        virtual std::string getContrasenia() = 0;
        virtual std::string getDescripcion() = 0;
        virtual std::string getNombre() = 0;
        std::string getNick();
        //Constructor
        Usuario();
        //Usuario(Usuario &User);
        ~Usuario();

};

#endif