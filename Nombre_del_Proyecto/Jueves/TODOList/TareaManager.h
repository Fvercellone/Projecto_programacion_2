#pragma once
#include "TareaArchivo.h"

class TareaManager
{
  public:
    TareaManager();
    void cargarTarea();
    void listarTareas();
    void marcarTarea();
    void eliminarTarea();
    void mostrarTareaOrdenada();
    
  protected:
    void mostrarTarea(Tarea tarea);
    
  private:
    TareaArchivo _repo;
};
