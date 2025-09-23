#include <iostream>
#include "TareaMenu.h"
using namespace std;

TareaMenu::TareaMenu(){
  _cantidadOpciones = 5;
}
void TareaMenu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void TareaMenu::mostrarOpciones(){
  cout << "--- MENU TAREAS ---" << endl;
  cout << "1- CARGAR TAREA "<<endl;
  cout << "2- MOSTRAR TAREAS "<<endl;
  cout << "3- MARCAR TAREA "<<endl;
  cout << "4- ELIMINAR TAREA "<<endl;
  cout << "5- MOSTRAR ORDENADOS ALFABETICAMENTE "<<endl;
  cout << "0- Salir "<<endl;
}

int TareaMenu::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;
  
  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..."<<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}
void TareaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _tareaManager.cargarTarea();
  break;
  case 2:
    _tareaManager.listarTareas();
  break;
  case 3:
    _tareaManager.marcarTarea();
  break;
  case 4:
    _tareaManager.eliminarTarea();
  break;
  case 5:
    _tareaManager.mostrarTareaOrdenada();
  break;  

  }
}
