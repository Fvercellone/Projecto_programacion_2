#pragma once
#include "TareaMenu.h"

class App
{
  public:
    App();
    void run();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

    TareaMenu _tareaMenu;
  private:
    int _cantidadOpciones;
};

