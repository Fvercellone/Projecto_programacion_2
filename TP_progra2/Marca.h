#ifndef MARCA_H
#define MARCA_H

#include <string>
#include <iostream>

class Marca {
private:
    int idMarca;           // ID �nico generado autom�ticamente
    std::string nombre;    // Nombre de la marca

public:
    // Constructor
    Marca(int id, const std::string& n);

    // Getters
    int getIdMarca() const;
    std::string getNombre() const;

    // Setters
    void setNombre(const std::string& n);

    // Mostrar
    void mostrarInfo() const;
};

#endif
