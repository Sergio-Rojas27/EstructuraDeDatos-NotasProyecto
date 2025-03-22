#pragma once
#ifndef MATERIA_H
#define MATERIA_H

#include <string>
#include "nota.h"

class Materia {
public:
    std::string codigo;
    std::string nombre;
    double notaFinal;
    Nota* listaNotas;
    Materia* siguiente;
    Materia* anterior;

    Materia(std::string c, std::string n);
};

#endif