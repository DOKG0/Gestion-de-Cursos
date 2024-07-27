#include "ControladorUsuario.h"

ControladorUsuario *ControladorUsuario::instance = nullptr;


ControladorCurso * Ccurso = ControladorCurso::getInstance();

ControladorUsuario::ControladorUsuario(){
    this->estudiantes = new OrderedDictionary();
    this->profesores = new OrderedDictionary();
}

ControladorUsuario *ControladorUsuario::getInstance(){
    if (instance == nullptr){
        instance = new ControladorUsuario();
    }
    return instance;
}

HandlerIdioma * idiomashandler = HandlerIdioma::getInstance();

//************************************************************************************//

//Verificaciones

bool ControladorUsuario::ExisteEstudiante(std::string nickname) {
    IKey* ik = new String(nickname);
    bool existe = this->estudiantes->member(ik);
    delete ik;
    return existe;
}

bool ControladorUsuario::ExisteProfesor(std::string nickname) {
    IKey* ik = new String(nickname);
    bool existe = this->profesores->member(ik);
    delete ik;
    return existe;
}

bool ControladorUsuario::IdiomaPerteneceAProfesor(std::string nicknameProfesor, std::string nombreIdioma) {
    IKey* ikProf = new String(nicknameProfesor);
    Profesor* profesor = dynamic_cast<Profesor*>(this->profesores->find(ikProf));
    delete ikProf;

    if (profesor == nullptr) {
        return false;
    }

    IDictionary* idiomasProfesor = profesor->getIdiomasProfesor();

    IKey* ikIdiom = new String(nombreIdioma);
    bool existe = idiomasProfesor->member(ikIdiom);
    delete ikIdiom;

    return existe;
}


//************************************************************************************//

Profesor* ControladorUsuario::ObtenerProfesor(std::string nickname) {
    OrderedKey* ik = new String(nickname);
    ICollectible* ic = this->profesores->find(ik);
    delete ik;
    
    if (ic != nullptr) {
        return dynamic_cast<Profesor*>(ic);
    } else {
        return nullptr;
    }
}

Estudiante* ControladorUsuario::ObtenerEstudiante(std::string nickname) {
    OrderedKey* ik = new String(nickname);
    ICollectible* ic = this->estudiantes->find(ik);
    delete ik;
    
    if (ic != nullptr) {
        return dynamic_cast<Estudiante*>(ic);
    } else {
        return nullptr;
    }
}

void ControladorUsuario::SetProfesorActual(Profesor* profesor) {
    this->profesorActual = profesor;
}

void ControladorUsuario::SetEstudianteActual(Estudiante* estudiante) {
    this->estudianteActual = estudiante;
}
//************************************************************************************//

IDictionary* ControladorUsuario::ListarProfesores(){
    IIterator* itp;
    Profesor* p;

    IDictionary* listprofesores = new OrderedDictionary();

    for(itp = this->profesores->getIterator(); itp->hasCurrent(); itp->next()){
        
        p = (Profesor*)itp->getCurrent();
        OrderedKey* ok = new String(p->getNickname().c_str());
        listprofesores->add(ok, p);
    }

    return listprofesores;
}

IDictionary* ControladorUsuario::ListarEstudiantes(){
    IIterator* itp;
    Estudiante* e;

    IDictionary* listestudiantes = new OrderedDictionary();

    for(itp = this->estudiantes->getIterator(); itp->hasCurrent(); itp->next()){
        
        e = (Estudiante*)itp->getCurrent();
        OrderedKey* ok = new String(e->getNickname().c_str());
        listestudiantes->add(ok, e);
    }

    return listestudiantes;
}

//************************************************************************************//
// 1 - AltaUsuario

//confirmar alta estudiante
void ControladorUsuario::ConfirmarAltaEstudiante(std::string nickname, std::string nombre, std::string descripcion, std::string contrasenia, std::string pais, Date fechaNac){
    OrderedKey* ik = new String(nickname);
    if(this->estudiantes->member(ik)){
        std::cout << "\nYa existe un estudiante con este Nickname" << std::endl;
    }else{
        Estudiante* e = new Estudiante(nickname,nombre, descripcion, contrasenia, pais, fechaNac);
        this->estudiantes->add(ik,e);
        std::cout << "Se ha dado de alta al estudiante correctamente" << std::endl;
    }
}

