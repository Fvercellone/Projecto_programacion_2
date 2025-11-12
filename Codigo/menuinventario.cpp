#include "MenuInventario.h"
#include <iostream>
#include "ListaMarcas.h"
#include "Manejo_Archivos.h"
using namespace std;

void menuInventario(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {system("cls");
        cout << "\n=== MENU INVENTARIO ===\n";
        cout << "1. Consultar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Ingresar stock\n";
        cout << "4. Descontar stock\n";
        cout << "5. Mostrar Inventario\n";
        cout << "6. Mostrar productos inactivos\n";
        cout << "7. Mostrar productos activos\n";
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
                system("pause");
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
                    ManejadorArchivos::guardarProductos(inventario.getProductos());
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
                    ManejadorArchivos::guardarProductos(inventario.getProductos());
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

//            case 6: {  // Activar producto
//                int id;
//                cout << "Ingrese ID del producto a ACTIVAR: ";
//                cin >> id;
//                inventario.activarProducto(id);
//                system("pause");
//                system("cls");
//                break;
//            }
//            case 7: { // Desactivar producto
//                int id;
//                cout << "Ingrese ID del producto a DESACTIVAR: ";
//                cin >> id;
//                inventario.desactivarProducto(id);
//                system("pause");
//                system("cls");
//                break;
//            }
            case 6: { // Mostrar inactivos
                inventario.mostrarProductosInactivos();
                system("pause");
                system("cls");
                break;
            }

            case 7: { // Mostrar Activos
            inventario.mostrarProductosActivos();
            system("pause");
            system("cls");
            break;
            }

            case 0: break;
            default: cout << "Opcion invalida.\n"; system("cls");
        }
    } while(opcion != 0);
}
