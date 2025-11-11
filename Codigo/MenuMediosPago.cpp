#include "MenuMediosPago.h"
#include "ListaMediosPago.h"
#include <iostream>
#include <limits>

using namespace std;

MenuMediosPago::MenuMediosPago()
{
    // ctor
}

MenuMediosPago::~MenuMediosPago()
{
    // dtor
}

void MenuMediosPago::mostrarMenu() {
    ListaMediosPago lista;
    int opcion;

    do {
        cout << "\n=== GESTION DE MEDIOS DE PAGO ===" << endl;
        cout << "1. Agregar medio de pago" << endl;
        cout << "2. Mostrar todos los medios de pago" << endl;
        cout << "3. Mostrar medios de pago activos" << endl;
        cout << "4. Activar medio de pago" << endl;
        cout << "5. Desactivar medio de pago" << endl;
        cout << "6. Eliminar medio de pago (marcar como inactivo)" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarMedioPago(lista);
                break;
            case 2:
                lista.mostrarMediosPago();
                break;
            case 3:
                lista.mostrarMediosPagoActivos();
                break;
            case 4:
                activarMedioPago(lista);
                break;
            case 5:
                desactivarMedioPago(lista);
                break;
            case 6:
                eliminarMedioPago(lista);
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while(opcion != 0);
}

void MenuMediosPago::agregarMedioPago(ListaMediosPago& lista) {
    string nombre;
    double ajuste;

    cout << "\n--- AGREGAR MEDIO DE PAGO ---" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre del medio de pago: ";
    getline(cin, nombre);

    cout << "Ajuste (ejemplo: 0.9 para 10% descuento, 1.1 para 10% incremento, 1.0 sin ajuste): ";
    cin >> ajuste;

    // Validar ajuste
    if (ajuste <= 0) {
        cout << "Error: El ajuste debe ser un valor positivo." << endl;
        return;
    }

    MedioPago nuevoMedio(0, nombre, ajuste, true);
    lista.agregarMedioPago(nuevoMedio);
}

void MenuMediosPago::activarMedioPago(ListaMediosPago& lista) {
    int id;

    cout << "\n--- ACTIVAR MEDIO DE PAGO ---" << endl;
    cout << "Ingrese el ID del medio de pago a activar: ";
    cin >> id;

    lista.activarMedioPago(id);
}

void MenuMediosPago::desactivarMedioPago(ListaMediosPago& lista) {
    int id;

    cout << "\n--- DESACTIVAR MEDIO DE PAGO ---" << endl;
    cout << "Ingrese el ID del medio de pago a desactivar: ";
    cin >> id;

    lista.desactivarMedioPago(id);
}

void MenuMediosPago::eliminarMedioPago(ListaMediosPago& lista) {
    int id;

    cout << "\n--- ELIMINAR MEDIO DE PAGO ---" << endl;
    cout << "Ingrese el ID del medio de pago a eliminar (marcar como inactivo): ";
    cin >> id;

    lista.eliminarMedioPago(id);
}
