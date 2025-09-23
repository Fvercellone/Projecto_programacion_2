#pragma once
#include <string>
#include "Tarea.h"

class TareaArchivo
{
  public:
    TareaArchivo(std::string nombreArchivo = "tareas.dat");
    bool guardar(Tarea registro);
    bool guardar(int pos, Tarea tarea);
    int buscarID(int id);
    bool eliminar(int pos);
    
    // bool modificar(Tarea tarea);
    
    
    Tarea leer(int pos);
    int leerTodos(Tarea tareas[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();
    
    
    
  private:
    std::string _nombreArchivo;
};


