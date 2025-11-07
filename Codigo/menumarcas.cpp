#include "MenuMarcas.h"
#include <iostream>
using namespace std;

void menuMarcas(ListaMarcas& listaMarcas, Inventario& inventario) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== GESTION DE MARCAS ===\n";
        cout << "1. Crear Marca\n";
        cout << "2. Mostrar Todas las Marcas\n";
        cout << "3. Desactivar Marca\n";
        cout << "4. Activar Marca\n";
        cout << "5. Mostrar Marcas Inactivas\n";
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
            case 3: {  // Desactivar marca
                int id;
                cout << "Ingrese ID de la marca a DESACTIVAR: ";
                cin >> id;
                listaMarcas.desactivarMarca(id);
                system("pause");
                system("cls");
                break;
            }
            case 4: {  // Activar marca
                int id;
                cout << "Ingrese ID de la marca a ACTIVAR: ";
                cin >> id;
                listaMarcas.activarMarca(id);
                system("pause");
                system("cls");
                break;
            }
            case 5: {  // Mostrar marcas inactivas
                listaMarcas.mostrarMarcasInactivas();
                system("pause");
                system("cls");
                break;
            }
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
