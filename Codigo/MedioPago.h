#ifndef MEDIOPAGO_H
#define MEDIOPAGO_H

#include <string>
#include <iostream>

class MedioPago {
private:
    int idMedioPago;
    std::string nombre;
    double ajuste;  // 0.9 = 10% descuento, 1.1 = 10% incremento, 1.0 = sin cambio
    bool activo;

public:
    MedioPago(int id = 0, const std::string& n = "", double a = 1.0, bool act = true);

    // Getters
    int getIdMedioPago() const;
    std::string getNombre() const;
    double getAjuste() const;
    bool getActivo() const;

    // Setters
    void setIdMedioPago(int id);
    void setNombre(const std::string& n);
    void setAjuste(double a);
    void setActivo(bool act);

    // Métodos
    void mostrarInfo() const;
    double aplicarAjuste(double monto) const;
    std::string getTipoAjuste() const;  // Devuelve "Descuento", "Incremento" o "Sin ajuste"
};

#endif
