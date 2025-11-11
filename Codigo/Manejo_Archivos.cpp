#include <iostream>
#include <fstream>
#include <direct.h>
#include "Manejo_Archivos.h"

void ManejadorArchivos::crearCarpetaSiNoExiste(const std::string& carpeta) {
    _mkdir(carpeta.c_str());
}

/// PRODUCTOS
void ManejadorArchivos::guardarProductos(const std::vector<Producto>& productos, const std::string& archivo) {
    // Crear carpeta si no existe
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar productos en " << archivo << std::endl;
        return;
    }

    for (const auto& producto : productos) {
        file << producto.getIdProducto() << " "
             << producto.getNombre() << "|"
             << producto.getDescripcion() << "|"
             << producto.getPrecio() << " "
             << producto.getStock() << " "
             << producto.getIdMarca() << "\n"
             << producto.getActivo() << "\n";
    }
}

std::vector<Producto> ManejadorArchivos::cargarProductos(const std::string& archivo) {
    std::vector<Producto> productos;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de productos no encontrado: " << archivo << std::endl;
        return productos;
    }

    int id, stock, idMarca;
    std::string nombre, descripcion;
    float precio;
    bool activo;

    while (file >> id) {
        file.ignore(1, ' ');
        std::getline(file, nombre, '|');
        std::getline(file, descripcion, '|');
        file >> precio >> stock >> idMarca >> activo;
        file.ignore(1000, '\n');

        productos.push_back(Producto(id, nombre, descripcion, precio, stock, idMarca, activo));
    }

    return productos;
}


///MARCAS
void ManejadorArchivos::guardarMarcas(const std::vector<Marca>& marcas, const std::string& archivo) {
    // Crear carpeta si no existe
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar marcas en " << archivo << std::endl;
        return;
    }

    for (const auto& marca : marcas) {
        file << marca.getIdMarca() << " "
             << marca.getNombre() << " "
             << marca.getActivo() << "\n";
    }
}

std::vector<Marca> ManejadorArchivos::cargarMarcas(const std::string& archivo) {
    std::vector<Marca> marcas;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de marcas no encontrado: " << archivo << std::endl;
        return marcas;
    }

    int id;
    std::string nombre;
    bool activo;

    while (file >> id) {
        file.ignore(1, ' ');  // Ignorar espacio después del ID

        // Leer nombre (hasta el último espacio antes del booleano)
        std::getline(file, nombre, ' ');  // ← CAMBIAR: leer hasta espacio, no hasta salto de línea

        file >> activo;
        file.ignore(1000, '\n');

        marcas.push_back(Marca(id, nombre, activo));
    }

    return marcas;
}


// Medios de Pago
void ManejadorArchivos::guardarMediosPago(const std::vector<MedioPago>& mediosPago, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar medios de pago en " << archivo << std::endl;
        return;
    }

    for (const auto& medio : mediosPago) {
        file << medio.getIdMedioPago() << " "
             << medio.getNombre() << " "
             << medio.getAjuste() << " "
             << medio.getActivo() << "\n";
    }
}

std::vector<MedioPago> ManejadorArchivos::cargarMediosPago(const std::string& archivo) {
    std::vector<MedioPago> mediosPago;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de medios de pago no encontrado: " << archivo << std::endl;
        return mediosPago;
    }

    int id;
    std::string nombre;
    double ajuste;
    bool activo;

    while (file >> id) {
        file.ignore(1, ' ');
        std::getline(file, nombre, ' ');
        file >> ajuste >> activo;
        file.ignore(1000, '\n');

        mediosPago.push_back(MedioPago(id, nombre, ajuste, activo));
    }

    return mediosPago;
}


/// VENTAS
void ManejadorArchivos::guardarVentas(const std::vector<Venta>& ventas, const std::string& archivo) {
    // Crear carpeta si no existe
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar ventas en " << archivo << std::endl;
        return;
    }

    for (const auto& venta : ventas) {
        // Guardar encabezado de venta
        file << venta.getIdVenta() << " "
             << venta.getIdMedioPago() << " "
             << venta.getNombreMedioPago() << "|"
             << venta.getAjusteMedioPago() << " "
             << venta.getSubtotal() << " "
             << venta.getTotal() << " "
             << venta.getActivo() << " "
             << venta.getItems().size() << "\n";

        // Guardar items de la venta
        for (const auto& item : venta.getItems()) {
            file << "  " << item.getIdProducto() << " "
                 << item.getNombreProducto() << "|"
                 << item.getCantidad() << " "
                 << item.getPrecioUnitario() << "\n";
        }
    }
}

