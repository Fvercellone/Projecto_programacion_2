#include <iostream>
#include "Producto.h"

int main() {
    Producto p1(1, "Lapicera Azul", "Bolígrafo tinta azul", 120.5f, 50, 10);

    p1.mostrarInfo();
    p1.agregarStock(20);
    p1.mostrarInfo();
    p1.quitarStock(10);
    p1.mostrarInfo();

    return 0;
}
