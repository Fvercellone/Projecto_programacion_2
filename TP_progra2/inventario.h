#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "Producto.h"

class Inventario {
private:
    std::string archivoProductos;
    std::vector<Producto> productos;

public:
    Inventario(const std::string& archivo = "DATA/productos.txt");

    void agregarProducto(const Producto& p);
    void eliminarProducto(int idProducto);  // ← Asegúrate de que esté declarada
    Producto* buscarProducto(int idProducto);
    void mostrarInventario() const;
    int getCantidadTotal() const;

    // Métodos para manejo de archivos
    void guardarProductos() const;
    void cargarProductos();
};

#endif
