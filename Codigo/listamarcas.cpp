#include "ListaMarcas.h"
#include <algorithm>
#include "Manejo_Archivos.h"

ListaMarcas::ListaMarcas() {
    marcas = ManejadorArchivos::cargarMarcas();
    ultimoID = ManejadorArchivos::cargarUltimoIDMarca();}

void ListaMarcas::agregarMarca(const Marca& m) {
    for (const auto& marca : marcas) {
        if (marca.getIdMarca() == m.getIdMarca()) {
            std::cout << "Error: Ya existe una marca con ese ID.\n";
            return;
        }
    }

    // Generar nuevo ID automáticamente
    int nuevoID = generarNuevoID();
    Marca marcaCopia = m;
    marcaCopia.setIdMarca(nuevoID);

    marcas.push_back(marcaCopia);
    ManejadorArchivos::guardarMarcas(marcas);
    std::cout << "Marca agregada exitosamente! ID asignado: " << nuevoID << "\n";
}

void ListaMarcas::eliminarMarca(int idMarca, Inventario& inventario) {
    Marca* marca = buscarMarca(idMarca);
    if (!marca) {
        std::cout << "Error: No se encontro la marca.\n";
        return;
    }

    if (!marca->getActivo()) {
        std::cout << "La marca ya está inactiva.\n";
        return;
    }

    if (idMarca == 0) {
        std::cout << "Error: No se puede eliminar la marca 'SIN MARCA'.\n";
        return;
    }

    // Verificar si hay productos con esta marca (sin filtrar por activo)
    int productosRelacionados = inventario.contarProductosPorMarca(idMarca);

    if (productosRelacionados > 0) {
        std::cout << "\nADVERTENCIA\n";
        std::cout << "Esta marca tiene " << productosRelacionados << " productos relacionados.\n";
        std::cout << "¿Seguro que deseas desactivar la marca? (s/n): ";

        char confirmacion;
        std::cin >> confirmacion;
        if (confirmacion != 's' && confirmacion != 'S') {
            std::cout << "Operacion cancelada.\n";
            return;
        }
    }

    marca->setActivo(false);  // ← Solo desactivar
    ManejadorArchivos::guardarMarcas(marcas);
    std::cout << "Marca marcada como INACTIVA.\n";
}

int ListaMarcas::generarNuevoID() {
    ultimoID++;
    ManejadorArchivos::guardarUltimoIDMarca(ultimoID);
    return ultimoID;
}


void ListaMarcas::activarMarca(int idMarca) {
    Marca* marca = buscarMarca(idMarca);
    if (marca) {
        if (marca->getActivo()) {
            std::cout << "La marca ya está ACTIVA.\n";
        } else {
            marca->setActivo(true);
            ManejadorArchivos::guardarMarcas(marcas);
            std::cout << "Marca ACTIVADA exitosamente!\n";
        }
    } else {
        std::cout << "Error: Marca no encontrada.\n";
    }
}

void ListaMarcas::desactivarMarca(int idMarca) {
    Marca* marca = buscarMarca(idMarca);
    if (marca) {
        if (!marca->getActivo()) {
            std::cout << "La marca ya está INACTIVA.\n";
        } else {
            // No permitir desactivar "SIN MARCA"
            if (idMarca == 0) {
                std::cout << "Error: No se puede desactivar la marca 'SIN MARCA'.\n";
                return;
            }
            marca->setActivo(false);
            ManejadorArchivos::guardarMarcas(marcas);
            std::cout << "Marca DESACTIVADA exitosamente!\n";
        }
    } else {
        std::cout << "Error: Marca no encontrada.\n";
    }
}

void ListaMarcas::mostrarMarcasInactivas() const {
    std::cout << "=== MARCAS INACTIVAS ===\n";
    int contador = 0;
    for (const auto& m : marcas) {
        if (!m.getActivo()) {
            m.mostrarInfo();
            contador++;
        }
    }
    std::cout << "Total marcas inactivas: " << contador << "\n";
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
    std::cout << "=== TODAS LAS MARCAS ===\n";
    for (const auto& m : marcas) {
        m.mostrarInfo();
    }
    std::cout << "Total marcas: " << marcas.size() << "\n";
}
