#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <string>
#include "Producto.h"
#include "MedioPago.h"

class ItemVenta {
private:
    int idProducto;
    std::string nombreProducto;
    int cantidad;
    float precioUnitario;

public:
    ItemVenta(int idProd = 0, const std::string& nombre = "", int cant = 0, float precio = 0.0f);

    // Getters
    int getIdProducto() const;
    std::string getNombreProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    float getSubtotal() const;

    // Setters
    void setCantidad(int cant);
    void setPrecioUnitario(float precio);

    void mostrarInfo() const;
};

class Venta {
private:
    int idVenta;
    std::vector<ItemVenta> items;
    int idMedioPago;
    std::string nombreMedioPago;
    double ajusteMedioPago;
    float subtotal;
    float total;
    bool activo;

public:
    Venta(int idV = 0, int idMedioP = 0, const std::string& nomMedioP = "", double ajuste = 1.0);

    // Getters
    int getIdVenta() const;
    int getIdMedioPago() const;
    std::string getNombreMedioPago() const;
    double getAjusteMedioPago() const;
    float getSubtotal() const;
    float getTotal() const;
    bool getActivo() const;
    const std::vector<ItemVenta>& getItems() const;

    // Setters
    void setIdVenta(int id);
    void setMedioPago(int id, const std::string& nombre, double ajuste);
    void setActivo(bool a);

    // Métodos
    void agregarItem(const ItemVenta& item);
    void calcularTotales();
    void mostrarVenta() const;
};

#endif
