#include "SeleccionFunciones.h"
using namespace std;

int seleccionarMarca(ListaMarcas& listaMarcas) {
    const vector<Marca>& marcas = listaMarcas.getMarcas();

    if (marcas.empty()) {
        cout << "No hay marcas disponibles.\n";
        system("pause");
        return -1;
    }

    int indiceSeleccionado = Seleccionador::mostrar<Marca>(
        marcas,
        [](const Marca& m, bool sel) {
            cout << (sel ? " > " : "   ")
                 << "[" << m.getIdMarca() << "] "
                 << m.getNombre() << "\n";
        },
        "SELECCIONAR MARCA",
        6 // cantidad por página
    );

    if (indiceSeleccionado == -1) return -1;
    return marcas[indiceSeleccionado].getIdMarca();
}
