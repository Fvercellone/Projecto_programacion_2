#include "menuediciones.h"
#include <iostream>
using namespace std;

void menuEdiciones(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== MENU EDICIONES ===\n";
        cout << "1. Editar precio producto\n";
        cout << "2. Editar marca producto\n";
        cout << "3. Editar nombre producto\n";
        cout << "4. Editar descripción producto\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                int id;
                float nuevoPrecio;
                cout << "Ingrese ID del producto: ";
                cin >> id;

                Producto* producto = inventario.buscarProducto(id);
                if (producto) {
                    cout << "Producto actual:\n";
                    producto->mostrarInfo();
                    cout << "\nIngrese nuevo precio: $";
                    cin >> nuevoPrecio;
                    inventario.editarPrecioProducto(id, nuevoPrecio);
                } else cout << "Producto no encontrado.\n";
                system("pause");
                break;
            }

            case 2: {
                int id, nuevaMarca;
                cout << "Ingrese ID del producto: ";
                cin >> id;

                Producto* producto = inventario.buscarProducto(id);
                if (producto) {
                    cout << "Producto actual:\n";
                    producto->mostrarInfo();
                    cout << "\nMarcas disponibles:\n";
                    listaMarcas.mostrarMarcas();
                    cout << "\nIngrese nueva ID de marca: ";
                    cin >> nuevaMarca;
                    inventario.cambiarMarcaProducto(id, nuevaMarca, listaMarcas);
                } else cout << "Producto no encontrado.\n";
                system("pause");
                break;
            }

            case 3: {
                int id;
                string nuevoNombre;
                cout << "Ingrese ID del producto: ";
                cin >> id;

                Producto* producto = inventario.buscarProducto(id);
                if (producto) {
                    cout << "Producto actual:\n";
                    producto->mostrarInfo();
                    cout << "\nIngrese nuevo nombre: ";
                    cin.ignore();
                    getline(cin, nuevoNombre);
                    inventario.editarNombreProducto(id, nuevoNombre);
                } else cout << "Producto no encontrado.\n";
                system("pause");
                break;
            }

            case 4: {
                int id;
                string nuevaDesc;
                cout << "Ingrese ID del producto: ";
                cin >> id;

                Producto* producto = inventario.buscarProducto(id);
                if (producto) {
                    cout << "Producto actual:\n";
                    producto->mostrarInfo();
                    cout << "\nIngrese nueva descripción: ";
                    cin.ignore();
                    getline(cin, nuevaDesc);
                    inventario.editarDescripcionProducto(id, nuevaDesc);
                } else cout << "Producto no encontrado.\n";
                system("pause");
                break;
            }

            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}
