#include "Marca.h"

// Constructor actualizado
Marca::Marca(int id, const std::string& n, bool a)
    : idMarca(id), nombre(n), activo(a) {}

int Marca::getIdMarca() const { return idMarca; }
std::string Marca::getNombre() const { return nombre; }
void Marca::setNombre(const std::string& n) { nombre = n; }
bool Marca::getActivo() const { return activo; }
void Marca::setActivo(bool a) { activo = a; }

// mostrarInfo para mostrar estado
void Marca::mostrarInfo() const {
    std::string estado = activo ? "ACTIVA" : "INACTIVA";
    std::cout << "Marca[" << idMarca << "] - " << nombre
              << " | Estado: " << estado << "\n";
}



void Marca::setIdMarca(int id) {
    idMarca = id;
}
