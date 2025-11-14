#ifndef DEVOLUCION_H
#define DEVOLUCION_H

#include "Factura.h"
#include <vector>
#include <string>

class ItemDevolucion {
private:
    int idProducto;
    std::string nombreProducto;
    int cantidad;
    float precioUnitario;

public:
    ItemDevolucion(int idProd = 0, const std::string& nombre = "", int cant = 0, float precio = 0.0f);

    // Getters
    int getIdProducto() const;
    std::string getNombreProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    float getSubtotal() const;

    void mostrarInfo() const;
};

class Devolucion {
private:
    int idDevolucion;
    int idFacturaOriginal;
    std::string fechaHora;
    std::string nombreCliente;
    std::string rucCliente;
    std::string motivo;
    std::vector<ItemDevolucion> itemsDevueltos;
    float totalDevolucion;
    bool activa;

public:
    Devolucion(int idDev = 0, int idFactura = 0, const std::string& fecha = "",
               const std::string& cliente = "", const std::string& ruc = "",
               const std::string& mot = "");

    // Getters
    int getIdDevolucion() const;
    int getIdFacturaOriginal() const;
    std::string getFechaHora() const;
    std::string getNombreCliente() const;
    std::string getRucCliente() const;
    std::string getMotivo() const;
    float getTotalDevolucion() const;
    bool getActiva() const;
    const std::vector<ItemDevolucion>& getItemsDevueltos() const;

    // Setters
    void setIdDevolucion(int id);
    void setFacturaOriginal(int idFactura, const std::string& cliente, const std::string& ruc);
    void setMotivo(const std::string& mot);
    void setActiva(bool a);

    // Métodos
    void agregarItem(const ItemDevolucion& item);
    void calcularTotal();
    void mostrarDevolucion() const;
    void mostrarDevolucionCompleta() const;

private:
    std::string obtenerFechaHoraActual();
};

#endif
