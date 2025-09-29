#include "Producto.h"

Producto::Producto(int idP, const std::string& n, const std::string& d, float p, int s, int idM)
    : idProducto(idP), nombre(n), descripcion(d), precio(p), stock(s), idMarca(idM) {}

// Getters
int Producto::getIdProducto() const { return idProducto; }
std::string Producto::getNombre() const { return nombre; }
std::string Producto::getDescripcion() const { return descripcion; }
float Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
int Producto::getIdMarca() const { return idMarca; }

// Setters
void Producto::setNombre(const std::string& n) { nombre = n; }
void Producto::setDescripcion(const std::string& d) { descripcion = d; }
void Producto::setPrecio(float p) { precio = p; }
void Producto::setStock(int s) { stock = s; }
void Producto::setIdMarca(int idM) { idMarca = idM; }

// Métodos
void Producto::mostrarInfo() const {
    std::cout << "Producto[" << idProducto << "] " << nombre
              << " | $" << precio
              << " | Stock: " << stock
              << " | Marca ID: " << idMarca
              << " | Desc: " << descripcion << "\n";
}

void Producto::agregarStock(int cantidad) { stock += cantidad;}
void Producto::DescontarStock(int cantidad) { stock -= cantidad; }

void Producto::quitarStock(int cantidad) {
    if (cantidad <= stock) stock -= cantidad;
    else std::cout << "No hay suficiente stock para quitar.\n";
}
