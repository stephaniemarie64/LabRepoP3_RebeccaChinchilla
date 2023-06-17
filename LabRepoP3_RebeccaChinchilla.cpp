#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

struct Matriz {
    int filas;
    int columnas;
    int** datos;
};

// Funcion para generar una matriz con valores aleatorios
Matriz generarMatriz(int filas, int columnas) {
    Matriz matriz;
    matriz.filas = filas;
    matriz.columnas = columnas;
    matriz.datos = new int* [filas];
    srand(time(0)); // random
    for (int i = 0; i < filas; i++) {
        matriz.datos[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz.datos[i][j] = rand() % 101 - 50; // Generar valores aleatorios en el rango [-50, 50]
        }
    }
    return matriz;
}

// Funcion para liberar la memoria de una matriz
void liberarMatriz(Matriz& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        delete[] matriz.datos[i];
    }
    delete[] matriz.datos;
}

// Funcion para mostrar una matriz en la consola
void mostrarMatriz(const Matriz& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        for (int j = 0; j < matriz.columnas; j++) {
            cout << setw(5) << matriz.datos[i][j] << " "; // Utilizamos setw(5) para alinear las columnas
        }
        cout << endl;
    }
}

void opcion1() {
    cout << "Seleccionaste la opcion 1" << endl;
}

void opcion2() {
    cout << "Seleccionaste la opcion 2" << endl;
}


void mostrarMenu() {
    int opcion;

    do {
        // Mostrar el menú
        cout << "MENU" << endl;
        cout << "1. Generar matriz" << endl;
        cout << "2. Realizar operaciones entre matrices" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cout << endl;

        // Realizar acciones según la opcion seleccionada
        switch (opcion) {
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 3);
}

int main() {
    mostrarMenu();
    return 0;
}
