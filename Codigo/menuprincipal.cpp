#include "MenuPrincipal.h"
#include "MenuProductos.h"
#include "MenuMarcas.h"
#include "MenuMediosPago.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void menuPrincipal(Inventario& inventario, ListaMarcas& listaMarcas) {
    // Inicializar los otros módulos - CREAR UNA SOLA INSTANCIA
    ListaMediosPago listaMediosPago;
    MenuVentas menuVentas;
    MenuFacturas menuFacturas;
    ListaVentas listaVentas;  // ← MISMA instancia para ventas y facturas

    int opcion;
    do {
        system("cls");
        cout << "========================================\n";
        cout << "       SISTEMA DE GESTION COMERCIAL\n";
        cout << "           PROYECTO UNIVERSIDAD\n";
        cout << "========================================\n";
        cout << "1. Gestion de Productos\n";
        cout << "2. Gestion de Marcas\n";
        cout << "3. Gestion de Medios de Pago\n";
        cout << "4. Gestion de Ventas\n";
        cout << "5. Historial y Reportes de Facturas\n";
        cout << "0. Salir del Sistema\n";
        cout << "========================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                system("cls");
                menuProductos(inventario, listaMarcas);
                system("cls");
                break;

            case 2:
                system("cls");
                menuMarcas(listaMarcas, inventario);
                system("cls");
                break;

            case 3:
                system("cls");
                {
                    MenuMediosPago menuMP;
                    menuMP.mostrarMenu();
                }
                system("cls");
                break;

            case 4:
                system("cls");
                menuVentas.mostrarMenu(inventario, listaMediosPago, listaVentas); // ← 3 parámetros
                system("cls");
                break;

            case 5:
                system("cls");
                {
                    MenuFacturas menuFacturas;
                    menuFacturas.mostrarMenu(inventario);  // ← Solo inventario como parámetro
                }
                system("cls");
                break;

            case 0:
                system("cls");
                cout << "Gracias por usar el sistema. ¡Hasta pronto!\n";
                break;

            default:
                system("cls");
                cout << "Opcion no valida. Intente nuevamente.\n";
                system("pause");
        }
    } while(opcion != 0);
}
