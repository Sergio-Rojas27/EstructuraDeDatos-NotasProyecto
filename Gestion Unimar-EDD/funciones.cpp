#include "funciones.h"
#include <iostream>

// Funciones de la gestión de notas
void registrarNota(Materia* materia, std::string fecha, double nota, double ponderacion) {
    Nota* nuevaNota = new Nota(fecha, nota, ponderacion);
    nuevaNota->siguiente = materia->listaNotas;
    materia->listaNotas = nuevaNota;
    materia->notaFinal += nuevaNota->notaPonderada;
}

void mostrarNotas(Materia* materia) {
    Nota* actual = materia->listaNotas;
    while (actual != nullptr) {
        std::cout << "Fecha: " << actual->fecha << ", Nota: " << actual->nota
            << ", Ponderación: " << actual->ponderacion << "%, Nota Ponderada: " << actual->notaPonderada << std::endl;
        actual = actual->siguiente;
    }
}

// Funciones de la gestión de materias
void inscribirMateria(Estudiante* estudiante, std::string codigo, std::string nombre) {
    Materia* nuevaMateria = new Materia(codigo, nombre);
    nuevaMateria->siguiente = estudiante->listaMaterias;
    if (estudiante->listaMaterias != nullptr) {
        estudiante->listaMaterias->anterior = nuevaMateria;
    }
    estudiante->listaMaterias = nuevaMateria;
}

void eliminarMateria(Estudiante* estudiante, std::string codigo) {
    Materia* actual = estudiante->listaMaterias;
    while (actual != nullptr) {
        if (actual->codigo == codigo) {
            if (actual->anterior != nullptr) {
                actual->anterior->siguiente = actual->siguiente;
            }
            else {
                estudiante->listaMaterias = actual->siguiente;
            }
            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = actual->anterior;
            }
            delete actual;
            return;
        }
        actual = actual->siguiente;
    }
}

void listarMaterias(Estudiante* estudiante) {
    Materia* actual = estudiante->listaMaterias;
    while (actual != nullptr) {
        std::cout << "Código: " << actual->codigo << ", Nombre: " << actual->nombre
            << ", Nota Final: " << actual->notaFinal << std::endl;
        actual = actual->siguiente;
    }
}

// Funciones de la gestión de estudiantes
Estudiante* registrarEstudiante(Estudiante* raiz, int id, std::string nombre, std::string carrera) {
    if (raiz == nullptr) {
        return new Estudiante(id, nombre, carrera);
    }
    if (id < raiz->id) {
        raiz->izquierda = registrarEstudiante(raiz->izquierda, id, nombre, carrera);
    }
    else {
        raiz->derecha = registrarEstudiante(raiz->derecha, id, nombre, carrera);
    }
    return raiz;
}

Estudiante* buscarEstudiante(Estudiante* raiz, int id) {
    if (raiz == nullptr || raiz->id == id) {
        return raiz;
    }
    if (id < raiz->id) {
        return buscarEstudiante(raiz->izquierda, id);
    }
    return buscarEstudiante(raiz->derecha, id);
}

Estudiante* eliminarEstudiante(Estudiante* raiz, int id) {
    if (raiz == nullptr) {
        return raiz;
    }
    if (id < raiz->id) {
        raiz->izquierda = eliminarEstudiante(raiz->izquierda, id);
    }
    else if (id > raiz->id) {
        raiz->derecha = eliminarEstudiante(raiz->derecha, id);
    }
    else {
        if (raiz->izquierda == nullptr) {
            Estudiante* temp = raiz->derecha;
            delete raiz;
            return temp;
        }
        else if (raiz->derecha == nullptr) {
            Estudiante* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }
        Estudiante* temp = raiz->derecha;
        while (temp->izquierda != nullptr) {
            temp = temp->izquierda;
        }
        raiz->id = temp->id;
        raiz->nombre = temp->nombre;
        raiz->carrera = temp->carrera;
        raiz->derecha = eliminarEstudiante(raiz->derecha, temp->id);
    }
    return raiz;
}

void inorden(Estudiante* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierda);
        std::cout << "ID: " << raiz->id << ", Nombre: " << raiz->nombre << ", Carrera: " << raiz->carrera << std::endl;
        inorden(raiz->derecha);
    }
}

int contarEstudiantes(Estudiante* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    return 1 + contarEstudiantes(raiz->izquierda) + contarEstudiantes(raiz->derecha);
}