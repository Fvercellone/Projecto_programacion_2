#ifndef LISTAMARCAS_H
#define LISTAMARCAS_H

#include <vector>
#include <string>
#include "Marca.h"
#include "Inventario.h"

class Inventario;

class ListaMarcas {
private:
    std::vector<Marca> marcas;
    int ultimoID;  // ← NUEVO

public:
    ListaMarcas();  // ← SIN parámetro

    void agregarMarca(const Marca& m);
    void eliminarMarca(int idMarca, Inventario& inventario);
    void activarMarca(int idMarca);
    void desactivarMarca(int idMarca);
    void mostrarMarcasInactivas() const;
    Marca* buscarMarca(int id);
    void mostrarMarcas() const;
    const std::vector<Marca>& getMarcas() const { return marcas; }  // ← NUEVO

private:
    int generarNuevoID();
};

#endif
