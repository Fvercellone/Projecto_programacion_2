#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Marca.h"

class ManejadorArchivos {
public:
    // Productos
    static void guardarProductos(const std::vector<Producto>& productos, const std::string& archivo = "DATA/productos.txt");
    static std::vector<Producto> cargarProductos(const std::string& archivo = "DATA/productos.txt");

    // Marcas
    static void guardarMarcas(const std::vector<Marca>& marcas, const std::string& archivo = "DATA/marcas.txt");
    static std::vector<Marca> cargarMarcas(const std::string& archivo = "DATA/marcas.txt");

   // IDs SEPARADOS - CADA UNO CON SU ARCHIVO
    static void guardarUltimoIDProducto(int ultimoID, const std::string& archivo = "DATA/ultimo_id_producto.txt");
    static int cargarUltimoIDProducto(const std::string& archivo = "DATA/ultimo_id_producto.txt");

    static void guardarUltimoIDMarca(int ultimoID, const std::string& archivo = "DATA/ultimo_id_marca.txt");
    static int cargarUltimoIDMarca(const std::string& archivo = "DATA/ultimo_id_marca.txt");

private:
    static void crearCarpetaSiNoExiste(const std::string& carpeta);
};

#endif
