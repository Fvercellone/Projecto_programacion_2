#pragma once
#include "TareaManager.h"

class TareaMenu
{
  public:
    TareaMenu();
    void mostrar();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

    TareaManager _tareaManager;
  private:
    int _cantidadOpciones;
};

