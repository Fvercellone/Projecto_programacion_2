#include "ListaFacturas.h"
#include "Manejo_Archivos.h"
#include <iostream>
#include <limits>

using namespace std;

ListaFacturas::ListaFacturas() {
    facturas = ManejadorArchivos::cargarFacturas();
    ultimoID = ManejadorArchivos::cargarUltimoIDFactura();
}

void ListaFacturas::generarFactura(ListaVentas& listaVentas) {
    cout << "\n--- GENERAR FACTURA ---\n";

    // Mostrar ventas activas sin factura
    cout << "VENTAS ACTIVAS SIN FACTURA:\n";
    const auto& ventas = listaVentas.getVentas();
    bool hayVentasSinFactura = false;

    for (const auto& venta : ventas) {
        if (venta.getActivo()) {
            // Verificar si ya tiene factura
            bool tieneFactura = false;
            for (const auto& factura : facturas) {
                if (factura.getIdVenta() == venta.getIdVenta() && factura.getActivo()) {
                    tieneFactura = true;
                    break;
                }
            }

            if (!tieneFactura) {
                venta.mostrarVenta();
                hayVentasSinFactura = true;
            }
        }
    }

    if (!hayVentasSinFactura) {
        cout << "No hay ventas activas sin factura.\n";
        return;
    }

    // Seleccionar venta
    int idVenta;
    cout << "Ingrese ID de la venta a facturar: ";
    cin >> idVenta;

    Venta* venta = listaVentas.buscarVenta(idVenta);
    if (!venta || !venta->getActivo()) {
        cout << "Error: Venta no encontrada o inactiva.\n";
        return;
    }

    // Verificar si ya tiene factura
    for (const auto& factura : facturas) {
        if (factura.getIdVenta() == idVenta && factura.getActivo()) {
            cout << "Error: Esta venta ya tiene una factura activa.\n";
            return;
        }
    }

        // Datos del cliente - SOLO PARA LA FACTURA
    string nombre, ruc, direccion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre del cliente (Enter para CONSUMIDOR FINAL): ";
    getline(cin, nombre);
    if (nombre.empty()) nombre = "CONSUMIDOR FINAL";

    cout << "Ingrese su DNI (Enter para 9999999999999): ";
    getline(cin, ruc);
    if (ruc.empty()) ruc = "9999999999999";

    cout << "Direccion (Enter para NO ESPECIFICADA): ";
    getline(cin, direccion);
    if (direccion.empty()) direccion = "NO ESPECIFICADA";

    // Crear factura
    Factura nuevaFactura;
    nuevaFactura.generarDesdeVenta(*venta);
    nuevaFactura.setCliente(nombre, ruc, direccion);

    int nuevoID = generarNuevoID();
    nuevaFactura.setIdFactura(nuevoID);

    facturas.push_back(nuevaFactura);
    ManejadorArchivos::guardarFacturas(facturas);

    system("cls");

    cout << "\n=== FACTURA GENERADA ===\n";
    nuevaFactura.mostrarFacturaCompleta();
    cout << "ID de factura: " << nuevoID << "\n";
}

void ListaFacturas::anularFactura(int idFactura) {
    Factura* factura = buscarFactura(idFactura);
    if (factura && factura->getActivo()) {
        factura->setActivo(false);
        ManejadorArchivos::guardarFacturas(facturas);
        cout << "Factura anulada exitosamente.\n";
    } else {
        cout << "Error: Factura no encontrada o ya anulada.\n";
    }
}

void ListaFacturas::mostrarFacturas() const {
    cout << "=== TODAS LAS FACTURAS ===\n";
    if (facturas.empty()) {
        cout << "No hay facturas registradas.\n";
        return;
    }

    for (const auto& factura : facturas) {
        factura.mostrarFactura();
    }
    cout << "Total facturas: " << facturas.size() << "\n";
}

void ListaFacturas::mostrarFacturasActivas() const {
    cout << "=== FACTURAS ACTIVAS ===\n";
    int contador = 0;
    for (const auto& factura : facturas) {
        if (factura.getActivo()) {
            factura.mostrarFactura();
            contador++;
        }
    }
    cout << "Total facturas activas: " << contador << "\n";
}

void ListaFacturas::mostrarFacturaCompleta(int idFactura) const {
    for (const auto& factura : facturas) {
        if (factura.getIdFactura() == idFactura) {
            factura.mostrarFacturaCompleta();
            return;
        }
    }
    cout << "Error: Factura no encontrada.\n";
}

Factura* ListaFacturas::buscarFactura(int id) {
    for (auto& factura : facturas) {
        if (factura.getIdFactura() == id) {
            return &factura;
        }
    }
    return nullptr;
}

const std::vector<Factura>& ListaFacturas::getFacturas() const {
    return facturas;
}

int ListaFacturas::generarNuevoID() {
    ultimoID++;
    ManejadorArchivos::guardarUltimoIDFactura(ultimoID);
    return ultimoID;
}