//confirmar alta profesor
void ControladorUsuario::ConfirmarAltaProfesor(std::string nickname, std::string nombre, std::string descripcion, std::string contrasenia, std::string instituto){
        OrderedKey* ik = new String(nickname);
    if(this->profesores->member(ik)){
        std::cout << "\nYa existe un profesor con este Nickname" << std::endl;
    }else{
        Profesor * p = new Profesor(nickname, nombre, descripcion, contrasenia, instituto);
        this->profesores->add(ik,p);
        std::cout << "Se ha dado de alta al profesor correctamente" << std::endl;
    }
}

//agregar idioma 
void ControladorUsuario::AgregarIdioma(std::string nombreidioma){
    IKey * ni = new String (nombreidioma);
     
    if (idiomashandler->getIdiomasH()->member(ni)) {
        ICollectible * ici = idiomashandler->getIdiomasH()->find(ni);
        Idioma * i = dynamic_cast<Idioma*>(ici);
        if (i != nullptr) {
            this->profesorActual->AgregarIdiomaProfesor(i);
            std::cout << "El idioma ha sido asignado correctamente al profesor" << std::endl;
        } else {
            std::cout << "error del dynamic_cast" << std::endl;
        }
        } else {
            std::cout << "\nIdioma ingresado no existe, intente de nuevo\n" << std::endl;
        }
    delete ni;
}
//************************************************************************************//

// 2 - ConsultaUsuario

//obtener usuarios
IDictionary* ControladorUsuario::ObtenerUsuarios(){
    IIterator* ite;
    IIterator* itp;
    Estudiante* e;
    Profesor* p;

    IDictionary* listuser = new OrderedDictionary();

    for(ite = this->estudiantes->getIterator(); ite->hasCurrent(); ite->next()){
        
        e = (Estudiante*)ite->getCurrent();
        OrderedKey* ok = new String (e->getNickname().c_str());
        listuser->add(ok, e);
    }
    for(itp = this->profesores->getIterator(); itp->hasCurrent(); itp->next()){
        
        p = (Profesor*)itp->getCurrent();
        
        OrderedKey* asdk = new String (p->getNickname());
        listuser->add(asdk,p);
    }
    return listuser;
}

//informacion usuario
DataUsuario * ControladorUsuario::InformacionUsuario(std::string nickname){
    OrderedKey * ik = new String(nickname);
    bool flag = false;

    ICollectible * ic = this->estudiantes->find(ik);
    if(ic == nullptr){
        ic = this->profesores->find(ik);
        flag = true;
    }
    
    if(flag && ic != nullptr){
        return new DataProfesor(dynamic_cast<Profesor*>(ic)->getNickname(), dynamic_cast<Profesor*>(ic)->getDescripcion(), dynamic_cast<Profesor*>(ic)->getInstituto(), dynamic_cast<Profesor*>(ic)->getIdiomasProfesor());
    }else if(ic != nullptr){
        IDictionary * cursosins = dynamic_cast<Estudiante*>(ic)->getCursosInscripto();
        return new DataEstudiante(dynamic_cast<Estudiante*>(ic)->getNickname(), dynamic_cast<Estudiante*>(ic)->getDescripcion(), dynamic_cast<Estudiante*>(ic)->getPais(), dynamic_cast<Estudiante*>(ic)->getFechaNac(), cursosins);
    }else{
        return nullptr;
    }
}



