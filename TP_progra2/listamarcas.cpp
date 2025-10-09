#include "ListaMarcas.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <direct.h>

const int PRIMER_ID_MARCA = 20001;

inline void crearCarpetaSiNoExiste(const std::string& carpeta) {
    _mkdir(carpeta.c_str());
}

ListaMarcas::ListaMarcas(const std::string& archivo) : archivoMarcas(archivo), ultimoID(PRIMER_ID_MARCA - 1) {
    // PRIMERO cargar el último ID
    cargarUltimoID();

    // LUEGO cargar las marcas
    cargarMarcas();

    size_t pos = archivo.find_last_of("/\\");
    if (pos != std::string::npos) {
        std::string carpeta = archivo.substr(0, pos);
        crearCarpetaSiNoExiste(carpeta);
    }

    if (!buscarMarca(0)) {
        Marca marcaSinMarca(0, "SIN MARCA");
        marcas.push_back(marcaSinMarca);
        guardarMarcas();
        std::cout << "Marca 'SIN MARCA' creada automaticamente.\n";
    }
}

void ListaMarcas::agregarMarca(const Marca& m) {
    // Generar nuevo ID automáticamente
    int nuevoID = generarNuevoID();

    // Crear copia de la marca con el nuevo ID
    Marca marcaCopia = m;
    marcaCopia.setIdMarca(nuevoID);  // setteamos el ID para cada nueva marca

    marcas.push_back(marcaCopia);
    guardarMarcas();
    std::cout << "Marca agregada exitosamente! ID asignado: " << nuevoID << "\n";
}

Marca* ListaMarcas::buscarMarca(int id) {
    for (auto& m : marcas) {
        if (m.getIdMarca() == id) {
            return &m;
        }
    }
    return nullptr;
}

void ListaMarcas::mostrarMarcas() const {
    std::cout << "=== MARCAS ===\n";
    for (const auto& m : marcas) {
        m.mostrarInfo();
    }
}

// Métodos para archivos
void ListaMarcas::guardarMarcas() const {
    std::ofstream archivo(archivoMarcas);
    if (!archivo) {
        std::cout << "Error al guardar marcas.\n";
        return;
    }

    for (const auto& marca : marcas) {
        marca.guardarEnArchivo(archivo);
    }
}

void ListaMarcas::cargarMarcas() {
    marcas.clear();

    std::ifstream archivo(archivoMarcas);
    if (!archivo) {
        std::cout << "Archivo de marcas no encontrado. Se creara uno nuevo.\n";
        return;
    }

    Marca m;
    while (m.cargarDesdeArchivo(archivo)) {
        marcas.push_back(m);
    }

    std::cout << "Cargadas " << marcas.size() << " marcas.\n";
}

void ListaMarcas::eliminarMarca(int idMarca, Inventario& inventario) {
    Marca* marca = buscarMarca(idMarca);
    if (!marca) {
        std::cout << "Error: No se encontro la marca.\n";
        return;
    }

    // No permitir eliminar la marca "SIN MARCA"
    if (idMarca == 0) {
        std::cout << "Error: No se puede eliminar la marca 'SIN MARCA'.\n";
        return;
    }

    // Verificar si hay productos con esta marca
    int productosRelacionados = inventario.contarProductosPorMarca(idMarca);

    if (productosRelacionados > 0) {
        std::cout << "\nADVERTENCIA\n";
        std::cout << "Esta marca tiene " << productosRelacionados << " productos relacionados.\n";

        // MOSTRAR los productos específicos

        std::cout << "\n";
        inventario.mostrarProductosPorMarca(idMarca);
        std::cout << "\n";


        std::cout << "Los productos se reasignaran a 'SIN MARCA'.\n";
        std::cout << "\n";
        std::cout << "Seguro que deseas eliminar? (s/n): ";

        char confirmacion;
        std::cin >> confirmacion;
        if (confirmacion != 's' && confirmacion != 'S') {
            std::cout << "Eliminacion cancelada.\n";
            return;
        }

        // Reasignar productos a "SIN MARCA"
        inventario.reasignarProductosAMarca(idMarca, 0);
    }

    // Proceder con eliminación de marca
    auto it = std::remove_if(marcas.begin(), marcas.end(),
        [idMarca](const Marca& m) { return m.getIdMarca() == idMarca; });

    marcas.erase(it, marcas.end());
    guardarMarcas();
    std::cout << "Marca eliminada. Productos reasignados a 'SIN MARCA'.\n";
}


/// Genera un nuevo ID autoincremental para marcas
int ListaMarcas::generarNuevoID() {
    ultimoID++;  // Incrementa el contador
    guardarUltimoID();  // Guarda inmediatamente
    return ultimoID;
}

void ListaMarcas::cargarUltimoID() {
    std::ifstream archivo("DATA/ultimo_id_marcas.txt");
    if (archivo) {
        archivo >> ultimoID;
        // VERIFICAR que no sea un valor corrupto
        if (ultimoID < PRIMER_ID_MARCA) {
            ultimoID = PRIMER_ID_MARCA - 1;
        }
    } else {
        // Si no existe el archivo
        ultimoID = PRIMER_ID_MARCA - 1;
    }
}

/// Guarda el último ID en archivo
void ListaMarcas::guardarUltimoID() const {
    std::ofstream archivo("DATA/ultimo_id_marcas.txt");  // ← ARCHIVO DIFERENTE
    if (archivo) {
        archivo << ultimoID;
    }
}
