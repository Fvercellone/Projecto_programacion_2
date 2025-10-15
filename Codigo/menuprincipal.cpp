#include "MenuPrincipal.h"
#include "MenuProductos.h"
#include "MenuMarcas.h"
#include <iostream>
using namespace std;

void menuPrincipal(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Productos\n";
        cout << "2. Marcas\n";
        cout << "3. Ventas (TODO)\n";
        cout << "4. Facturas (TODO)\n";
        cout << "5. Recibos (TODO)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: menuProductos(inventario, listaMarcas); system("cls"); ; break;
            case 2:  menuMarcas(listaMarcas, inventario); system("cls"); system("cls");  break;
            case 3: cout << "Modulo Ventas pendiente.\n"; system("cls");  break;
            case 4: cout << "Modulo Facturas pendiente.\n"; system("cls");  break;
            case 5: cout << "Modulo Recibos pendiente.\n"; system("cls");  break;
            case 0: cout << "Saliendo...\n"; system("cls");  break;
            default: cout << "Opcion invalida.\n"; system("cls");
        }
    } while(opcion != 0);
}
