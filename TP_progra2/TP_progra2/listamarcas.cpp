#include "ListaMarcas.h"
#include <iostream>

void ListaMarcas::agregarMarca(Marca* m) {
    marcas.push_back(m);
}

Marca* ListaMarcas::buscarMarca(int id) {
    for (auto* m : marcas) {
        if (m->getIdMarca() == id) return m;
    }
    return nullptr;
}

void ListaMarcas::mostrarMarcas() const {
    std::cout << "=== MARCAS ===\n";
    for (auto* m : marcas) {
        m->mostrarInfo();
    }
}
