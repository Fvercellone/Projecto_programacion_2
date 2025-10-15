#include "MenuPrincipal.h"

int main() {

    ListaMarcas listaMarcas("DATA/marcas.txt");
    Inventario inventario("DATA/productos.txt");
    menuPrincipal(inventario, listaMarcas);

    return 0;
}
