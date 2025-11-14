#include "MenuFacturas.h"
#include "Manejo_Archivos.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuFacturas::mostrarMenu(Inventario& inventario) {
    int opcion;

    do {
        cout << "\n=== HISTORIAL Y REPORTES DE FACTURAS ===" << endl;
        cout << "1. Ver todas las facturas" << endl;
        cout << "2. Buscar factura por ID" << endl;
        cout << "3. Realizar devolución" << endl;           // ← NUEVA
        cout << "4. Ver todas las devoluciones" << endl;    // ← NUEVA
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarTodasFacturas();
                break;
            case 2:
                buscarFacturaPorID();
                break;
            case 3:
                realizarDevolucion(inventario);  // ← NUEVA
                break;
            case 4:
                mostrarTodasDevoluciones();  // ← NUEVA
                break;
            case 0:
                cout << "Volviendo..." << endl;
                system("cls");
                break;
            default:
                cout << "Opcion no valida." << endl;
                system("cls");
        }
    } while(opcion != 0);
}

    void MenuFacturas::mostrarTodasFacturas() {
        system("cls");
        cout << "\n--- TODAS LAS FACTURAS ---\n";
        vector<Factura> facturas = ManejadorArchivos::cargarFacturas();

        if (facturas.empty()) {
            cout << "No hay facturas registradas.\n";
            system("pause");
            system("cls");
            return;
        }

        for (const auto& factura : facturas) {
            factura.mostrarFactura();
        }
        cout << "Total facturas: " << facturas.size() << "\n";

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    void MenuFacturas::buscarFacturaPorID() {
        system("cls");
        int idFactura;
        cout << "\n--- BUSCAR FACTURA POR ID ---\n";
        cout << "Ingrese ID de factura: ";
        cin >> idFactura;

        vector<Factura> facturas = ManejadorArchivos::cargarFacturas();
        bool encontrada = false;

        for (const auto& factura : facturas) {
            if (factura.getIdFactura() == idFactura) {
                factura.mostrarFacturaCompleta();
                encontrada = true;
                break;
            }
        }

        if (!encontrada) {
            cout << "Factura no encontrada.\n";
            system("pause");
            system("cls");
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    // ========== FUNCIÓN NUEVA: REALIZAR DEVOLUCIÓN ==========
    void MenuFacturas::realizarDevolucion(Inventario& inventario) {
        system("cls");
        cout << "\n--- REALIZAR DEVOLUCIÓN ---\n";

        // Cargar facturas existentes
        vector<Factura> facturas = ManejadorArchivos::cargarFacturas();
        if (facturas.empty()) {
            cout << "No hay facturas para realizar devoluciones.\n";
            system("pause");
            system("cls");
            return;
        }

        // Mostrar facturas disponibles
        cout << "FACTURAS DISPONIBLES:\n";
        for (const auto& factura : facturas) {
            factura.mostrarFactura();
        }

        // Seleccionar factura
        int idFactura;
        cout << "Ingrese ID de la factura a devolver: ";
        cin >> idFactura;
        system("cls");
        // Buscar factura
        Factura* facturaSeleccionada = nullptr;
        for (auto& factura : facturas) {
            if (factura.getIdFactura() == idFactura) {
                facturaSeleccionada = &factura;
                break;
            }
        }

        if (!facturaSeleccionada) {
            cout << "Error: Factura no encontrada.\n";
            system("pause");
            system("cls");
            return;
        }

        // Mostrar factura completa
        cout << "\n--- FACTURA SELECCIONADA ---\n";
        facturaSeleccionada->mostrarFacturaCompleta();

        // Crear devolución
        Devolucion nuevaDevolucion;
        nuevaDevolucion.setFacturaOriginal(facturaSeleccionada->getIdFactura(),
                                          facturaSeleccionada->getNombreCliente(),
                                          facturaSeleccionada->getRucCliente());

        // Motivo de devolución
        string motivo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese motivo de la devolución: ";
        getline(cin, motivo);
        nuevaDevolucion.setMotivo(motivo);
        system("cls");

        // Seleccionar productos a devolver (simplificado por ahora)
        cout << "\n--- PRODUCTOS DE LA FACTURA ---\n";
        // Nota: Aquí necesitaríamos acceder a los items de la venta original
        // Por ahora, haremos una versión simplificada

        cout << "Funcionalidad de selección de productos en desarrollo...\n";
        cout << "Por ahora, se creará una devolución básica.\n";

        // Guardar devolución
        vector<Devolucion> devoluciones = ManejadorArchivos::cargarDevoluciones();
        int ultimoID = ManejadorArchivos::cargarUltimoIDDevolucion();
        int nuevoID = ultimoID + 1;

        nuevaDevolucion.setIdDevolucion(nuevoID);

        devoluciones.push_back(nuevaDevolucion);
        ManejadorArchivos::guardarDevoluciones(devoluciones);
        ManejadorArchivos::guardarUltimoIDDevolucion(nuevoID);

        cout << "\n=== DEVOLUCIÓN REGISTRADA ===\n";
        nuevaDevolucion.mostrarDevolucionCompleta();
        cout << "ID de devolución: " << nuevoID << "\n";

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    // ========== FUNCIÓN NUEVA: MOSTRAR DEVOLUCIONES ==========
    void MenuFacturas::mostrarTodasDevoluciones() {
        system("cls");
        cout << "\n--- TODAS LAS DEVOLUCIONES ---\n";
        vector<Devolucion> devoluciones = ManejadorArchivos::cargarDevoluciones();

        if (devoluciones.empty()) {
            cout << "No hay devoluciones registradas.\n";
            system("pause");
            system("cls");
            return;
        }

        for (const auto& devolucion : devoluciones) {
            devolucion.mostrarDevolucion();
        }
        cout << "Total devoluciones: " << devoluciones.size() << "\n";

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("cls");
    }
