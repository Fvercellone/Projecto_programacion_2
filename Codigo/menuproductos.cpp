#include "MenuProductos.h"
#include "MenuInventario.h"
#include "MenuEdiciones.h"

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <windows.h>

using namespace std;

// --- NUEVA FUNCIÓN ---
// Muestra las marcas de 10 en 10 y permite elegir con flechas ↑ ↓ ← → + Enter
int seleccionarMarca(ListaMarcas& listaMarcas) {
    const vector<Marca>& marcas = listaMarcas.getMarcas();  // requiere getMarcas() en ListaMarcas
    if (marcas.empty()) {
        cout << "No hay marcas registradas.\n";
        system("pause");
        return -1;
    }

    int pagina = 0;
    int seleccion = 0;
    int totalMarcas = marcas.size();
    const int porPagina = 10;

    while (true) {
        system("cls");
        cout << "=== SELECCIONAR MARCA ===\n\n";

        int inicio = pagina * porPagina;
        int fin = min(inicio + porPagina, totalMarcas);

        for (int i = inicio; i < fin; ++i) {
            if (i == seleccion)
                cout << " > ";
            else
                cout << "   ";

            cout << "[" << marcas[i].getIdMarca() << "] "
                 << marcas[i].getNombre() << "\n";
        }

        SetConsoleOutputCP(CP_UTF8);
        cout << "\nUsa ↑ ↓ para moverte, ← → para cambiar pagina, ENTER para seleccionar.\n";
        int tecla = _getch();

        if (tecla == 72 && seleccion > 0) seleccion--;                     // ↑
        else if (tecla == 80 && seleccion < totalMarcas - 1) seleccion++;  // ↓
        else if (tecla == 75 && pagina > 0) {                              // ←
            pagina--;
            seleccion = pagina * porPagina;
        }
        else if (tecla == 77 && fin < totalMarcas) {                       // →
            pagina++;
            seleccion = pagina * porPagina;
        }
        else if (tecla == 13) {                                            // ENTER
            system("cls");
            cout << "Marca seleccionada: " << marcas[seleccion].getNombre() << "\n";
            return marcas[seleccion].getIdMarca();
        }
    }
}

void menuProductos(Inventario& inventario, ListaMarcas& listaMarcas) {
    int opcion;
    do {
        system("cls");
        cout << "\n=== MENU PRODUCTOS ===\n";
        cout << "1. Crear Producto\n";
        cout << "2. Inventario\n";
        cout << "3. Gestionar Marcas\n";
        cout << "4. Editar producto\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: {
                int stock;
                string nombre, desc;
                float precio;

                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese descripcion: ";
                getline(cin, desc);
                cout << "Ingrese precio: ";
                cin >> precio;
                cout << "Ingrese stock: ";
                cin >> stock;

                // --- NUEVO SISTEMA DE SELECCIÓN DE MARCA ---
                int idM = seleccionarMarca(listaMarcas);
                if (idM == -1) {
                    cout << "Operación cancelada.\n";
                    system("pause");
                    break;
                }

                if (listaMarcas.buscarMarca(idM)) {
                    Producto nuevoProducto(0, nombre, desc, precio, stock, idM);
                    inventario.agregarProducto(nuevoProducto);
                } else {
                    cout << "ERROR: Marca inexistente.\n";
                }

                system("pause");
                system("cls");
                break;
            }

            case 2:
                menuInventario(inventario, listaMarcas);
                system("cls");
                break;

            case 3:
                menuMarcas(listaMarcas, inventario);
                system("cls");
                break;

            case 4:
                menuEdiciones(inventario, listaMarcas);
                system("cls");
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }
    } while(opcion != 0);
}
