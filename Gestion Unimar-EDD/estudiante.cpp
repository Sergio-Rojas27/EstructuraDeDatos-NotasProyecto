#include "estudiante.h"

Estudiante::Estudiante(int i, std::string n, std::string c)
    : id(i), nombre(n), carrera(c), listaMaterias(nullptr), izquierda(nullptr), derecha(nullptr) {
}