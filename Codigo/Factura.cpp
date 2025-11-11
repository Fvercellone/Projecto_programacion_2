#include "Factura.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Factura::Factura(int idFact, int idVent, const std::string& fecha,
                 const std::string& cliente, const std::string& ruc,
                 const std::string& direccion)
    : idFactura(idFact), idVenta(idVent), fechaHora(fecha),
      nombreCliente(cliente), rucCliente(ruc), direccionCliente(direccion),
      subtotal(0), total(0), activo(true) {

    if (fecha.empty()) {
        fechaHora = obtenerFechaHoraActual();
    }
}

// Getters
int Factura::getIdFactura() const { return idFactura; }
int Factura::getIdVenta() const { return idVenta; }
std::string Factura::getFechaHora() const { return fechaHora; }
std::string Factura::getNombreCliente() const { return nombreCliente; }
std::string Factura::getRucCliente() const { return rucCliente; }
std::string Factura::getDireccionCliente() const { return direccionCliente; }
float Factura::getSubtotal() const { return subtotal; }
float Factura::getTotal() const { return total; }
bool Factura::getActivo() const { return activo; }

// Setters
void Factura::setIdFactura(int id) { idFactura = id; }
void Factura::setIdVenta(int id) { idVenta = id; }
void Factura::setFechaHora(const std::string& fecha) { fechaHora = fecha; }
void Factura::setCliente(const std::string& nombre, const std::string& ruc, const std::string& direccion) {
    nombreCliente = nombre;
    rucCliente = ruc;
    direccionCliente = direccion;
}
void Factura::setTotales(float sub, float tot) {
    subtotal = sub;
    total = tot;
}
void Factura::setActivo(bool a) { activo = a; }

void Factura::generarDesdeVenta(const Venta& venta) {
    idVenta = venta.getIdVenta();
    subtotal = venta.getSubtotal();
    total = venta.getTotal();
    fechaHora = obtenerFechaHoraActual();
}

void Factura::mostrarFactura() const {
    string estado = activo ? "ACTIVA" : "ANULADA";
    cout << "Factura[" << idFactura << "] | Venta: " << idVenta
         << " | Cliente: " << nombreCliente
         << " | Total: $" << total
         << " | Fecha: " << fechaHora
         << " | Estado: " << estado << "\n";
}

void Factura::mostrarFacturaCompleta() const {
    cout << "\n========================================\n";
    cout << "           FACTURA ELECTRONICA\n";
    cout << "========================================\n";
    cout << "No. Factura: " << idFactura << "\n";
    cout << "No. Venta: " << idVenta << "\n";
    cout << "Fecha: " << fechaHora << "\n";
    cout << "----------------------------------------\n";
    cout << "CLIENTE:\n";
    cout << "Nombre: " << nombreCliente << "\n";
    cout << "RUC/CI: " << rucCliente << "\n";
    cout << "Direccion: " << direccionCliente << "\n";
    cout << "----------------------------------------\n";
    cout << "SUBTOTAL: $" << fixed << setprecision(2) << subtotal << "\n";
    cout << "TOTAL: $" << fixed << setprecision(2) << total << "\n";
    cout << "========================================\n";
    cout << "Estado: " << (activo ? "ACTIVA" : "ANULADA") << "\n";
    cout << "========================================\n";
}

std::string Factura::obtenerFechaHoraActual() {
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
