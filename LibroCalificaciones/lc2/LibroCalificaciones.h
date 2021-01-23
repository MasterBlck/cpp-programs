#include <string> // el programa usa la clase string estándar de C++
using std::string;

// definición de la clase LibroCalificaciones
class LibroCalificaciones
{
    public:
        LibroCalificaciones( string ); // el constructor inicializa el nombre del curso
        void establecerNombreCurso( string ); // función para establecer el nombre del curso
        string obtenerNombreCurso(); // función para obtener el nombre del curso
        void mostrarMensaje(); // muestra un mensaje de bienvenida
        void determinarPromedioClase(); // promedia las calificaciones escritas por el usuario
    private:
        string nombreCurso; // nombre del curso para este LibroCalificaciones
}; // fin de la clase LibroCalificaciones
