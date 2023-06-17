#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

struct Matriz {//esto es para que sea publico y todos lo puedan usar
    int filas;
    int columnas;
    int** datos;
};

// Funcion para generar una matriz con valores aleatorios
Matriz Imatriz(int filas, int columnas) {
    Matriz matriz;
    matriz.filas = filas;
    matriz.columnas = columnas;
    matriz.datos = new int* [filas];
    srand(time(0)); // random
    for (int i = 0; i < filas; i++) {
        matriz.datos[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz.datos[i][j] = rand() % 101 - 50; //esto genrera valores aleatorios en el rango [-50, 50]
        }
    }
    return matriz;
}

// Funcion para liberar la memoria de una matriz
void free(Matriz& matriz) {
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

// Funcion para realizar la suma de dos matrices
Matriz sumMatriz(const Matriz& matriz1, const Matriz& matriz2) {
    Matriz ANS;
    ANS.filas = matriz1.filas;
    ANS.columnas = matriz1.columnas;
    ANS.datos = new int* [ANS.filas];

    for (int i = 0; i < ANS.filas; i++) {
        ANS.datos[i] = new int[ANS.columnas];
        for (int j = 0; j < ANS.columnas; j++) {
            ANS.datos[i][j] = matriz1.datos[i][j] + matriz2.datos[i][j];
        }
    }
    return ANS;
}

// Funcion para realizar la resta de dos matrices
Matriz lessMatrices(const Matriz& matriz1, const Matriz& matriz2) {
    Matriz ANS;
    ANS.filas = matriz1.filas;
    ANS.columnas = matriz1.columnas;
    ANS.datos = new int* [ANS.filas];

    for (int i = 0; i < ANS.filas; i++) {
        ANS.datos[i] = new int[ANS.columnas];
        for (int j = 0; j < ANS.columnas; j++) {
            ANS.datos[i][j] = matriz1.datos[i][j] - matriz2.datos[i][j];
        }
    }
    return ANS;
}

// Funcion para realizar la multiplicación de dos matrices
Matriz mMatriz(const Matriz& matriz1, const Matriz& matriz2) {
    Matriz ANS;
    ANS.filas = matriz1.filas;
    ANS.columnas = matriz2.columnas;
    ANS.datos = new int* [ANS.filas];

    for (int i = 0; i < ANS.filas; i++) {
        ANS.datos[i] = new int[ANS.columnas];
        for (int j = 0; j < ANS.columnas; j++) {
            ANS.datos[i][j] = 0;
            for (int k = 0; k < matriz1.columnas; k++) {
                ANS.datos[i][j] += matriz1.datos[i][k] * matriz2.datos[k][j];
            }
        }
    }
    return ANS;
}

// Funcion para realizar las operaciones entre matrices
void op(const vector<Matriz*>& matrices, int numMatriz1, int numMatriz2, char opr) {
    if (numMatriz1 >= 0 && numMatriz1 < matrices.size() && numMatriz2 >= 0 && numMatriz2 < matrices.size()) {
        Matriz matriz1 = *matrices[numMatriz1];
        Matriz matriz2 = *matrices[numMatriz2];
        Matriz ANS;

        switch (opr) {
        case '+':
            if (matriz1.filas == matriz2.filas && matriz1.columnas == matriz2.columnas) {
                ANS = sumMatriz(matriz1, matriz2);
                cout << "Resultado de la suma:" << endl;
                mostrarMatriz(ANS);
            }else {
                cout << "Error: Las matrices deben tener las mismas dimensiones para realizar la suma." << endl;
            }
            break;
        case '-':
            if (matriz1.filas == matriz2.filas && matriz1.columnas == matriz2.columnas) {
                ANS = lessMatrices(matriz1, matriz2);
                cout << "Resultado de la resta:" << endl;
                mostrarMatriz(ANS);
            }else {
                cout << "Error: Las matrices deben tener las mismas dimensiones para realizar la resta." << endl;
            }
            break;
        case '*':
            if (matriz1.columnas == matriz2.filas) {
                ANS = mMatriz(matriz1, matriz2);
                cout << "Resultado de la multiplicacion:" << endl;
                mostrarMatriz(ANS);
            }else {
                cout << "Error: El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz para realizar la multiplicacion." << endl;
            }
            break;
        default:
            cout << "Error: opr invalida. Intente de nuevo con alguno de estos simbolos(*,+,-)." << endl;
        }
    } else {
        cout << "Error: el numero de matriz invalidos." << endl;
    }
}

// Funcion para el menu principal
void mostrarMenu(vector<Matriz*>& matrices) {
    int opcion;

    do {
        // Mostrar el menu
        cout << "MENU" << endl;
        cout << "1. Generar matriz" << endl;
        cout << "2. Realizar operaciones entre matrices" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cout << endl;

        // Realizar acciones segun la opcion seleccionada
        switch (opcion) {
        case 1:
            int filas, columnas;
            cout << "Generarador de Matrices" << endl << endl;
            cout << "Ingrese el numero de filas de la matriz: ";
            cin >> filas;
            cout << "Ingrese el numero de columnas de la matriz: ";
            cin >> columnas;
            if (filas >= 2 && columnas >= 2) {
                Matriz* matriz = new Matriz;
                *matriz = Imatriz(filas, columnas);
                matrices.push_back(matriz);
                cout << endl << "Matriz generada:" << endl;
                mostrarMatriz(*matriz);
            }else {
                cout << "Error: El numero de filas y columnas debe ser mayor o igual a 2." << endl;
            }
            break;
        case 2:
            if (matrices.empty()) {
                cout << "Error: No hay matrices disponibles para realizar operaciones." << endl;
            }else {
                cout << "Matrices disponibles:" << endl;
                for (int i = 0; i < matrices.size(); i++) {
                    cout << "Matriz " << i + 1 << ":" << endl;
                    mostrarMatriz(*matrices[i]);
                    cout << endl;
                }
                int numMatriz1, numMatriz2;
                char opr;

                cout << "Ingrese el numero de la primera matriz elegida: ";
                cin >> numMatriz1;
                cout << "Ingrese el numero de la segunda matriz elegida: ";
                cin >> numMatriz2;
                cout << "Ingrese la opr a realizar (+ para suma, - para resta, * para multiplicacion): ";
                cin >> opr;
                cout << endl;
                op(matrices, numMatriz1 - 1, numMatriz2 - 1, opr);
            }
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while (opcion != 3);
    // Liberar la memoria de las matrices generadas
    for (int i = 0; i < matrices.size(); i++) {
        free(*matrices[i]);
        delete matrices[i];
    }
}

int main() {
    vector<Matriz*> matrices;
    mostrarMenu(matrices);
    return 0;
}