std::vector<Venta> ManejadorArchivos::cargarVentas(const std::string& archivo) {
    std::vector<Venta> ventas;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de ventas no encontrado: " << archivo << std::endl;
        return ventas;
    }

    int idVenta, idMedioPago, numItems;
    std::string nombreMedioPago;
    double ajusteMedioPago;
    float subtotal, total;
    bool activo;

    while (file >> idVenta >> idMedioPago) {
        file.ignore(1, ' ');
        std::getline(file, nombreMedioPago, '|');
        file >> ajusteMedioPago >> subtotal >> total >> activo >> numItems;
        file.ignore(1000, '\n');

        // Crear venta
        Venta venta(idVenta, idMedioPago, nombreMedioPago, ajusteMedioPago);
        venta.setActivo(activo);

        // Cargar items
        for (int i = 0; i < numItems; i++) {
            int idProducto, cantidad;
            std::string nombreProducto;
            float precioUnitario;

            file.ignore(2, ' '); // Ignorar "  " al inicio de la línea
            file >> idProducto;
            file.ignore(1, ' ');
            std::getline(file, nombreProducto, '|');
            file >> cantidad >> precioUnitario;
            file.ignore(1000, '\n');

            ItemVenta item(idProducto, nombreProducto, cantidad, precioUnitario);
            venta.agregarItem(item);
        }

        ventas.push_back(venta);
    }

    return ventas;
}


/// FACTURAS
void ManejadorArchivos::guardarFacturas(const std::vector<Factura>& facturas, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar facturas en " << archivo << std::endl;
        return;
    }

    for (const auto& factura : facturas) {
        file << factura.getIdFactura() << " "
             << factura.getIdVenta() << " "
             << factura.getFechaHora() << "|"
             << factura.getNombreCliente() << "|"
             << factura.getRucCliente() << "|"
             << factura.getDireccionCliente() << "|"
             << factura.getSubtotal() << " "
             << factura.getTotal() << " "
             << factura.getActivo() << "\n";
    }
}

std::vector<Factura> ManejadorArchivos::cargarFacturas(const std::string& archivo) {
    std::vector<Factura> facturas;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de facturas no encontrado: " << archivo << std::endl;
        return facturas;
    }

    int idFactura, idVenta;
    std::string fechaHora, nombreCliente, rucCliente, direccionCliente;
    float subtotal, total;
    bool activo;

    while (file >> idFactura >> idVenta) {
        file.ignore(1, ' ');
        std::getline(file, fechaHora, '|');
        std::getline(file, nombreCliente, '|');
        std::getline(file, rucCliente, '|');
        std::getline(file, direccionCliente, '|');
        file >> subtotal >> total >> activo;
        file.ignore(1000, '\n');

        Factura factura(idFactura, idVenta, fechaHora, nombreCliente, rucCliente, direccionCliente);
        factura.setTotales(subtotal, total);
        factura.setActivo(activo);

        facturas.push_back(factura);
    }

    return facturas;
}








/// IDs de PRODUCTOS
void ManejadorArchivos::guardarUltimoIDProducto(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDProducto(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // ← Empieza desde 10000 (9999 + 1)

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {
            ultimoID = 9999;
        }
    }
    return ultimoID;
}

/// IDs de MARCAS
void ManejadorArchivos::guardarUltimoIDMarca(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDMarca(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // ← Empieza desde 10000 (9999 + 1)

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {
            ultimoID = 9999;
        }
    }
    return ultimoID;
}


/// IDs para Medios de Pago
void ManejadorArchivos::guardarUltimoIDMedioPago(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDMedioPago(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 29999;  // Empieza desde 30000

    if (file) {
        file >> ultimoID;
        if (ultimoID < 30000) {
            ultimoID = 29999;
        }
    }
    return ultimoID;
}

/// IDs para VENTAS
void ManejadorArchivos::guardarUltimoIDVenta(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDVenta(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // ← CAMBIAR: Empieza desde 10000 (9999 + 1)

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {  // ← CAMBIAR: Validar desde 10000
            ultimoID = 9999;
        }
    }
    return ultimoID;
}


// IDs para FACTURAS
void ManejadorArchivos::guardarUltimoIDFactura(int ultimoID, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (file) {
        file << ultimoID;
    }
}

int ManejadorArchivos::cargarUltimoIDFactura(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 9999;  // Empieza desde 10000

    if (file) {
        file >> ultimoID;
        if (ultimoID < 10000) {
            ultimoID = 9999;
        }
    }
    return ultimoID;
}
