#include "LibroCalificaciones.h"
int main()
{
    // crea el objeto LibroCalificaciones llamado miLibroCalificaciones y
    // pasa el nombre del curso al constructor
    LibroCalificaciones miLibroCalificaciones( "CS101 Programacion en C++" );
    miLibroCalificaciones.mostrarMensaje(); // muestra el mensaje de bienvenida
    miLibroCalificaciones.determinarPromedioClase(); // busca el promedio de 10 calificaciones
    return 0; // indica que el programa terminó correctamente
} // fin de main
