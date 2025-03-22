#pragma once
#ifndef NOTA_H
#define NOTA_H

#include <string>

class Nota {
public:
    std::string fecha;
    double nota;
    double ponderacion;
    double notaPonderada;
    Nota* siguiente;

    Nota(std::string f, double n, double p);
};

#endif