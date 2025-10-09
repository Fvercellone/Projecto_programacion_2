#ifndef MARCA_H
#define MARCA_H

#include <string>
#include <iostream>
#include <fstream>

class Marca {
private:
    int idMarca;
    std::string nombre;

public:
    // Constructor
    Marca(int id = 0, const std::string& n = "");

    // Getters
    int getIdMarca() const;
    std::string getNombre() const;

    // Setters
    void setIdMarca(int id);
    void setNombre(const std::string& n);

    // Mostrar
    void mostrarInfo() const;

    // Métodos para archivos
    void guardarEnArchivo(std::ofstream& archivo) const;
    bool cargarDesdeArchivo(std::ifstream& archivo);
};

#endif
