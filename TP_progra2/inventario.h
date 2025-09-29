#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Producto.h"

class Inventario {
private:
    std::vector<Producto*> listaProductos;
    int cantidadTotal;

public:
    Inventario();

    void agregarProducto(Producto* p);
    void DescontarProducto(Producto* p);
    void eliminarProducto(int idProducto);
    Producto* buscarProducto(int idProducto);
    void mostrarInventario() const;

    int getCantidadTotal() const;
};

#endif
