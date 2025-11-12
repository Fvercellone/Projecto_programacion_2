#include "ListaMediosPago.h"
#include "Manejo_Archivos.h"
#include <algorithm>

ListaMediosPago::ListaMediosPago() {
    mediosPago = ManejadorArchivos::cargarMediosPago();
    ultimoID = ManejadorArchivos::cargarUltimoIDMedioPago();
}

void ListaMediosPago::agregarMedioPago(const MedioPago& mp) {
    for (const auto& medio : mediosPago) {
        if (medio.getIdMedioPago() == mp.getIdMedioPago()) {
            std::cout << "Error: Ya existe un medio de pago con ese ID.\n";
            return;
        }
    }

    // Generar nuevo ID automáticamente
    int nuevoID = generarNuevoID();
    MedioPago medioCopia = mp;
    medioCopia.setIdMedioPago(nuevoID);

    mediosPago.push_back(medioCopia);
    ManejadorArchivos::guardarMediosPago(mediosPago);
    std::cout << "Medio de pago agregado exitosamente! ID asignado: " << nuevoID << "\n";
    system("pause");    system("cls");
}

void ListaMediosPago::eliminarMedioPago(int idMedioPago) {
    system("cls");
    MedioPago* medio = buscarMedioPago(idMedioPago);
    if (medio) {
        if (!medio->getActivo()) {
            std::cout << "El medio de pago ya está INACTIVO.\n";
            return;
        }
        medio->setActivo(false);
        ManejadorArchivos::guardarMediosPago(mediosPago);
        std::cout << "Medio de pago marcado como INACTIVO.\n";
    } else {
        std::cout << "Error: Medio de pago no encontrado.\n";
    }
    system("pause");
    system("cls");
}

void ListaMediosPago::activarMedioPago(int idMedioPago) {
    system("cls");
    MedioPago* medio = buscarMedioPago(idMedioPago);
    if (medio) {
        if (medio->getActivo()) {
            std::cout << "El medio de pago ya está ACTIVO.\n";
        } else {
            medio->setActivo(true);
            ManejadorArchivos::guardarMediosPago(mediosPago);
            std::cout << "Medio de pago ACTIVADO exitosamente!\n";
        }
    } else {
        std::cout << "Error: Medio de pago no encontrado.\n";
    }
    system("pause");
    system("cls");
}

void ListaMediosPago::desactivarMedioPago(int idMedioPago) {
    system("cls");
    MedioPago* medio = buscarMedioPago(idMedioPago);
    if (medio) {
        if (!medio->getActivo()) {
            std::cout << "El medio de pago ya está INACTIVO.\n";
        } else {
            medio->setActivo(false);
            ManejadorArchivos::guardarMediosPago(mediosPago);
            std::cout << "Medio de pago DESACTIVADO exitosamente!\n";
        }
    } else {
        std::cout << "Error: Medio de pago no encontrado.\n";
    }
    system("pause");
    system("cls");
}

MedioPago* ListaMediosPago::buscarMedioPago(int id) {
    system("cls");
    for (auto& mp : mediosPago) {
        if (mp.getIdMedioPago() == id) {
            return &mp;
        }
    }
    return nullptr;
}

// NUEVA función - Solo busca medios de pago ACTIVOS
MedioPago* ListaMediosPago::buscarMedioPagoActivo(int id) {
    system("cls");
    for (auto& mp : mediosPago) {
        if (mp.getIdMedioPago() == id && mp.getActivo()) {
            return &mp;
        }
    }
    return nullptr;
}

void ListaMediosPago::mostrarMediosPago() const {
    system("cls");
    std::cout << "=== TODOS LOS MEDIOS DE PAGO ===\n";
    for (const auto& mp : mediosPago) {
        mp.mostrarInfo();
    }
    std::cout << "Total medios de pago: " << mediosPago.size() << "\n";
    system("pause");
    system("cls");
}

void ListaMediosPago::mostrarMediosPagoActivos() const {
    system("cls");
    std::cout << "=== MEDIOS DE PAGO ACTIVOS ===\n";
    int contador = 0;
    for (const auto& mp : mediosPago) {
        if (mp.getActivo()) {
            mp.mostrarInfo();
            contador++;
        }
    }
    std::cout << "Total medios de pago activos: " << contador << "\n";
}

const std::vector<MedioPago>& ListaMediosPago::getMediosPagoActivos() const {
    static std::vector<MedioPago> mediosActivos;
    mediosActivos.clear();
    for (const auto& mp : mediosPago) {
        if (mp.getActivo()) {
            mediosActivos.push_back(mp);
        }
    }
    return mediosActivos;
}

int ListaMediosPago::generarNuevoID() {
    ultimoID++;
    ManejadorArchivos::guardarUltimoIDMedioPago(ultimoID);
    return ultimoID;
}
