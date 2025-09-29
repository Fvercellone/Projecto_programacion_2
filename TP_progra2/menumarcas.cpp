#include "MenuMarcas.h"
#include <iostream>
using namespace std;

void menuMarcas(ListaMarcas& listaMarcas) {
    int opcion;
    do {system("cls");
        cout << "\n=== MENU MARCAS ===\n";
        cout << "1. Agregar marca\n";
        cout << "2. Mostrar marcas\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                int idM;
                string nombreM;
                cout << "Ingrese ID de la marca: ";
                cin >> idM;
                cout << "Ingrese nombre de la marca: ";
                cin.ignore();
                getline(cin, nombreM);
                listaMarcas.agregarMarca(new Marca(idM, nombreM));
                system("cls");
                break;
            }
            case 2:
                listaMarcas.mostrarMarcas();
                system("pause");
                system("cls");
                break;
            case 0: break;
            default: cout << "Opcion invalida.\n";

        }
    } while(opcion != 0);
}
