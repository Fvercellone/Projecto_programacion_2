#include <cstring>
#include "Tarea.h"
using namespace std;

Tarea::Tarea()
:_id(0), _descripcion(""), _fecha(), _completado(false) {

}

Tarea::Tarea(int id, std::string descripcion, Fecha fecha, bool completado){
  setID(id);
  setDescripcion(descripcion);
  setFecha(fecha);
  setCompletado(completado);
}

void Tarea::setID(int id){
  _id = id;
}

int Tarea::getID(){
  return _id;
}

void Tarea::setDescripcion(std::string descripcion){
  strncpy(_descripcion, descripcion.c_str(), 299);
  _descripcion[299] = '\0';
}

std::string Tarea::getDescripcion(){
  return _descripcion;
}

void Tarea::setFecha(Fecha fecha){
  _fecha = fecha;
}

Fecha Tarea::getFecha(){
  return _fecha;
}

void Tarea::setCompletado(bool completado){
  _completado = completado;
}

bool Tarea::getCompletado(){
  return _completado;
}

void Tarea::setEliminado(bool eliminado){
  _eliminado = eliminado;
}

bool Tarea::getEliminado(){
  return _eliminado;
}

string Tarea::toString(){
  return to_string(_id) + 
  ", " + string(_descripcion) + 
  ", " + _fecha.toString() +
  ", " + to_string(_completado) +
  ", " + to_string(_eliminado) ;
}
