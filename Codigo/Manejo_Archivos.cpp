#include <iostream>
#include <fstream>
#include <direct.h>
#include "Manejo_Archivos.h"
#include "Devolucion.h"

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
             << medio.getNombre() << "|"  // ← Usar pipe como separador
             << medio.getAjuste() << " "
             << medio.getActivo() << "\n";

        std::cout << "DEBUG: Guardado - ID: " << medio.getIdMedioPago()
                  << " Nombre: " << medio.getNombre()
                  << " Ajuste: " << medio.getAjuste()
                  << " Activo: " << medio.getActivo() << std::endl;
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
    char separador;

    while (file >> id) {
        file.ignore(1, ' ');  // Ignorar espacio después del ID

        // Leer nombre hasta el pipe
        std::getline(file, nombre, '|');

        file >> ajuste >> activo;
        file.ignore(1000, '\n');

        mediosPago.push_back(MedioPago(id, nombre, ajuste, activo));
    }

    return mediosPago;
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


/// DEVOLUCIONES
void ManejadorArchivos::guardarDevoluciones(const std::vector<Devolucion>& devoluciones, const std::string& archivo) {
    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    std::ofstream file(archivo);
    if (!file) {
        std::cout << "Error al guardar devoluciones en " << archivo << std::endl;
        return;
    }

    for (const auto& devolucion : devoluciones) {
        // Guardar encabezado de devolución
        file << devolucion.getIdDevolucion() << " "
             << devolucion.getIdFacturaOriginal() << " "
             << devolucion.getFechaHora() << "|"
             << devolucion.getNombreCliente() << "|"
             << devolucion.getRucCliente() << "|"
             << devolucion.getMotivo() << "|"
             << devolucion.getTotalDevolucion() << " "
             << devolucion.getActiva() << " "
             << devolucion.getItemsDevueltos().size() << "\n";

        // Guardar items de la devolución
        for (const auto& item : devolucion.getItemsDevueltos()) {
            file << "  " << item.getIdProducto() << " "
                 << item.getNombreProducto() << "|"
                 << item.getCantidad() << " "
                 << item.getPrecioUnitario() << "\n";
        }
    }
}

std::vector<Devolucion> ManejadorArchivos::cargarDevoluciones(const std::string& archivo) {
    std::vector<Devolucion> devoluciones;

    std::ifstream file(archivo);
    if (!file) {
        std::cout << "Archivo de devoluciones no encontrado: " << archivo << std::endl;
        return devoluciones;
    }

    int idDevolucion, idFacturaOriginal, numItems;
    std::string fechaHora, nombreCliente, rucCliente, motivo;
    float totalDevolucion;
    bool activa;

    while (file >> idDevolucion >> idFacturaOriginal) {
        file.ignore(1, ' ');
        std::getline(file, fechaHora, '|');
        std::getline(file, nombreCliente, '|');
        std::getline(file, rucCliente, '|');
        std::getline(file, motivo, '|');
        file >> totalDevolucion >> activa >> numItems;
        file.ignore(1000, '\n');

        // Crear devolución
        Devolucion devolucion(idDevolucion, idFacturaOriginal, fechaHora, nombreCliente, rucCliente, motivo);
        devolucion.setActiva(activa);

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

            ItemDevolucion item(idProducto, nombreProducto, cantidad, precioUnitario);
            devolucion.agregarItem(item);
        }

        devoluciones.push_back(devolucion);
    }

    return devoluciones;
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

// IDs para DEVOLUCIONES
void ManejadorArchivos::guardarUltimoIDDevolucion(int ultimoID, const std::string& archivo) {
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

int ManejadorArchivos::cargarUltimoIDDevolucion(const std::string& archivo) {
    std::ifstream file(archivo);
    int ultimoID = 19999;  // Empieza desde 20000

    if (file) {
        file >> ultimoID;
        if (ultimoID < 20000) {
            ultimoID = 19999;
        }
    }
    return ultimoID;
}




















