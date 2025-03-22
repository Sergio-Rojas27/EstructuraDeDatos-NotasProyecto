#include "materia.h"

Materia::Materia(std::string c, std::string n)
    : codigo(c), nombre(n), notaFinal(0), listaNotas(nullptr), siguiente(nullptr), anterior(nullptr) {
}