//************************************************************************************//
//11 - Inscribir a curso
//Listar cursos disponibles para estudiante
IDictionary * ControladorUsuario::ListarCursosHabiEstudiantes(std::string nickname){
    std::string nombrecurso;
    Estudiante * estudiante = this->ObtenerEstudiante(nickname); //Busco al estudiante en la coleccion de estudiantes del controlador usuario
    IDictionary * listaCursosHabi = new OrderedDictionary();//En esta coleccion voy a guardar los cursos habilitados para el estudiante
    IDictionary * listaDeCursos = Ccurso->ListarDataCurso(); //Le pido al constrolador de curso, que me de la lista de datacurso
    IIterator * it = listaDeCursos->getIterator(); // Obtengo iterador para recorrer la coleccion de cursos 
    DataCursoHab * dcurso = nullptr;
    while (it->hasCurrent()) // Recorro la coleccion en busca de cursos en los que el estudiante NO esta inscripto y SI tiene sus previas aprobadas.
    {
        dcurso = dynamic_cast<DataCursoHab*>(it->getCurrent()); //Como dentro de la coleccion de cursos_habilitados, hay mas colecciones, tengo que castear la info para obtener variable de tipo curso
        if(dcurso == nullptr){
            std::cout << "Es nulo" << std::endl;
            return nullptr;
        }

        if(dcurso->getHabilitado() == true){
            //std::cout << "Adentro del if 1" << std::endl;
            nombrecurso = dcurso->getNombreCurso();
            Curso * curso = Ccurso->ObtenerCurso(nombrecurso);
            if(estudiante->estaInscripto(nombrecurso) == false && estudiante->TienePreviasAprobadas(curso) == true){
                //std::cout << "Adentro del if 2" << std::endl;
                OrderedKey * cursokey = new String(nombrecurso);
                listaCursosHabi->add(cursokey, dcurso);
            }
            //std::cout << "afuera del if 2" << std::endl;
        }
        //std::cout << "afuera del if 1" << std::endl;

        it->next();
    }
    delete it;
    return listaCursosHabi;
}


void ControladorUsuario::InscribirCurso(std::string nickname, std::string nombrecurso, Date fechaRegistro) {
    Estudiante *estudiante = ObtenerEstudiante(nickname);//Chequeo si el estudiante existe
    if (!estudiante) {
        std::cout << "El estudiante no existe" << std::endl;
        return;
    }

    Curso *curso = Ccurso->ObtenerCurso(nombrecurso);
    if (!curso) {
        std::cout << "El curso no existe" << std::endl; //chequeo si el curso existe
        return;
    }
    //chequeo si el estudiante ya esta inscripto en el curso
    if (estudiante->estaInscripto(nombrecurso)) {
        std::cout << "El estudiante ya está inscripto en este curso" << std::endl;
        return;
    }
    //chequeo si el estudiante tiene las previas necesarias de ese curso aprobadas
    if (!estudiante->TienePreviasAprobadas(curso)) {
        std::cout << "El estudiante no ha aprobado los cursos previos necesarios" << std::endl;
        return;
    }

    Registro *nuevoRegistro = new Registro(); // creo el registro
    nuevoRegistro->setFechaRegistro(fechaRegistro); //le agrego la fecha
    nuevoRegistro->setPorcentajeAprobacion(0.0); // le agrego el porcenaje de aprobacion
    nuevoRegistro->setCurso(curso); // linkeo el curso al registro
    nuevoRegistro->setEstudiante(estudiante); // linkeo el estudiante al registro

    estudiante->agregarRegistro(curso->getNombreCurso(), nuevoRegistro); //agrego el registro al estudiante identificado por el nomnbre del curso al que se inscribio
    curso->agregarEstudiante(estudiante); //agrego el estudiante a la coleccion de estudiantes del curso
    curso->agregarRegistroInscripcion(nuevoRegistro); // agrego el registro de inscripcion del estudiante al curso tambien identificado por el estudiante

    std::cout << "El estudiante ha sido inscripto en el curso " << curso->getNombreCurso() << " de forma correcta" << std::endl;
}






//************************************************************************************//
//12 - Realizar ejercicio

IDictionary* ControladorUsuario::ListarCursosInscriptoNoAprobados(std::string nickname) {
    IDictionary* cursosInscriptoNoAprobados = new OrderedDictionary();

    Estudiante* estudiante = ObtenerEstudiante(nickname);
    if (estudiante == nullptr) {
        return cursosInscriptoNoAprobados; // Si el estudiante no existe, devolver diccionario vacío
    }

    IIterator* it = estudiante->getRegistro2()->getIterator();
    while (it->hasCurrent()) {
        Registro* registro = dynamic_cast<Registro*>(it->getCurrent());
        if (registro) {
            Curso* curso = registro->getCurso();
            if (curso && registro->getPorcentajeAprobacion() < 100.0) {
                OrderedKey* key = new String(curso->getNombreCurso());
                cursosInscriptoNoAprobados->add(key,curso);
            }
        }
        it->next();
    }

    delete it;
    return cursosInscriptoNoAprobados;
}

