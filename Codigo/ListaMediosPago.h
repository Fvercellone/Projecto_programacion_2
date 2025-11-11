#ifndef LISTAMEDIOSPAGO_H
#define LISTAMEDIOSPAGO_H

#include <vector>
#include <string>
#include "MedioPago.h"

class ListaMediosPago {
private:
    std::vector<MedioPago> mediosPago;
    int ultimoID;

public:
    ListaMediosPago();

    void agregarMedioPago(const MedioPago& mp);
    void eliminarMedioPago(int idMedioPago);
    void activarMedioPago(int idMedioPago);
    void desactivarMedioPago(int idMedioPago);
    MedioPago* buscarMedioPago(int id);
    void mostrarMediosPago() const;
    void mostrarMediosPagoActivos() const;
    const std::vector<MedioPago>& getMediosPagoActivos() const;

private:
    int generarNuevoID();
};

#endif
