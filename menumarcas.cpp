#include "MenuMarcas.h"

#include <iostream>
using namespace std;

void menuMarcas(ListaMarcas& listaMarcas, Inventario& inventario) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== GESTION DE MARCAS ===\n";
        cout << "1. Crear Marca\n";
        cout << "2. Mostrar Marcas\n";
        cout << "3. Eliminar Marca\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                string nombre;

                cout << "Ingrese nombre de la marca: ";
                cin.ignore();
                getline(cin, nombre);

                Marca nuevaMarca(0, nombre);  // ID temporal (0)
                listaMarcas.agregarMarca(nuevaMarca);

                system("pause");
                system("cls");
                break;
            }

            case 2: {
                listaMarcas.mostrarMarcas();
                system("pause");
                system("cls");
                break;
            }

            case 3: {
                int id;
                cout << "Ingrese ID de la marca a eliminar: ";
                cin >> id;
                listaMarcas.eliminarMarca(id, inventario);
                system("pause");
                system("cls");
                break;
            }

            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
