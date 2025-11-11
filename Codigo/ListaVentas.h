#ifndef LISTAVENTAS_H
#define LISTAVENTAS_H

#include <vector>
#include "Venta.h"
#include "Inventario.h"
#include "ListaMediosPago.h"

class ListaVentas {
private:
    std::vector<Venta> ventas;
    int ultimoID;

public:
    ListaVentas();

    void crearVenta(Inventario& inventario, ListaMediosPago& listaMediosPago);
    void anularVenta(int idVenta);
    void mostrarVentas() const;
    void mostrarVentasActivas() const;
    Venta* buscarVenta(int id);
    const std::vector<Venta>& getVentas() const;

private:
    int generarNuevoID();
    bool descontarStock(Inventario& inventario, const Venta& venta);
    void restaurarStock(Inventario& inventario, const Venta& venta);
};

#endif
