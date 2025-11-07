#include "Producto.h"
#include <limits>

// Constructor actualizado
Producto::Producto(int idP, const std::string& n, const std::string& d, float p, int s, int idM, bool a)
    : idProducto(idP), nombre(n), descripcion(d), precio(p), stock(s), idMarca(idM), activo(a) {}

// Getters
int Producto::getIdProducto() const { return idProducto; }
std::string Producto::getNombre() const { return nombre; }
std::string Producto::getDescripcion() const { return descripcion; }
float Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
int Producto::getIdMarca() const { return idMarca; }
bool Producto::getActivo() const { return activo; }

// Setters
void Producto::setNombre(const std::string& n) { nombre = n; }
void Producto::setDescripcion(const std::string& d) { descripcion = d; }
void Producto::setPrecio(float p) { precio = p; }
void Producto::setStock(int s) { stock = s; }
void Producto::setIdMarca(int idM) { idMarca = idM; }
void Producto::setActivo(bool a) { activo = a; }

// Métodos
void Producto::mostrarInfo() const {
    std::string estado = activo ? "ACTIVO" : "INACTIVO";
    std::cout << "Producto[" << idProducto << "] " << nombre
              << " | $" << precio
              << " | Stock: " << stock
              << " | Marca ID: " << idMarca
              << " | Desc: " << descripcion
              << " | Estado: " << estado << "\n";  // ← NUEVO
}


void Producto::agregarStock(int cantidad) { stock += cantidad;}

void Producto::quitarStock(int cantidad) {
    if (cantidad <= stock) {
        stock -= cantidad;
        std::cout << "Stock actualizado.\n";
    } else {
        std::cout << "No hay suficiente stock para quitar.\n";
    }
}


// Setteamos id
void Producto::setIdProducto(int id) {
    idProducto = id;
}
