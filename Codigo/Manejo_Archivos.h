#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Marca.h"
#include "MedioPago.h"
#include "Venta.h"
#include "Factura.h"


class ManejadorArchivos {
public:
    // Productos
    static void guardarProductos(const std::vector<Producto>& productos, const std::string& archivo = "DATA/productos.txt");
    static std::vector<Producto> cargarProductos(const std::string& archivo = "DATA/productos.txt");

    // Marcas
    static void guardarMarcas(const std::vector<Marca>& marcas, const std::string& archivo = "DATA/marcas.txt");
    static std::vector<Marca> cargarMarcas(const std::string& archivo = "DATA/marcas.txt");

    // Medios de Pago
    static void guardarMediosPago(const std::vector<MedioPago>& mediosPago, const std::string& archivo = "DATA/medios_pago.txt");
    static std::vector<MedioPago> cargarMediosPago(const std::string& archivo = "DATA/medios_pago.txt");

    // Ventas
    static void guardarVentas(const std::vector<Venta>& ventas, const std::string& archivo = "DATA/ventas.txt");
    static std::vector<Venta> cargarVentas(const std::string& archivo = "DATA/ventas.txt");

    // Facturas
    static void guardarFacturas(const std::vector<Factura>& facturas, const std::string& archivo = "DATA/facturas.txt");
    static std::vector<Factura> cargarFacturas(const std::string& archivo = "DATA/facturas.txt");


    // IDs SEPARADOS - CADA UNO CON SU ARCHIVO
    static void guardarUltimoIDProducto(int ultimoID, const std::string& archivo = "DATA/ultimo_id_producto.txt");
    static int cargarUltimoIDProducto(const std::string& archivo = "DATA/ultimo_id_producto.txt");

    static void guardarUltimoIDMarca(int ultimoID, const std::string& archivo = "DATA/ultimo_id_marca.txt");
    static int cargarUltimoIDMarca(const std::string& archivo = "DATA/ultimo_id_marca.txt");

    static void guardarUltimoIDMedioPago(int ultimoID, const std::string& archivo = "DATA/ultimo_id_medio_pago.txt");
    static int cargarUltimoIDMedioPago(const std::string& archivo = "DATA/ultimo_id_medio_pago.txt");

    static void guardarUltimoIDVenta(int ultimoID, const std::string& archivo = "DATA/ultimo_id_venta.txt");
    static int cargarUltimoIDVenta(const std::string& archivo = "DATA/ultimo_id_venta.txt");

    static void guardarUltimoIDFactura(int ultimoID, const std::string& archivo = "DATA/ultimo_id_factura.txt");
    static int cargarUltimoIDFactura(const std::string& archivo = "DATA/ultimo_id_factura.txt");

private:
    static void crearCarpetaSiNoExiste(const std::string& carpeta);
};

#endif
