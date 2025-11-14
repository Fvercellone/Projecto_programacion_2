#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Marca.h"
#include "MedioPago.h"
#include "Venta.h"
#include "Factura.h"

// Forward declarations
class Producto;
class Marca;
class MedioPago;
class Venta;
class Factura;
class Devolucion;

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

    // Facturas
    static void guardarFacturas(const std::vector<Factura>& facturas, const std::string& archivo = "DATA/facturas.txt");
    static std::vector<Factura> cargarFacturas(const std::string& archivo = "DATA/facturas.txt");

    // DEVOLUCIONES
    static void guardarDevoluciones(const std::vector<Devolucion>& devoluciones, const std::string& archivo = "DATA/devoluciones.txt");
    static std::vector<Devolucion> cargarDevoluciones(const std::string& archivo = "DATA/devoluciones.txt");




    // IDs SEPARADOS - CADA UNO CON SU ARCHIVO
    static void guardarUltimoIDProducto(int ultimoID, const std::string& archivo = "DATA/ultimo_id_producto.txt");
    static int cargarUltimoIDProducto(const std::string& archivo = "DATA/ultimo_id_producto.txt");

    static void guardarUltimoIDMarca(int ultimoID, const std::string& archivo = "DATA/ultimo_id_marca.txt");
    static int cargarUltimoIDMarca(const std::string& archivo = "DATA/ultimo_id_marca.txt");

    static void guardarUltimoIDMedioPago(int ultimoID, const std::string& archivo = "DATA/ultimo_id_medio_pago.txt");
    static int cargarUltimoIDMedioPago(const std::string& archivo = "DATA/ultimo_id_medio_pago.txt");

    static void guardarUltimoIDFactura(int ultimoID, const std::string& archivo = "DATA/ultimo_id_factura.txt");
    static int cargarUltimoIDFactura(const std::string& archivo = "DATA/ultimo_id_factura.txt");

    static void guardarUltimoIDDevolucion(int ultimoID, const std::string& archivo = "DATA/ultimo_id_devolucion.txt");
    static int cargarUltimoIDDevolucion(const std::string& archivo = "DATA/ultimo_id_devolucion.txt");






private:
    static void crearCarpetaSiNoExiste(const std::string& carpeta);
};

#endif
