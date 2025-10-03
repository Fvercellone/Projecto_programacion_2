#include "Producto.h"
#include <limits>

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
    std::cout << "Producto[" << idProducto << "] "
              << " | Nombre: " << nombre
              << " | Desc: " << descripcion
              << " | $" << precio
              << " | Stock: " << stock
              << " | Marca ID: " << idMarca << "\n";
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

// Guardar producto en archivo
void Producto::guardarEnArchivo(std::ofstream& archivo) const {
    archivo << idProducto << " "
            << nombre << "|"
            << descripcion << "|"
            << precio << " "
            << stock << " "
            << idMarca << "\n";
}

// Cargar producto desde archivo - VERSIÓN CORREGIDA
bool Producto::cargarDesdeArchivo(std::ifstream& archivo) {
    if (!(archivo >> idProducto)) {
        return false;
    }

    // Ignorar espacio después del ID
    archivo.ignore(1, ' ');

    // Leer nombre (hasta el |)
    std::getline(archivo, nombre, '|');

    // Leer descripción (hasta el |)
    std::getline(archivo, descripcion, '|');

    // Leer precio, stock e idMarca (separados por espacios)
    if (!(archivo >> precio >> stock >> idMarca)) {
        return false;
    }

    // Ignorar el salto de línea
    archivo.ignore(1000, '\n');

    return true;
}
