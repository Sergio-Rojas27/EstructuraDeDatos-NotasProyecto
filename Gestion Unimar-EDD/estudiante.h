#pragma once
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include "materia.h"

class Estudiante {
public:
    int id;
    std::string nombre;
    std::string carrera;
    Materia* listaMaterias;
    Estudiante* izquierda;
    Estudiante* derecha;

    Estudiante(int i, std::string n, std::string c);
};

#endif