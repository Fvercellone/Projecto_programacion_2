#include "MenuInventario.h"
#include <iostream>
using namespace std;

void menuInventario(Inventario& inventario) {
    int opcion;
    do {
        cout << "\n=== MENU INVENTARIO ===\n";
        cout << "1. Consultar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Ingresar stock\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int id;
                cout << "Ingrese ID producto: "; cin >> id;
                Producto* p = inventario.buscarProducto(id);
                if (p) p->mostrarInfo();
                else cout << "No encontrado.\n";
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID producto: "; cin >> id;
                inventario.eliminarProducto(id);
                break;
            }
            case 3: {
                int id, cant;
                cout << "Ingrese ID producto: "; cin >> id;
                Producto* p = inventario.buscarProducto(id);
                if (p) {
                    cout << "Ingrese cantidad a ingresar: "; cin >> cant;
                    p->agregarStock(cant);
                    cout << "Stock actualizado.\n";
                } else cout << "Producto no encontrado.\n";
                break;
            }
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);
}
