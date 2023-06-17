#include <iostream>

using namespace std;

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
