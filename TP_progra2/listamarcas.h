#ifndef LISTAMARCAS_H
#define LISTAMARCAS_H

#include <vector>
#include <string>
#include "Marca.h"

class ListaMarcas {
private:
    std::vector<Marca> marcas;
    std::string archivoMarcas;

public:
    ListaMarcas(const std::string& archivo = "DATA/marcas.txt");

    void agregarMarca(const Marca& m);
    Marca* buscarMarca(int id);
    void mostrarMarcas() const;

    // Métodos para archivos
    void guardarMarcas() const;
    void cargarMarcas();
};

#endif
