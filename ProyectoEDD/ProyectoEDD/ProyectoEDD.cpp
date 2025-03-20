// ProyectoEDD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

// Clase para representar una Nota
class Nota {
public:
    std::string fecha;       // Fecha de la evaluación
    float valor;             // Nota obtenida (0 a 20)
    float ponderacion;       // Ponderación de la evaluación (porcentaje)
    float notaPonderada;     // Nota ponderada (valor * ponderación)

    // Constructor
    Nota(std::string f, float v, float p) : fecha(f), valor(v), ponderacion(p) {
        notaPonderada = valor * (ponderacion / 100); // Calcula la nota ponderada
    }
};

// Nodo para la lista enlazada simple de notas
struct NodoNota {
    Nota nota;              // Datos de la nota
    NodoNota* siguiente;    // Puntero al siguiente nodo

    // Constructor
    NodoNota(Nota n) : nota(n), siguiente(nullptr) {}
};

// Lista enlazada simple para gestionar notas
class ListaNotas {
private:
    NodoNota* cabeza;       // Puntero al primer nodo de la lista

public:
    // Constructor
    ListaNotas() : cabeza(nullptr) {}

    // Método para agregar una nota al final de la lista
    void agregarNota(Nota nota) {
        NodoNota* nuevoNodo = new NodoNota(nota);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            NodoNota* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    // Método para mostrar todas las notas de la lista
    void mostrarNotas() {
        NodoNota* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Fecha: " << temp->nota.fecha << ", Nota: " << temp->nota.valor
                << ", Ponderación: " << temp->nota.ponderacion << "%, Nota Ponderada: "
                << temp->nota.notaPonderada << std::endl;
            temp = temp->siguiente;
        }
    }

    // Método para calcular la nota final de la materia
    float calcularNotaFinal() {
        float notaFinal = 0;
        NodoNota* temp = cabeza;
        while (temp != nullptr) {
            notaFinal += temp->nota.notaPonderada;
            temp = temp->siguiente;
        }
        return notaFinal;
    }
};

// Clase para representar una Materia
class Materia {
public:
    std::string codigo;      // Código de la materia
    std::string nombre;      // Nombre de la materia
    ListaNotas notas;        // Lista de notas (usamos nuestra lista enlazada simple)

    // Constructor
    Materia(std::string c, std::string n) : codigo(c), nombre(n) {}

    // Método para mostrar las notas de la materia
    void mostrarNotas() {
        std::cout << "Notas de la materia " << nombre << " (" << codigo << "):" << std::endl;
        notas.mostrarNotas();
        std::cout << "Nota Final: " << notas.calcularNotaFinal() << std::endl;
    }
};

// Nodo para la lista doblemente enlazada de materias
struct NodoMateria {
    Materia materia;        // Datos de la materia
    NodoMateria* anterior;  // Puntero al nodo anterior
    NodoMateria* siguiente; // Puntero al siguiente nodo

    // Constructor
    NodoMateria(Materia m) : materia(m), anterior(nullptr), siguiente(nullptr) {}
};

// Lista doblemente enlazada para gestionar materias
class ListaMaterias {
private:
    NodoMateria* cabeza;    // Puntero al primer nodo de la lista
    NodoMateria* cola;      // Puntero al último nodo de la lista

public:
    // Constructor
    ListaMaterias() : cabeza(nullptr), cola(nullptr) {}

    // Método para agregar una materia al final de la lista
    void agregarMateria(Materia materia) {
        NodoMateria* nuevoNodo = new NodoMateria(materia);
        if (cabeza == nullptr) {
            cabeza = cola = nuevoNodo;
        }
        else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
    }

    // Método para mostrar todas las materias de la lista
    void mostrarMaterias() {
        NodoMateria* temp = cabeza;
        while (temp != nullptr) {
            temp->materia.mostrarNotas();
            temp = temp->siguiente;
        }
    }
};

// Función principal
int main() {
    // Crear una lista de materias
    ListaMaterias listaMaterias;

    // Crear algunas materias y agregar notas
    Materia materia1("MAT-101", "Matemáticas");
    materia1.notas.agregarNota(Nota("2023-10-01", 18, 30)); // Nota 1
    materia1.notas.agregarNota(Nota("2023-10-15", 15, 20)); // Nota 2
    materia1.notas.agregarNota(Nota("2023-10-30", 20, 50)); // Nota 3

    Materia materia2("FIS-101", "Física");
    materia2.notas.agregarNota(Nota("2023-10-05", 16, 40)); // Nota 1
    materia2.notas.agregarNota(Nota("2023-10-20", 14, 60)); // Nota 2

    // Agregar materias a la lista
    listaMaterias.agregarMateria(materia1);
    listaMaterias.agregarMateria(materia2);

    // Mostrar todas las materias con sus notas
    listaMaterias.mostrarMaterias();

    return 0;
}
