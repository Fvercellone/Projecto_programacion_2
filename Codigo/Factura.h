#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include "Venta.h"

class Factura {
private:
    int idFactura;
    int idVenta;
    std::string fechaHora;
    std::string nombreCliente;
    std::string rucCliente;
    std::string direccionCliente;
    float subtotal;
    float total;
    bool activo;

public:
    Factura(int idFact = 0, int idVent = 0, const std::string& fecha = "",
            const std::string& cliente = "CONSUMIDOR FINAL",
            const std::string& ruc = "9999999999999",
            const std::string& direccion = "NO ESPECIFICADA");

    // Getters
    int getIdFactura() const;
    int getIdVenta() const;
    std::string getFechaHora() const;
    std::string getNombreCliente() const;
    std::string getRucCliente() const;
    std::string getDireccionCliente() const;
    float getSubtotal() const;
    float getTotal() const;
    bool getActivo() const;

    // Setters
    void setIdFactura(int id);
    void setIdVenta(int id);
    void setFechaHora(const std::string& fecha);
    void setCliente(const std::string& nombre, const std::string& ruc, const std::string& direccion);
    void setTotales(float sub, float tot);
    void setActivo(bool a);

    // Métodos
    void generarDesdeVenta(const Venta& venta);
    void mostrarFactura() const;
    void mostrarFacturaCompleta() const;

private:
    std::string obtenerFechaHoraActual();
};

#endif
