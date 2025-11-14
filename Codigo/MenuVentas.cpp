#include "MenuVentas.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuVentas::mostrarMenu(Inventario& inventario, ListaMediosPago& listaMediosPago, ListaVentas& listaVentas) {
    int opcion;

    do {
        cout << "\n=== GESTION DE VENTAS ===" << endl;
        cout << "1. Crear venta" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch(opcion) {
            case 1:
                system("cls");
                crearVenta(listaVentas, inventario, listaMediosPago);
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while(opcion != 0);
}

void MenuVentas::crearVenta(ListaVentas& listaVentas, Inventario& inventario, ListaMediosPago& listaMediosPago) {
    listaVentas.crearVenta(inventario, listaMediosPago);
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

