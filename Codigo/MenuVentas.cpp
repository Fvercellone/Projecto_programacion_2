#include "MenuVentas.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuVentas::mostrarMenu(Inventario& inventario, ListaMediosPago& listaMediosPago) {
    ListaVentas listaVentas;
    int opcion;

    do {
        cout << "\n=== GESTION DE VENTAS ===" << endl;
        cout << "1. Crear venta" << endl;
        cout << "2. Mostrar todas las ventas" << endl;
        cout << "3. Mostrar ventas activas" << endl;
        cout << "4. Anular venta" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch(opcion) {
            case 1:
                crearVenta(listaVentas, inventario, listaMediosPago);
                break;
            case 2:
                mostrarVentas(listaVentas);
                break;
            case 3:
                mostrarVentasActivas(listaVentas);
                break;
            case 4:
                anularVenta(listaVentas);
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
}

void MenuVentas::anularVenta(ListaVentas& listaVentas) {
    int idVenta;

    cout << "\n--- ANULAR VENTA ---" << endl;
    cout << "Ingrese el ID de la venta a anular: ";
    cin >> idVenta;

    listaVentas.anularVenta(idVenta);
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void MenuVentas::mostrarVentas(const ListaVentas& listaVentas) {
    listaVentas.mostrarVentas();
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void MenuVentas::mostrarVentasActivas(const ListaVentas& listaVentas) {
    listaVentas.mostrarVentasActivas();
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}