void ControladorUsuario::CargarAprobado(std::string nickname_, std::string curso_, std::string leccion_, std::string ejercicio_){

    Estudiante* estudiante = ObtenerEstudiante(nickname_);
    if (estudiante == nullptr) {
        std::cout << "No se encontro el estudiante" << std::endl;
        return;
    }

    Curso* curso = Ccurso->ObtenerCurso(curso_);
    if (curso == nullptr) {
        std::cout << "No se encontro el curso" << std::endl;
        return;
    }

    Leccion * leccion = curso->ObtenerLeccion(leccion_);
    if(leccion == nullptr){
        std::cout << "No se encontro la leccion" << std::endl;
        return;
    }

    Ejercicio * ejercicio = leccion->ObtenerEjercicio(ejercicio_);
    if(ejercicio == nullptr){
        std::cout << "No se encontro el ejercicio" << std::endl;
        return;
    }

    ejercicio->setAprobado(true);


}
//************************************************************************************//
//
IDictionary * ControladorUsuario::ConsultarEstadisticasEstudiante(std::string nickname){

IDictionary* estadisticas = new OrderedDictionary();
    
    Estudiante* estudiante = dynamic_cast<Estudiante*>(ObtenerEstudiante(nickname));
    if (estudiante == nullptr) {
        throw std::invalid_argument("Estudiante no encontrado");
    }

    IIterator* itCursos = estudiante->getRegistro2()->getIterator();
    while (itCursos->hasCurrent()) {
        Registro* registro = dynamic_cast<Registro*>(itCursos->getCurrent());
        if (registro != nullptr) {
            Curso* curso = dynamic_cast<Curso*>(registro->getCurso());
            std::string nombreCurso = curso->getNombreCurso();
            std::string descripcionCurso = curso->getDescripcionCurso();
            TipoDificultad dificultadCurso = curso->getDificultad();
            int ejerciciosAprobados = registro->getEjerciciosAprobados()->getSize();
            double porcentajeAvance = Ccurso->CalcularporcentajeAprobacion(nickname,nombreCurso);

            CursoEstadistica* cursoEstadistica = new CursoEstadistica{curso, porcentajeAvance, descripcionCurso,dificultadCurso,ejerciciosAprobados};
            OrderedKey * key = new String(nombreCurso);
            estadisticas->add(key, cursoEstadistica);
        }
        itCursos->next();
    }
    delete itCursos;

    return estadisticas;
}

IDictionary* ControladorUsuario::consultarEstadisticasProfesor(std::string nickname){
    Profesor* profesor = this->ObtenerProfesor(nickname);
    if (profesor == nullptr) {
        std::cout << "Profesor no encontrado" << std::endl;
        return nullptr;
    }

    IDictionary* cursosProfesor = profesor->getCursosProfesor();
    IIterator* it = cursosProfesor->getIterator();
    IDictionary* estadisticas = new OrderedDictionary();

    while (it->hasCurrent()) {
        Curso* curso = dynamic_cast<Curso*>(it->getCurrent());
        if (curso != nullptr) {
            IDictionary* registros = curso->getRegistroInscripcion();
            IIterator* itReg = registros->getIterator();
            double sumaPorcentajes = 0.0;
            int cantidadEstudiantes = 0;

            while (itReg->hasCurrent()) {
                Registro* registro = dynamic_cast<Registro*>(itReg->getCurrent());
                if (registro != nullptr) {
                    sumaPorcentajes += registro->getPorcentajeAprobacion();
                    cantidadEstudiantes++;
                }
                itReg->next();
            }
            delete itReg;

            double promedioAvance = cantidadEstudiantes > 0 ? sumaPorcentajes / cantidadEstudiantes : 0.0;
            std::string descripcion = curso->getDescripcionCurso();
            TipoDificultad dificultad = curso->getDificultad();

            DataEstadisticaProfesor* data = new DataEstadisticaProfesor(curso->getNombreCurso(), promedioAvance, dificultad, descripcion);
            estadisticas->add(new String(curso->getNombreCurso().c_str()), data);
        }
        it->next();
    }
    delete it;

    return estadisticas;
}