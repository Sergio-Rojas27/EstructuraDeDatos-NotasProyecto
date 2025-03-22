// Gestion Unimar-EDD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "nota.h"
#include "materia.h"
#include "estudiante.h"
#include "funciones.h"

using namespace std;

int main() {
    Estudiante* raiz = nullptr;
    int opcion, id;
    string nombre, carrera, codigo, fecha;
    double nota, ponderacion;

    do {
		cout << "+-------------------------------------------+" << endl;
		cout << "|          SELECCIONE UNA OPCION.           |" << endl;
		cout << "+-------------------------------------------+" << endl;
        cout << "|(1). Registrar Estudiante                  |" << endl;
        cout << "|(2). Buscar Estudiante                     |" << endl;
        cout << "|(3). Eliminar Estudiante                   |" << endl;
        cout << "|(4). Mostrar Estudiantes (Inorden)         |" << endl;
        cout << "|(5). Inscribir Materian                    |" << endl;
        cout << "|(6). Eliminar Materia                      |" << endl;
        cout << "|(7). Listar Materias                       |" << endl;
        cout << "|(8). Registrar Nota                        |" << endl;
        cout << "|(9). Mostrar Notas                         |" << endl;
        cout << "|(0). Salir                                 |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "ID: ";
            cin >> id;
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Carrera: ";
            getline(cin, carrera);
            raiz = registrarEstudiante(raiz, id, nombre, carrera);
            break;
        case 2:
            cout << "ID: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Estudiante encontrado: " << estudiante->nombre << endl;
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 3:
            cout << "ID: ";
            cin >> id;
            raiz = eliminarEstudiante(raiz, id);
            break;
        case 4:
            inorden(raiz);
            break;
        case 5:
            cout << "ID del Estudiante: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                cout << "Nombre de la Materia: ";
                cin.ignore();
                getline(cin, nombre);
                inscribirMateria(estudiante, codigo, nombre);
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 6:
            cout << "ID del Estudiante: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                eliminarMateria(estudiante, codigo);
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 7:
            cout << "ID del Estudiante: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                listarMaterias(estudiante);
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 8:
            cout << "ID del Estudiante: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                Materia* materia = estudiante->listaMaterias;
                while (materia != nullptr && materia->codigo != codigo) {
                    materia = materia->siguiente;
                }
                if (materia != nullptr) {
                    cout << "Fecha de la Evaluacion: ";
                    cin >> fecha;
                    cout << "Nota Obtenida: ";
                    cin >> nota;
                    cout << "Ponderacion (%): ";
                    cin >> ponderacion;
                    registrarNota(materia, fecha, nota, ponderacion);
                }
                else {
                    cout << "Materia no encontrada." << endl;
                }
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 9:
            cout << "ID del Estudiante: ";
            cin >> id;
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                Materia* materia = estudiante->listaMaterias;
                while (materia != nullptr && materia->codigo != codigo) {
                    materia = materia->siguiente;
                }
                if (materia != nullptr) {
                    mostrarNotas(materia);
                }
                else {
                    cout << "Materia no encontrada." << endl;
                }
            }
            else {
                cout << "Estudiante no encontrado." << endl;
            }
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
