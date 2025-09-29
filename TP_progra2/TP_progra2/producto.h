#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

class Producto {
private:
    int idProducto;          // ID único del producto
    std::string nombre;
    std::string descripcion;
    float precio;
    int stock;
    int idMarca;             // Relación con Marca

public:
    // Constructor
    Producto(int idP, const std::string& n, const std::string& d, float p, int s, int idM);

    // Getters
    int getIdProducto() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    float getPrecio() const;
    int getStock() const;
    int getIdMarca() const;   // Nuevo getter

    // Setters
    void setNombre(const std::string& n);
    void setDescripcion(const std::string& d);
    void setPrecio(float p);
    void setStock(int s);
    void setIdMarca(int idM); // Nuevo setter

    // Métodos
    void mostrarInfo() const;
    void agregarStock(int cantidad);
    void quitarStock(int cantidad);
};

#endif
