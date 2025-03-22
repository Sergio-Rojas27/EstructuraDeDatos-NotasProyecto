#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estudiante.h"

// Funciones para la gestión de notas
void registrarNota(Materia* materia, std::string fecha, double nota, double ponderacion);
void mostrarNotas(Materia* materia);

// Funciones para la gestión de materias
void inscribirMateria(Estudiante* estudiante, std::string codigo, std::string nombre);
void eliminarMateria(Estudiante* estudiante, std::string codigo);
void listarMaterias(Estudiante* estudiante);

// Funciones para la gestión de estudiantes
Estudiante* registrarEstudiante(Estudiante* raiz, int id, std::string nombre, std::string carrera);
Estudiante* buscarEstudiante(Estudiante* raiz, int id);
Estudiante* eliminarEstudiante(Estudiante* raiz, int id);
void inorden(Estudiante* raiz);
int contarEstudiantes(Estudiante* raiz);

#endif