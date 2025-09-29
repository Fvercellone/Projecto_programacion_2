#include "MenuProductos.h"
#include "MenuInventario.h"
#include <iostream>
using namespace std;

void menuProductos(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        cout << "\n=== MENU PRODUCTOS ===\n";
        cout << "1. Crear Producto\n";
        cout << "2. Inventario\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int idP, stock, idM;
                string nombre, desc;
                float precio;

                cout << "Ingrese ID Producto: "; cin >> idP;
                cout << "Ingrese nombre: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese descripcion: "; getline(cin, desc);
                cout << "Ingrese precio: "; cin >> precio;
                cout << "Ingrese stock: "; cin >> stock;
                cout << "Ingrese ID de la marca: "; cin >> idM;

                if (listaMarcas.buscarMarca(idM)) {
                    inventario.agregarProducto(new Producto(idP, nombre, desc, precio, stock, idM));
                } else {
                    cout << "ERROR: Marca inexistente.\n";
                }
                break;
            }
            case 2: menuInventario(inventario); break;
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
