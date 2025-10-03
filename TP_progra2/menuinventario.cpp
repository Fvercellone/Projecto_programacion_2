#include "MenuInventario.h"
#include <iostream>
using namespace std;

void menuInventario(Inventario& inventario) {
    int opcion;
    do {system("cls");
        cout << "\n=== MENU INVENTARIO ===\n";
        cout << "1. Consultar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Ingresar stock\n";
        cout << "4. Descontar stock\n";
        cout << "5. Mostrar Inventario\n";
        cout << "6. Editar precio producto\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                int id;
                cout << "Ingrese ID producto: "; cin >> id;
                Producto* p = inventario.buscarProducto(id);
                if (p) p->mostrarInfo();
                else cout << "No encontrado.\n";
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID producto: "; cin >> id;
                inventario.eliminarProducto(id);
                system("cls");
                break;
            }
            case 3: {
                int id, cant;
                cout << "Ingrese ID producto: "; cin >> id;
                Producto* p = inventario.buscarProducto(id);
                if (p) {
                    cout << "Ingrese cantidad a ingresar: "; cin >> cant;
                    p->agregarStock(cant);
                    inventario.guardarProductos();
                    cout << "Stock actualizado.\n";
                  system("pause");
                } else cout << "Producto no encontrado.\n";
                system("cls");
                break;
            }
            case 4: {
                int id, cant;
                cout << "Ingrese ID producto: "; cin >> id;
                Producto* p = inventario.buscarProducto(id);
                if (p) {
                    cout << "Ingrese cantidad a descontar: "; cin >> cant;
                    p->quitarStock(cant);
                    inventario.guardarProductos();
                } else cout << "Producto no encontrado.\n";
                system("pause");
                system("cls");
                break;
            }
            case 5: {
                inventario.mostrarInventario();
                system("pause");
                system("cls");
                break;
            }
            case 6: {
                int id;
                float nuevoPrecio;
                cout << "Ingrese ID del producto: ";
                cin >> id;

                // Mostrar información actual del producto
                Producto* producto = inventario.buscarProducto(id);
                if (producto) {
                    cout << "Producto actual:\n";
                    producto->mostrarInfo();
                    cout << "\nIngrese nuevo precio: $";
                    cin >> nuevoPrecio;

                    inventario.editarPrecioProducto(id, nuevoPrecio);
                } else {
                    cout << "Producto no encontrado.\n";
                }
                system("pause");
                system("cls");
                break;
            }
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
