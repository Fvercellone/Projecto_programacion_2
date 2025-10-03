#include "Inventario.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <direct.h>

// Función para crear carpeta si no existe
inline void crearCarpetaSiNoExiste(const std::string& carpeta) {
    _mkdir(carpeta.c_str());
}

Inventario::Inventario(const std::string& archivo) : archivoProductos(archivo) {
    // Crear carpeta DATA si no existe
//    size_t pos = archivo.find_last_of("/\\");
//    if (pos != std::string::npos) {
//        std::string carpeta = archivo.substr(0, pos);
//        crearCarpetaSiNoExiste(carpeta);
//        std::cout << "DEBUG: Carpeta creada/verificada: " << carpeta << std::endl;
//    }

// std::cout << "DEBUG Inventario: Ruta del archivo = " << archivoProductos << std::endl;


    cargarProductos();
}

void Inventario::agregarProducto(const Producto& p) {

    for (const auto& producto : productos) {
        if (producto.getIdProducto() == p.getIdProducto()) {
            std::cout << "Error: Ya existe un producto con ese ID.\n";
            return;
        }
    }

    productos.push_back(p);
    guardarProductos();
    std::cout << "Producto agregado exitosamente!\n";
}

void Inventario::eliminarProducto(int idProducto) {
    auto it = std::remove_if(productos.begin(), productos.end(),
        [idProducto](const Producto& p) {
            return p.getIdProducto() == idProducto;
        });

    if (it != productos.end()) {
        productos.erase(it, productos.end());
        guardarProductos();
        std::cout << "Producto eliminado.\n";
    } else {
        std::cout << "No se encontro producto con ese ID.\n";
    }
}

Producto* Inventario::buscarProducto(int idProducto) {
    for (auto& p : productos) {
        if (p.getIdProducto() == idProducto) {
            return &p;
        }
    }
    return nullptr;
}

void Inventario::mostrarInventario() const {
    std::cout << "=== INVENTARIO ===\n";
    for (const auto& p : productos) {
        p.mostrarInfo();
    }
    std::cout << "Total productos: " << productos.size() << "\n";
}

int Inventario::getCantidadTotal() const {
    return productos.size();
}

void Inventario::guardarProductos() const {

    std::ofstream archivo(archivoProductos);
    if (!archivo) {
        std::cout << "ERROR: No se pudo abrir el archivo para escritura: " << archivoProductos << std::endl;
        return;
    }

    for (const auto& producto : productos) {
        producto.guardarEnArchivo(archivo);

    }

}

void Inventario::cargarProductos() {
    productos.clear();

    std::ifstream archivo(archivoProductos);
    if (!archivo) {
        std::cout << "Archivo de productos no encontrado. Se creara uno nuevo.\n";
        return;
    }

//    std::cout << "DEBUG: Archivo de productos abierto exitosamente" << std::endl;

    Producto p;
    int contador = 0;
    while (p.cargarDesdeArchivo(archivo)) {
        productos.push_back(p);
        contador++;
//        std::cout << "DEBUG: Producto cargado - ID: " << p.getIdProducto()
//                  << ", Nombre: " << p.getNombre() << std::endl;
    }

    std::cout << "Cargados " << productos.size() << " productos.\n";
}


void Inventario::editarPrecioProducto(int idProducto, float nuevoPrecio) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        float precioViejo = producto->getPrecio();  // Guardar precio anterior
        producto->setPrecio(nuevoPrecio);
        guardarProductos();  // Guardar cambios en archivo

        std::cout << "Precio actualizado exitosamente!\n";
        std::cout << "Producto: " << producto->getNombre() << "\n";
        std::cout << "Precio anterior: $" << precioViejo << "\n";
        std::cout << "Precio nuevo: $" << nuevoPrecio << "\n";
    } else {
        std::cout << "Error: No se encontro producto con ID " << idProducto << ".\n";
    }
}


//CONTAMOS A LOS PRODUCTOS POR MARCA PARA EVITAR DAÑOS Y/O PERDIDA DE INFORMACION

int Inventario::contarProductosPorMarca(int idMarca) const {
    int contador = 0;
    for (const auto& producto : productos) {
        if (producto.getIdMarca() == idMarca) {
            contador++;
        }
    }
    return contador;
}

void Inventario::mostrarProductosPorMarca(int idMarca) const {
    for (const auto& producto : productos) {
        if (producto.getIdMarca() == idMarca) {
            std::cout << "  - ";
            producto.mostrarInfo();  // O puedes hacer un cout personalizado
        }
    }
}

void Inventario::reasignarProductosAMarca(int idMarcaVieja, int idMarcaNueva) {
    for (auto& producto : productos) {
        if (producto.getIdMarca() == idMarcaVieja) {
            producto.setIdMarca(idMarcaNueva);
        }
    }
    guardarProductos();  // Guardar los cambios
}
