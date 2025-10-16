#include "MenuProductos.h"
#include "MenuInventario.h"
#include "MenuEdiciones.h"
#include "SeleccionFunciones.h"

#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;



void menuProductos(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== MENU PRODUCTOS ===\n";
        cout << "1. Crear Producto\n";
        cout << "2. Inventario\n";
        cout << "3. Gestionar Marcas\n";
        cout << "4. Editar producto\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                int stock;
                string nombre, desc;
                float precio;

                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese descripcion: ";
                getline(cin, desc);
                cout << "Ingrese precio: ";
                cin >> precio;
                cout << "Ingrese stock: ";
                cin >> stock;

                // --- NUEVO SISTEMA DE SELECCIÓN DE MARCA ---
                int idM = seleccionarMarca(listaMarcas);




                system("pause");
                system("cls");
                break;
            }

            case 2:
                menuInventario(inventario, listaMarcas);
                system("cls");
                break;

            case 3:
                menuMarcas(listaMarcas, inventario);
                system("cls");
                break;

            case 4:
                menuEdiciones(inventario, listaMarcas);
                system("cls");
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }
    } while(opcion != 0);
}
