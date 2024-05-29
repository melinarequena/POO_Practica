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
/*

#include <iostream>
#include <string>
#include <vector>

using namespace std;


 * COMPROBACION 2
 * class Estudiante {
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

 */

/* FARMACIA
 * PRODUCTOS: MEDICAMENTOS O CUIDADO PERSONAL
 * ATRIBUTOS: CODIGO, NOMBRE Y PRECIO
 * FARMACIA TIENE INVENTARIO (CONTENEDOR)
 *
 * OPERACIONES:
 * 1) AGREGAR PRODUCTO AL INVENTARIO
 * 2) VENDER PRODUCTO. REGISTRAR PRODUCTO, CON DATOS.
 *
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto{
private:
    string nombre;
    int codigo;
    float precio;
public:
    Producto(string n, int c, float p){
        nombre = n;
        codigo = c;
        precio = p;
        cout << "Se ha creado un nuevo producto" << endl;
    }
    ~Producto(){
        cout << "Destrucción de producto " << endl;
    }
    friend class Farmacia;
};

class remedio: public Producto {
public:
    remedio(string n, int c, float p): Producto(n,c,p){}
};

class cuidadoPersonal: public Producto {
public:
    cuidadoPersonal(string n, int c, float p): Producto(n,c,p){}
};


class Farmacia{ //clase contenedora
private:
    vector <Producto*> Inventario;
public:
    void addProducto(Producto * producto){
        Inventario.push_back(producto);
    }
    void venderProducto(const string& nombre){
        Producto * vendido = Inventario.back(); // devuelve el ulimo elemento
        Inventario.pop_back(); // elimina el ultimo elemento
        cout << " Vendido: " << vendido->nombre << " Precio: " << vendido->precio << " Codigo: " << vendido->codigo << " Comprador: " << nombre << endl;
    }
    void mostrarProductos(){
        cout <<"\n\nListado:\n" << endl;
        for(Producto * producto : Inventario){
         cout << "Nombre:" << producto->nombre << " Codigo:" << producto->codigo << " Precio:" <<producto->precio << endl;
        }
    }
    void liberarMemoria(){
        if(Inventario.empty()){
            return;
        }
        for(Producto * producto : Inventario){
            delete producto;
        }
    }
};

int main(){
    Farmacia * farmacia = new Farmacia;
    farmacia->addProducto(new cuidadoPersonal("Dermaglos", 123, 60.5));
    farmacia->addProducto(new remedio("Ibuprofeno 400", 1106, 30.2));
    farmacia->addProducto(new remedio("Paracetamol", 500, 29.6));

    farmacia->mostrarProductos();

    farmacia->venderProducto("Carla");

    farmacia->liberarMemoria();

    delete farmacia;

}
