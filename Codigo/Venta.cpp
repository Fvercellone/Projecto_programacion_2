#include "Venta.h"
#include <iostream>

using namespace std;

// Implementación de ItemVenta
ItemVenta::ItemVenta(int idProd, const std::string& nombre, int cant, float precio)
    : idProducto(idProd), nombreProducto(nombre), cantidad(cant), precioUnitario(precio) {}

int ItemVenta::getIdProducto() const { return idProducto; }
std::string ItemVenta::getNombreProducto() const { return nombreProducto; }
int ItemVenta::getCantidad() const { return cantidad; }
float ItemVenta::getPrecioUnitario() const { return precioUnitario; }
float ItemVenta::getSubtotal() const { return cantidad * precioUnitario; }

void ItemVenta::setCantidad(int cant) { cantidad = cant; }
void ItemVenta::setPrecioUnitario(float precio) { precioUnitario = precio; }

void ItemVenta::mostrarInfo() const {
    cout << "  Producto[" << idProducto << "] " << nombreProducto
         << " | Cant: " << cantidad
         << " | $" << precioUnitario
         << " | Subtotal: $" << getSubtotal() << "\n";
}

// Implementación de Venta
Venta::Venta(int idV, int idMedioP, const std::string& nomMedioP, double ajuste)
    : idVenta(idV), idMedioPago(idMedioP), nombreMedioPago(nomMedioP),
      ajusteMedioPago(ajuste), subtotal(0), total(0), activo(true) {}

int Venta::getIdVenta() const { return idVenta; }
int Venta::getIdMedioPago() const { return idMedioPago; }
std::string Venta::getNombreMedioPago() const { return nombreMedioPago; }
double Venta::getAjusteMedioPago() const { return ajusteMedioPago; }
float Venta::getSubtotal() const { return subtotal; }
float Venta::getTotal() const { return total; }
bool Venta::getActivo() const { return activo; }
const std::vector<ItemVenta>& Venta::getItems() const { return items; }

void Venta::setIdVenta(int id) { idVenta = id; }
void Venta::setMedioPago(int id, const std::string& nombre, double ajuste) {
    idMedioPago = id;
    nombreMedioPago = nombre;
    ajusteMedioPago = ajuste;
    calcularTotales();
}
void Venta::setActivo(bool a) { activo = a; }

void Venta::agregarItem(const ItemVenta& item) {
    items.push_back(item);
    calcularTotales();
}

void Venta::calcularTotales() {
    subtotal = 0;
    for (const auto& item : items) {
        subtotal += item.getSubtotal();
    }
    total = subtotal * ajusteMedioPago;
}

void Venta::mostrarVenta() const {
    string estado = activo ? "ACTIVA" : "ANULADA";
    cout << "Venta[" << idVenta << "] | Medio: " << nombreMedioPago
         << " | Subtotal: $" << subtotal
         << " | Total: $" << total
         << " | Estado: " << estado << "\n";

    cout << "  Items:\n";
    for (const auto& item : items) {
        item.mostrarInfo();
    }
}
