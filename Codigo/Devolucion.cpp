#include "Devolucion.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Implementación de ItemDevolucion
ItemDevolucion::ItemDevolucion(int idProd, const std::string& nombre, int cant, float precio)
    : idProducto(idProd), nombreProducto(nombre), cantidad(cant), precioUnitario(precio) {}

int ItemDevolucion::getIdProducto() const { return idProducto; }
std::string ItemDevolucion::getNombreProducto() const { return nombreProducto; }
int ItemDevolucion::getCantidad() const { return cantidad; }
float ItemDevolucion::getPrecioUnitario() const { return precioUnitario; }
float ItemDevolucion::getSubtotal() const { return cantidad * precioUnitario; }

void ItemDevolucion::mostrarInfo() const {
    cout << "  Producto[" << idProducto << "] " << nombreProducto
         << " | Cant: " << cantidad
         << " | $" << precioUnitario
         << " | Subtotal: $" << getSubtotal() << "\n";
}

// Implementación de Devolucion
Devolucion::Devolucion(int idDev, int idFactura, const std::string& fecha,
                       const std::string& cliente, const std::string& ruc,
                       const std::string& mot)
    : idDevolucion(idDev), idFacturaOriginal(idFactura), fechaHora(fecha),
      nombreCliente(cliente), rucCliente(ruc), motivo(mot),
      totalDevolucion(0), activa(true) {

    if (fecha.empty()) {
        fechaHora = obtenerFechaHoraActual();
    }
}

// Getters
int Devolucion::getIdDevolucion() const { return idDevolucion; }
int Devolucion::getIdFacturaOriginal() const { return idFacturaOriginal; }
std::string Devolucion::getFechaHora() const { return fechaHora; }
std::string Devolucion::getNombreCliente() const { return nombreCliente; }
std::string Devolucion::getRucCliente() const { return rucCliente; }
std::string Devolucion::getMotivo() const { return motivo; }
float Devolucion::getTotalDevolucion() const { return totalDevolucion; }
bool Devolucion::getActiva() const { return activa; }
const std::vector<ItemDevolucion>& Devolucion::getItemsDevueltos() const { return itemsDevueltos; }

// Setters
void Devolucion::setIdDevolucion(int id) { idDevolucion = id; }
void Devolucion::setFacturaOriginal(int idFactura, const std::string& cliente, const std::string& ruc) {
    idFacturaOriginal = idFactura;
    nombreCliente = cliente;
    rucCliente = ruc;
}
void Devolucion::setMotivo(const std::string& mot) { motivo = mot; }
void Devolucion::setActiva(bool a) { activa = a; }

void Devolucion::agregarItem(const ItemDevolucion& item) {
    itemsDevueltos.push_back(item);
    calcularTotal();
}

void Devolucion::calcularTotal() {
    totalDevolucion = 0;
    for (const auto& item : itemsDevueltos) {
        totalDevolucion += item.getSubtotal();
    }
}

void Devolucion::mostrarDevolucion() const {
    string estado = activa ? "ACTIVA" : "ANULADA";
    cout << "Devolucion[" << idDevolucion << "] | Factura: " << idFacturaOriginal
         << " | Cliente: " << nombreCliente
         << " | Total: $" << totalDevolucion
         << " | Estado: " << estado << "\n";
}

void Devolucion::mostrarDevolucionCompleta() const {
    cout << "\n========================================\n";
    cout << "      COMPROBANTE DE DEVOLUCIÓN\n";
    cout << "========================================\n";
    cout << "No. Devolución: " << idDevolucion << "\n";
    cout << "Factura Original: " << idFacturaOriginal << "\n";
    cout << "Fecha: " << fechaHora << "\n";
    cout << "Motivo: " << motivo << "\n";
    cout << "----------------------------------------\n";
    cout << "CLIENTE:\n";
    cout << "Nombre: " << nombreCliente << "\n";
    cout << "RUC/CI: " << rucCliente << "\n";
    cout << "----------------------------------------\n";
    cout << "PRODUCTOS DEVUELTOS:\n";
    for (const auto& item : itemsDevueltos) {
        item.mostrarInfo();
    }
    cout << "----------------------------------------\n";
    cout << "TOTAL DEVUELTO: $" << fixed << setprecision(2) << totalDevolucion << "\n";
    cout << "========================================\n";
    cout << "Estado: " << (activa ? "ACTIVA" : "ANULADA") << "\n";
    cout << "========================================\n";
}

std::string Devolucion::obtenerFechaHoraActual() {
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    stringstream ss;
    ss << (tiempoLocal->tm_mday) << "/"
       << (tiempoLocal->tm_mon + 1) << "/"
       << (tiempoLocal->tm_year + 1900) << " "
       << tiempoLocal->tm_hour << ":"
       << tiempoLocal->tm_min << ":"
       << tiempoLocal->tm_sec;

    return ss.str();
}
