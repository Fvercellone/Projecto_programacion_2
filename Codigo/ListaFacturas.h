#ifndef LISTAFACTURAS_H
#define LISTAFACTURAS_H

#include <vector>
#include "Factura.h"
#include "ListaVentas.h"

class ListaFacturas {
private:
    std::vector<Factura> facturas;
    int ultimoID;

public:
    ListaFacturas();

    void generarFactura(ListaVentas& listaVentas);
    void anularFactura(int idFactura);
    void mostrarFacturas() const;
    void mostrarFacturasActivas() const;
    void mostrarFacturaCompleta(int idFactura) const;
    Factura* buscarFactura(int id);
    const std::vector<Factura>& getFacturas() const;

private:
    int generarNuevoID();
};

#endif
