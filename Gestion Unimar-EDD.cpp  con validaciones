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
        cout << "|(5). Inscribir Materia                     |" << endl;
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
            // Validación de ID único
            if (buscarEstudiante(raiz, id) != nullptr) {
                cout << "Error: El ID ya está registrado." << endl;
                break; // Salir del caso si el ID ya existe
            }
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            // Validación de nombre no vacío
            if (nombre.empty()) {
                cout << "Error: El nombre no puede estar vacío." << endl;
                break;
            }
            cout << "Carrera: ";
            getline(cin, carrera);
            // Validación de carrera no vacía
            if (carrera.empty()) {
                cout << "Error: La carrera no puede estar vacía." << endl;
                break;
            }
            raiz = registrarEstudiante(raiz, id, nombre, carrera);
            break;
        case 2:
            cout << "ID: ";
            cin >> id;
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear(); // Limpiar el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta
                break;
            }
            // Buscar el estudiante
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
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Eliminar estudiante
            raiz = eliminarEstudiante(raiz, id);
            break;
        case 4:
            // Mostrar estudiantes en inorden
            if (raiz == nullptr) {
                cout << "No hay estudiantes registrados." << endl;
            }
            else {
                inorden(raiz);
            }
            break;
        case 5:
            cout << "ID del Estudiante: ";
            cin >> id;
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Buscar estudiante
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                // Validación de código de materia único
                Materia* materiaActual = estudiante->listaMaterias;
                while (materiaActual != nullptr) {
                    if (materiaActual->codigo == codigo) {
                        cout << "Error: La materia ya está inscrita." << endl;
                        break;
                    }
                    materiaActual = materiaActual->siguiente;
                }
                if (materiaActual != nullptr) break; // Salir si la materia ya está inscrita
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
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Buscar estudiante
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
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Buscar estudiante
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
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Buscar estudiante
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                // Buscar materia
                Materia* materia = estudiante->listaMaterias;
                while (materia != nullptr && materia->codigo != codigo) {
                    materia = materia->siguiente;
                }
                if (materia != nullptr) {
                    cout << "Fecha de la Evaluacion: ";
                    cin >> fecha;
                    cout << "Nota Obtenida: ";
                    cin >> nota;
                    // Validación de nota
                    if (nota < 0 || nota > 20) {
                        cout << "Error: La nota debe estar entre 0 y 20." << endl;
                        break;
                    }
                    cout << "Ponderacion (%): ";
                    cin >> ponderacion;
                    // Validación de ponderación
                    if (ponderacion < 0 || ponderacion > 100) {
                        cout << "Error: La ponderación debe estar entre 0% y 100%." << endl;
                        break;
                    }
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
            // Validación de entrada numérica
            if (cin.fail()) {
                cout << "Error: Entrada no válida. Debe ingresar un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            // Buscar estudiante
            if (Estudiante* estudiante = buscarEstudiante(raiz, id)) {
                cout << "Codigo de la Materia: ";
                cin >> codigo;
                // Buscar materia
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
            cout << "Error: Opción no válida. Por favor, seleccione una opción del menú." << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
