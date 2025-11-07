#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
#include <fstream>

class Producto {
private:
    int idProducto;
    std::string nombre;
    std::string descripcion;
    float precio;
    int stock;
    int idMarca;
    bool activo;  // ← NUEVO

public:
    // ACTUALIZAR constructor
    Producto(int idP = 0, const std::string& n="", const std::string& d="", float p=0, int s=0, int idM=0, bool a=true);

    // Getters
    int getIdProducto() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    float getPrecio() const;
    int getStock() const;
    int getIdMarca() const;
    bool getActivo() const;  // ← NUEVO

    // Setters
    void setIdProducto(int id);
    void setNombre(const std::string& n);
    void setDescripcion(const std::string& d);
    void setPrecio(float p);
    void setStock(int s);
    void setIdMarca(int idM);
    void setActivo(bool a);  // ← NUEVO

    void mostrarInfo() const;
    void agregarStock(int cantidad);
    void quitarStock(int cantidad);
};

#endif
