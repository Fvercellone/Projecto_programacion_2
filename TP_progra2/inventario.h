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
    void eliminarProducto(int idProducto);
    Producto* buscarProducto(int idProducto);
    void mostrarInventario() const;
    int getCantidadTotal() const;
    void editarPrecioProducto(int idProducto, float nuevoPrecio);

    //MARCA
    int contarProductosPorMarca(int idMarca) const;
    void mostrarProductosPorMarca(int idMarca) const;
    void reasignarProductosAMarca(int idMarcaVieja, int idMarcaNueva);

    // Métodos para manejo de archivos
    void guardarProductos() const;
    void cargarProductos();
};

#endif
