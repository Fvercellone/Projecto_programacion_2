#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "Producto.h"

class ListaMarcas;

class Inventario {
private:
    std::string archivoProductos;
    std::vector<Producto> productos;
    int ultimoID;

public:
    Inventario(const std::string& archivo = "DATA/productos.txt");

    void agregarProducto(const Producto& p);
    void eliminarProducto(int idProducto);
    Producto* buscarProducto(int idProducto);
    void mostrarInventario() const;
    int getCantidadTotal() const;
    void editarPrecioProducto(int idProducto, float nuevoPrecio);
    void editarNombreProducto(int idProducto, const std::string& nuevoNombre);
    void editarDescripcionProducto(int idProducto, const std::string& nuevaDescripcion);

    //MARCA
    int contarProductosPorMarca(int idMarca) const;
    void mostrarProductosPorMarca(int idMarca) const;
    void reasignarProductosAMarca(int idMarcaVieja, int idMarcaNueva);
    void cambiarMarcaProducto(int idProducto, int nuevaIdMarca, ListaMarcas& listaMarcas);

    // Métodos para manejo de archivos
    void guardarProductos() const;
    void cargarProductos();


private:
    int generarNuevoID();
    void cargarUltimoID();
    void guardarUltimoID() const;
};

#endif
