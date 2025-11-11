#ifndef MENUFACTURAS_H
#define MENUFACTURAS_H

#include "ListaFacturas.h"
#include "ListaVentas.h"

class MenuFacturas {
public:
    void mostrarMenu(ListaVentas& listaVentas);

private:
    void generarFactura(ListaFacturas& listaFacturas, ListaVentas& listaVentas);
    void anularFactura(ListaFacturas& listaFacturas);
    void mostrarFacturas(const ListaFacturas& listaFacturas);
    void mostrarFacturasActivas(const ListaFacturas& listaFacturas);
    void mostrarFacturaCompleta(const ListaFacturas& listaFacturas);
};

#endif
