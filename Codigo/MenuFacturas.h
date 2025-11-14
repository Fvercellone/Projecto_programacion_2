#ifndef MENUFACTURAS_H
#define MENUFACTURAS_H

#include "Inventario.h"
#include "Devolucion.h"
#include "Manejo_Archivos.h"

class MenuFacturas {
public:
    void mostrarMenu(Inventario& inventario);

private:
    void mostrarTodasFacturas();
    void buscarFacturaPorID();
    void realizarDevolucion(Inventario& inventario);
    void mostrarTodasDevoluciones();
};

#endif
