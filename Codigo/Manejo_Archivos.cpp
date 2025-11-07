#include <iostream>
#include <fstream>
#include <direct.h>
#include "Manejo_Archivos.h"

void ManejadorArchivos::crearCarpetaSiNoExiste(const std::string& carpeta) {
    _mkdir(carpeta.c_str());
}

// PRODUCTOS
void ManejadorArchivos::guardarProductos(const std::vector<Producto>& productos, const std::string& archivo) {
    // Crear carpeta si no existe
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar productos en " << archivo << std::endl;
        return;
    }

    for (const auto& producto : productos) {
        file << producto.getIdProducto() << " "
             << producto.getNombre() << "|"
             << producto.getDescripcion() << "|"
             << producto.getPrecio() << " "
             << producto.getStock() << " "
             << producto.getIdMarca() << "\n"
             << producto.getActivo() << "\n";
    }
}

std::vector<Producto> ManejadorArchivos::cargarProductos(const std::string& archivo) {
    std::vector<Producto> productos;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de productos no encontrado: " << archivo << std::endl;
        return productos;
    }

    int id, stock, idMarca;
    std::string nombre, descripcion;
    float precio;
    bool activo;

    while (file >> id) {
        file.ignore(1, ' ');
        std::getline(file, nombre, '|');
        std::getline(file, descripcion, '|');
        file >> precio >> stock >> idMarca >> activo;
        file.ignore(1000, '\n');

        productos.push_back(Producto(id, nombre, descripcion, precio, stock, idMarca, activo));
    }

    return productos;
}

void ManejadorArchivos::guardarMarcas(const std::vector<Marca>& marcas, const std::string& archivo) {
    // Crear carpeta si no existe
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar marcas en " << archivo << std::endl;
        return;
    }

    for (const auto& marca : marcas) {
        file << marca.getIdMarca() << " "
             << marca.getNombre() << " "
             << marca.getActivo() << "\n";
    }
}

std::vector<Marca> ManejadorArchivos::cargarMarcas(const std::string& archivo) {
    std::vector<Marca> marcas;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de marcas no encontrado: " << archivo << std::endl;
        return marcas;
    }

    int id;
    std::string nombre;
    bool activo;

    while (file >> id) {
        file.ignore(1, ' ');  // Ignorar espacio después del ID

        // Leer nombre (hasta el último espacio antes del booleano)
        std::getline(file, nombre, ' ');  // ← CAMBIAR: leer hasta espacio, no hasta salto de línea

        file >> activo;
        file.ignore(1000, '\n');

        marcas.push_back(Marca(id, nombre, activo));
    }

    return marcas;
}

// IDs de PRODUCTOS
void ManejadorArchivos::guardarUltimoIDProducto(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDProducto(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // ← Empieza desde 10000 (9999 + 1)

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {
            ultimoID = 9999;
        }
    }
    return ultimoID;
}

// IDs de MARCAS
void ManejadorArchivos::guardarUltimoIDMarca(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDMarca(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // ← Empieza desde 10000 (9999 + 1)

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {
            ultimoID = 9999;
        }
    }
    return ultimoID;
}
