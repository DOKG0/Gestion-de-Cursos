#include "HandlerIdioma.h"
#include <iostream>

HandlerIdioma * HandlerIdioma::instancia = nullptr;

HandlerIdioma * HandlerIdioma::getInstance(){
    if(instancia == nullptr){
        instancia = new HandlerIdioma();
    }
    return instancia;
}

HandlerIdioma::HandlerIdioma(){
    this->idiomash = new OrderedDictionary();
}

HandlerIdioma::~HandlerIdioma(){}


IDictionary * HandlerIdioma::getIdiomasH(){
    return this->idiomash;
}

//******************************************************************//

//operacion idiomas

//Alta Idioma
void HandlerIdioma::AltaIdioma(std::string idioma){
    OrderedKey * ik = new String(idioma);//era orderedkey
    if(this->idiomash->member(ik)){
        std::cout << "Ya existe este idioma en el sistema" << std::endl;
    }else{
        Idioma * i = new Idioma(idioma);
        this->idiomash->add(ik, i);
        std::cout << "Se ha dado de alta el idioma correctamente" << std::endl;
    } 
}

//******************************************************************//

//Consultar Idiomas

IDictionary * HandlerIdioma::ListarIdiomas(){
    IIterator * iti;
    Idioma *i;
    
    IDictionary * listaidioma = new OrderedDictionary();

    for(iti = this->idiomash->getIterator(); iti->hasCurrent(); iti->next()){
        i = dynamic_cast<Idioma*>(iti->getCurrent());
        if(i){
        //i = (Idioma*)iti->getCurrent();
        OrderedKey * ok = new String(i->getNombreIdioma().c_str());
        listaidioma->add(ok,i);
        }
    }
    delete iti;
    return listaidioma;
}

Idioma * HandlerIdioma::ObtenerIdiomaPorNombre(std::string nombreidioma) {
    IKey * key = new String(nombreidioma);
    Idioma * idioma = dynamic_cast<Idioma*>(this->idiomash->find(key));
    delete key;
    return idioma;
}