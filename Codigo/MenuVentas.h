#ifndef MENUVENTAS_H
#define MENUVENTAS_H

#include "ListaVentas.h"
#include "Inventario.h"
#include "ListaMediosPago.h"

class MenuVentas {
public:
    void mostrarMenu(Inventario& inventario, ListaMediosPago& listaMediosPago);

private:
    void crearVenta(ListaVentas& listaVentas, Inventario& inventario, ListaMediosPago& listaMediosPago);
    void anularVenta(ListaVentas& listaVentas);
    void mostrarVentas(const ListaVentas& listaVentas);
    void mostrarVentasActivas(const ListaVentas& listaVentas);
};

#endif
