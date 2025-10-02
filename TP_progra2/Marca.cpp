#include "Marca.h"

Marca::Marca(int id, const std::string& n) : idMarca(id), nombre(n) {}

int Marca::getIdMarca() const { return idMarca; }
std::string Marca::getNombre() const { return nombre; }
void Marca::setNombre(const std::string& n) { nombre = n; }

void Marca::mostrarInfo() const {
    std::cout << "Marca[" << idMarca << "] - " << nombre << "\n";
}

// Guardar marca en archivo
void Marca::guardarEnArchivo(std::ofstream& archivo) const {
    archivo << idMarca << " " << nombre << "\n";
}

// Cargar marca desde archivo
bool Marca::cargarDesdeArchivo(std::ifstream& archivo) {
    if (!(archivo >> idMarca)) {
        return false;
    }

    // Leer el nombre (puede contener espacios)
    archivo.ignore(); // Ignorar el espacio después del ID
    std::getline(archivo, nombre);

    return true;
}
