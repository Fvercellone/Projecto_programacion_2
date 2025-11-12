#include "MenuFacturas.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuFacturas::mostrarMenu(ListaVentas& listaVentas) {
    ListaFacturas listaFacturas;
    int opcion;

    do {
        cout << "\n=== GESTION DE FACTURAS ===" << endl;
        cout << "1. Generar factura" << endl;
        cout << "2. Mostrar todas las facturas" << endl;
        cout << "3. Mostrar facturas activas" << endl;
        cout << "4. Mostrar factura completa" << endl;
        cout << "5. Anular factura" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch(opcion) {
            case 1:
                system("cls");
                generarFactura(listaFacturas, listaVentas);
                break;
            case 2:
                system("cls");
                mostrarFacturas(listaFacturas);
                break;
            case 3:
                system("cls");
                mostrarFacturasActivas(listaFacturas);
                break;
            case 4:
                system("cls");
                mostrarFacturaCompleta(listaFacturas);
                break;
            case 5:
                system("cls");
                anularFactura(listaFacturas);
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                system("cls");
        }
    } while(opcion != 0);
}

void MenuFacturas::generarFactura(ListaFacturas& listaFacturas, ListaVentas& listaVentas) {
    listaFacturas.generarFactura(listaVentas);
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void MenuFacturas::anularFactura(ListaFacturas& listaFacturas) {
    int idFactura;

    cout << "\n--- ANULAR FACTURA ---" << endl;
    cout << "Ingrese el ID de la factura a anular: ";
    cin >> idFactura;

    listaFacturas.anularFactura(idFactura);
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void MenuFacturas::mostrarFacturas(const ListaFacturas& listaFacturas) {
    listaFacturas.mostrarFacturas();
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void MenuFacturas::mostrarFacturasActivas(const ListaFacturas& listaFacturas) {
    listaFacturas.mostrarFacturasActivas();
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void MenuFacturas::mostrarFacturaCompleta(const ListaFacturas& listaFacturas) {
    int idFactura;

    cout << "\n--- MOSTRAR FACTURA COMPLETA ---" << endl;
    cout << "Ingrese el ID de la factura: ";
    cin >> idFactura;

    listaFacturas.mostrarFacturaCompleta(idFactura);
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}
