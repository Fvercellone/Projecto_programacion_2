#include "Marca.h"

Marca::Marca(int id, const std::string& n) : idMarca(id), nombre(n) {}

int Marca::getIdMarca() const { return idMarca; }
std::string Marca::getNombre() const { return nombre; }
void Marca::setNombre(const std::string& n) { nombre = n; }

void Marca::mostrarInfo() const {
    std::cout << "Marca[" << idMarca << "] - " << nombre << "\n";
}
