/*Diseña un sistema de gestión de estudiantes para una universidad. Este sistema permitirá
manejar la información de los estudiantes, como su

 -nombre, edad, y promedio académico.

 Además, implementa una sobrecarga de operadores para comparar estudiantes por su mejor
promedio académico.
Implementación:
Clase Estudiante: Representa a un estudiante y contiene su información personal y académica.
Clase Universidad: es la clase contenedora que gestionará a los estudiantes.
Operadores Sobrecargados: se deberá sobrecargar el operador de comparación para poder
comparar estudiantes por su mejor promedio académico
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    float promedio;

public:
    Estudiante(string n, int e, float p) {
        nombre = n;
        edad = e;
        promedio = p;
    }
    ~Estudiante() {
        cout << "Estudiante eliminado" << endl;
    }

    bool operator > (const Estudiante & otra) const{
        return (promedio < otra.promedio);
    }

    void mostrar ()const{
        cout << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << endl;
    }
};

class Universidad{
private:
    vector <Estudiante*> contenedorEstudiantes;        // creamos el vector

public:
    void addEstudiante(string n, float p, int e){       // insertamos con push back
        contenedorEstudiantes.push_back(new Estudiante(n,e , p));

    }
    void mostrarEstudiantes(){          // creamos un iterador

        for(Estudiante * estudiante : contenedorEstudiantes){
            estudiante->mostrar();
        }
    }

    Estudiante * mejorEstudiante(){
        if(contenedorEstudiantes.empty()){
            return nullptr;
        }

        Estudiante * mejorEstudiante = contenedorEstudiantes[0];

        for(Estudiante * estudiante : contenedorEstudiantes){
            if(estudiante > mejorEstudiante){
                mejorEstudiante = estudiante;
            }
        }
        return mejorEstudiante;
    }
};

int main() {

    Universidad * universidad = new Universidad;

    universidad->addEstudiante("Camila", 10, 80);
    universidad->addEstudiante("Felipe", 7, 20);
    universidad->addEstudiante("Barbi", 9, 52);

    universidad->mostrarEstudiantes();

    cout << "El mejor estudiante es " << endl;
    universidad->mejorEstudiante()->mostrar();

    return 0;
}
