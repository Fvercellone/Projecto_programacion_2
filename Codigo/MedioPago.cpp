#include "MedioPago.h"

MedioPago::MedioPago(int id, const std::string& n, double a, bool act)
    : idMedioPago(id), nombre(n), ajuste(a), activo(act) {}

// Getters
int MedioPago::getIdMedioPago() const { return idMedioPago; }
std::string MedioPago::getNombre() const { return nombre; }
double MedioPago::getAjuste() const { return ajuste; }
bool MedioPago::getActivo() const { return activo; }

// Setters
void MedioPago::setIdMedioPago(int id) { idMedioPago = id; }
void MedioPago::setNombre(const std::string& n) { nombre = n; }
void MedioPago::setAjuste(double a) { ajuste = a; }
void MedioPago::setActivo(bool act) { activo = act; }

// Aplicar ajuste a un monto
double MedioPago::aplicarAjuste(double monto) const {
    return monto * ajuste;
}

// Determinar tipo de ajuste
std::string MedioPago::getTipoAjuste() const {
    if (ajuste < 1.0) return "Descuento";
    if (ajuste > 1.0) return "Incremento";
    return "Sin ajuste";
}

// Mostrar información
void MedioPago::mostrarInfo() const {
    std::string estado = activo ? "ACTIVO" : "INACTIVO";
    std::string tipo = getTipoAjuste();
    double porcentaje = 0.0;

    if (ajuste < 1.0) porcentaje = (1.0 - ajuste) * 100;
    else if (ajuste > 1.0) porcentaje = (ajuste - 1.0) * 100;

    std::cout << "MedioPago[" << idMedioPago << "] " << nombre
              << " | Ajuste: " << tipo;

    if (porcentaje > 0) {
        std::cout << " " << porcentaje << "%";
    }

    std::cout << " | Estado: " << estado << "\n";
}
