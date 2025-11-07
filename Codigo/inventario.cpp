#include "Inventario.h"
#include <algorithm>
#include "Manejo_Archivos.h"
#include "ListaMarcas.h"

Inventario::Inventario() {
    productos = ManejadorArchivos::cargarProductos();
    ultimoID = ManejadorArchivos::cargarUltimoIDProducto();}

void Inventario::agregarProducto(const Producto& p) {
    for (const auto& producto : productos) {
        if (producto.getIdProducto() == p.getIdProducto()) {
            std::cout << "Error: Ya existe un producto con ese ID.\n";
            return;
        }
    }

    // Generar nuevo ID automáticamente
    int nuevoID = generarNuevoID();
    Producto productoCopia = p;
    productoCopia.setIdProducto(nuevoID);

    productos.push_back(productoCopia);
    ManejadorArchivos::guardarProductos(productos);
    std::cout << "Producto agregado exitosamente! ID asignado: " << nuevoID << "\n";
}

void Inventario::eliminarProducto(int idProducto) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        if (!producto->getActivo()) {
            std::cout << "El producto ya esta inactivo.\n";
            return;
        }

        producto->setActivo(false);  // ← BORRADO LÓGICO
        ManejadorArchivos::guardarProductos(productos);
        std::cout << "Producto marcado como INACTIVO.\n";
    } else {
        std::cout << "No se encontro producto con ese ID.\n";
    }
}

void Inventario::editarPrecioProducto(int idProducto, float nuevoPrecio) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        producto->setPrecio(nuevoPrecio);
        ManejadorArchivos::guardarProductos(productos);
        std::cout << "Precio actualizado exitosamente!\n";
    } else {
        std::cout << "Error: Producto no encontrado.\n";
    }
}

void Inventario::cambiarMarcaProducto(int idProducto, int nuevaIdMarca, ListaMarcas& listaMarcas) {
    Producto* producto = buscarProducto(idProducto);
    if (!producto) {
        std::cout << "Error: Producto no encontrado.\n";
        return;
    }

    if (!listaMarcas.buscarMarca(nuevaIdMarca)) {
        std::cout << "Error: La marca ID " << nuevaIdMarca << " no existe.\n";
        return;
    }

    producto->setIdMarca(nuevaIdMarca);
    ManejadorArchivos::guardarProductos(productos);
    std::cout << "Marca cambiada exitosamente!\n";
}

void Inventario::editarNombreProducto(int idProducto, const std::string& nuevoNombre) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        producto->setNombre(nuevoNombre);
        ManejadorArchivos::guardarProductos(productos);
        std::cout << "Nombre actualizado exitosamente!\n";
    } else {
        std::cout << "Error: Producto no encontrado.\n";
    }
}

void Inventario::editarDescripcionProducto(int idProducto, const std::string& nuevaDescripcion) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        producto->setDescripcion(nuevaDescripcion);
        ManejadorArchivos::guardarProductos(productos);
        std::cout << "Descripción actualizada exitosamente!\n";
    } else {
        std::cout << "Error: Producto no encontrado.\n";
    }
}

int Inventario::generarNuevoID() {
    ultimoID++;
    ManejadorArchivos::guardarUltimoIDProducto(ultimoID);
    return ultimoID;
}




void Inventario::activarProducto(int idProducto) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        if (producto->getActivo()) {
            std::cout << "El producto ya está ACTIVO.\n";
        } else {
            producto->setActivo(true);
            ManejadorArchivos::guardarProductos(productos);
            std::cout << "Producto ACTIVADO exitosamente!\n";
        }
    } else {
        std::cout << "Error: Producto no encontrado.\n";
    }
}

void Inventario::desactivarProducto(int idProducto) {
    Producto* producto = buscarProducto(idProducto);
    if (producto) {
        if (!producto->getActivo()) {
            std::cout << "El producto ya está INACTIVO.\n";
        } else {
            producto->setActivo(false);
            ManejadorArchivos::guardarProductos(productos);
            std::cout << "Producto DESACTIVADO exitosamente!\n";
        }
    } else {
        std::cout << "Error: Producto no encontrado.\n";
    }
}

void Inventario::mostrarProductosInactivos() const {
    std::cout << "=== PRODUCTOS INACTIVOS ===\n";
    int contador = 0;
    for (const auto& p : productos) {
        if (!p.getActivo()) {
            p.mostrarInfo();
            contador++;
        }
    }
    std::cout << "Total productos inactivos: " << contador << "\n";
}

int Inventario::contarProductosPorMarca(int idMarca) const {
    int contador = 0;
    for (const auto& producto : productos) {
        if (producto.getIdMarca() == idMarca) {
            contador++;
        }
    }
    return contador;
}

void Inventario::reasignarProductosAMarca(int idMarcaVieja, int idMarcaNueva) {
    for (auto& producto : productos) {
        if (producto.getIdMarca() == idMarcaVieja) {
            producto.setIdMarca(idMarcaNueva);
        }
    }
    ManejadorArchivos::guardarProductos(productos);
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
    std::cout << "=== INVENTARIO COMPLETO ===\n";
    for (const auto& p : productos) {
        p.mostrarInfo();
    }
    std::cout << "Total productos: " << productos.size() << "\n";
}

int Inventario::getCantidadTotal() const {
    return productos.size();
}
