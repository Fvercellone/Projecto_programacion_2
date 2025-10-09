#include "MenuProductos.h"
#include "MenuInventario.h"
#include <iostream>
using namespace std;

void menuProductos(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== MENU PRODUCTOS ===\n";
        cout << "1. Crear Producto\n";
        cout << "2. Inventario\n";
        cout << "3. Gestionar Marcas\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                int stock, idM;
                string nombre, desc;
                float precio;

                cout << "Ingrese nombre: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese descripcion: "; getline(cin, desc);
                cout << "Ingrese precio: "; cin >> precio;
                cout << "Ingrese stock: "; cin >> stock;

                    //AGREGAR: Mostrar marcas disponibles
                cout <<""<<endl;
                listaMarcas.mostrarMarcas();
                cout << "--------------\n"<<endl;

                cout << "Ingrese ID de la marca: "; cin >> idM;

                if (listaMarcas.buscarMarca(idM)) {
                    Producto nuevoProducto(0, nombre, desc, precio, stock, idM);
                    inventario.agregarProducto(nuevoProducto);
                } else {
                    cout << "ERROR: Marca inexistente.\n";
                }
                system("pause");
                system("cls");
                break;
            }

            case 2:
                menuInventario(inventario, listaMarcas);  // ← AGREGAR listaMarcas
                system("cls");
                break;

            case 3:
                menuMarcas(listaMarcas, inventario);
                system("cls");
                break;

            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
