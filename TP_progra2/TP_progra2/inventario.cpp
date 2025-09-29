#include "Inventario.h"
#include <iostream>

Inventario::Inventario() : cantidadTotal(0) {}

void Inventario::agregarProducto(Producto* p) {
    listaProductos.push_back(p);
    cantidadTotal++;
}

void Inventario::eliminarProducto(int idProducto) {
    for (auto it = listaProductos.begin(); it != listaProductos.end(); ++it) {
        if ((*it)->getIdProducto() == idProducto) {
            delete *it; // liberar memoria
            listaProductos.erase(it);
            cantidadTotal--;
            std::cout << "Producto eliminado.\n";
            return;
        }
    }
    std::cout << "No se encontro producto con ese ID.\n";
}

Producto* Inventario::buscarProducto(int idProducto) {
    for (auto* p : listaProductos) {
        if (p->getIdProducto() == idProducto) return p;
    }
    return nullptr;
}

void Inventario::mostrarInventario() const {
    std::cout << "=== INVENTARIO ===\n";
    for (auto* p : listaProductos) {
        if (p) p->mostrarInfo();
    }
    std::cout << "Total productos: " << cantidadTotal << "\n";
}

int Inventario::getCantidadTotal() const {
    return cantidadTotal;
}
