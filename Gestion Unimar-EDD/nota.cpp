#include "nota.h"

Nota::Nota(std::string f, double n, double p)
    : fecha(f), nota(n), ponderacion(p), notaPonderada(n* p / 100), siguiente(nullptr) {
}