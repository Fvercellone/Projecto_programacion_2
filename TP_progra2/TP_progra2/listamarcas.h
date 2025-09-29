#ifndef LISTAMARCAS_H
#define LISTAMARCAS_H

#include <vector>
#include "Marca.h"

class ListaMarcas {
private:
    std::vector<Marca*> marcas;

public:
    void agregarMarca(Marca* m);
    Marca* buscarMarca(int id);
    void mostrarMarcas() const;
};

#endif
