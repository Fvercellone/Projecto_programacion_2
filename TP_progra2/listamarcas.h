#ifndef LISTAMARCAS_H
#define LISTAMARCAS_H

#include <vector>
#include <string>
#include "Marca.h"
#include "Inventario.h"

class ListaMarcas {
private:
    std::vector<Marca> marcas;
    std::string archivoMarcas;
    int ultimoID;

public:
    ListaMarcas(const std::string& archivo = "DATA/marcas.txt");

    void agregarMarca(const Marca& m);
    Marca* buscarMarca(int id);
    void eliminarMarca(int idMarca, Inventario& inventario);
    void mostrarMarcas() const;

    // Métodos para archivos
    void guardarMarcas() const;
    void cargarMarcas();

private:
    int generarNuevoID();
    void cargarUltimoID();
    void guardarUltimoID() const;


};

#endif
