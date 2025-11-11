#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "Producto.h"

class ListaMarcas;

class Inventario {
private:
    std::vector<Producto> productos;
    int ultimoID;  // ← NUEVO

public:
    Inventario();  // ← SIN parámetro

    void agregarProducto(const Producto& p);
    void eliminarProducto(int idProducto);
    void editarPrecioProducto(int idProducto, float nuevoPrecio);
    void cambiarMarcaProducto(int idProducto, int nuevaIdMarca, ListaMarcas& listaMarcas);
    void editarNombreProducto(int idProducto, const std::string& nuevoNombre);
    void editarDescripcionProducto(int idProducto, const std::string& nuevaDescripcion);

    void activarProducto(int idProducto);
    void desactivarProducto(int idProducto);

    void mostrarProductosInactivos() const;
    void mostrarProductosActivos() const;


    Producto* buscarProducto(int idProducto);
    void mostrarInventario() const;
    int getCantidadTotal() const;
    const std::vector<Producto>& getProductos() const { return productos; }
    int contarProductosPorMarca(int idMarca) const;
    void reasignarProductosAMarca(int idMarcaVieja, int idMarcaNueva);

private:
    int generarNuevoID();
};

#endif
