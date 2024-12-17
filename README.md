# Gestion de cursos

Este proyecto es una aplicación que facilita el aprendizaje de nuevos idiomas de forma **didáctica e interactiva**. La aplicación permite registrar cursos, profesores y estudiantes, así como inscribirse a cursos, realizar ejercicios, y visualizar el progreso del aprendizaje.

---

## **Características Principales**

1. **Gestión de Usuarios**:  
   - Dos tipos de usuarios: **Profesores** y **Estudiantes**.  
   - Cada usuario es registrado con:  
      - **Nickname** (identificador único).  
      - **Contraseña** (mínimo 6 caracteres).  
      - **Nombre** y **Descripción**.  
   - Información adicional:  
      - **Profesores**: Instituto donde trabaja e idiomas de especialización.  
      - **Estudiantes**: País de residencia y fecha de nacimiento.  

2. **Gestión de Cursos**:  
   - Los **profesores** pueden proponer y crear cursos en los idiomas en los que se especializan.  
   - Cada curso incluye:  
      - **Nombre único**, descripción e idioma.  
      - Nivel de dificultad: *Principiante*, *Medio* o *Avanzado*.  
   - Cursos con **prerrequisitos**:  
      - Un estudiante debe aprobar ciertos cursos previos para inscribirse en otros avanzados.  
   - **Lecciones y Ejercicios**:  
      - Cada curso se compone de **lecciones** que incluyen **ejercicios**.  
      - Tipos de ejercicios soportados:  
         - **Completar palabras**: Rellenar palabras faltantes en una frase.  
         - **Traducción**: Traducir una frase comparándola con la traducción correcta.  
   - **Progreso del Estudiante**:  
      - Registro de ejercicios aprobados y lecciones completadas.  
      - Un curso se considera aprobado cuando todas las lecciones y ejercicios han sido completados con éxito.  

3. **Visualización del Progreso**:  
   - Visualización del progreso individual del estudiante mediante gráficos interactivos.  
   - Comparación del progreso entre diferentes estudiantes.  

---

## **Estructura del Proyecto**

El proyecto se ha diseñado utilizando principios de **programación modular** y **patrones de diseño**:

1. **Makefile**  
   - El proyecto incluye un `Makefile` que facilita la compilación y ejecución del programa.

2. **DataTypes**  
   - Uso de **data types** para manejar estructuras de datos específicas.

3. **Librería iCollection**  
   - Se utiliza la librería `iCollection` para la gestión eficiente de colecciones.

4. **Singleton**  
   - El patrón **Singleton** se implementa para manejar la instancia única de los controladores del sistema.

5. **Controladores y Handlers**  
   - **ControladorUsuario**: Maneja la lógica relacionada con profesores y estudiantes.  
   - **ControladorCurso**: Gestiona la creación, consulta e inscripción de cursos.  
   - **HandlerIdioma**: Administra los idiomas disponibles en el sistema.  

6. **Interfaces**  
   - **InterfazCurso**: Define las operaciones relacionadas con los cursos.  
   - **InterfazUsuario**: Define las operaciones relacionadas con los usuarios.

---

## **Cómo Ejecutar el Programa**

1. Asegúrate de tener un entorno compatible para compilar y ejecutar el código (ej. **gcc**, **g++**, etc.).
2. Utiliza el **Makefile** incluido para compilar y ejecutar el proyecto.  
   - Compilar:  
     ```bash
     make build o make rebuild
     ```
   - Ejecutar:  
     ```bash
     make run
     ```
3. Limpiar archivos generados:  
   ```bash
   make clean
