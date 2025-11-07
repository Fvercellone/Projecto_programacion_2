#ifndef MARCA_H
#define MARCA_H

#include <string>
#include <iostream>
#include <fstream>

class Marca {
private:
    int idMarca;
    std::string nombre;
    bool activo;  // ← NUEVO

public:
    // ACTUALIZAR constructor
    Marca(int id = 0, const std::string& n = "", bool a = true);

    // Getters
    int getIdMarca() const;
    std::string getNombre() const;
    bool getActivo() const;  // ← NUEVO

    // Setters
    void setIdMarca(int id);
    void setNombre(const std::string& n);
    void setActivo(bool a);  // ← NUEVO

    void mostrarInfo() const;
};

#endif
