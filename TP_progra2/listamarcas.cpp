#include "ListaMarcas.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <direct.h>

inline void crearCarpetaSiNoExiste(const std::string& carpeta) {
    _mkdir(carpeta.c_str());
}

ListaMarcas::ListaMarcas(const std::string& archivo) : archivoMarcas(archivo) {
            size_t pos = archivo.find_last_of("/\\");
//    if (pos != std::string::npos) {
//        std::string carpeta = archivo.substr(0, pos);
//        crearCarpetaSiNoExiste(carpeta);
//        std::cout << "DEBUG: Carpeta creada/verificada: " << carpeta << std::endl;
//    }
//    std::cout << "DEBUG ListaMarcas: Ruta del archivo = " << archivoMarcas << std::endl;

    cargarMarcas();
}

void ListaMarcas::agregarMarca(const Marca& m) {


    // Verificar si la marca ya existe
    for (const auto& marca : marcas) {
        if (marca.getIdMarca() == m.getIdMarca()) {
            std::cout << "Error: Ya existe una marca con ese ID.\n";
            return;
        }
    }

    marcas.push_back(m);
    guardarMarcas();
    std::cout << "Marca agregada exitosamente!\n";
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
