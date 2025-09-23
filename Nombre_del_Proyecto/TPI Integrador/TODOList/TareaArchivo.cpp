#include "TareaArchivo.h"
TareaArchivo::TareaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {

}

bool TareaArchivo::guardar(Tarea registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_nombreArchivo.c_str(), "ab");
  
  if(pFile == nullptr){
    return false;  
  }
  
  result = fwrite(&registro, sizeof(Tarea), 1, pFile);
  
  fclose(pFile);
  
  return result;
}

bool TareaArchivo::guardar(int pos, Tarea registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb+");
  
  if(pFile == nullptr){
    return false;  
  }

  fseek(pFile, pos * sizeof(Tarea) , SEEK_SET);
  
  result = fwrite(&registro, sizeof(Tarea), 1, pFile);
  
  fclose(pFile);
  
  return result;
}

int TareaArchivo::leerTodos(Tarea tareas[], int cantidad){
  FILE *pFile;
  int result;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return 0;  
  }
 
  result = fread(tareas, sizeof(Tarea), cantidad, pFile);
  
  fclose(pFile);
  
  return result; 

}

Tarea TareaArchivo::leer(int pos){
  FILE *pFile;
  Tarea registro;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    registro.setID(-1);
    return registro;  
  }
  
  fseek(pFile, pos * sizeof(Tarea) , SEEK_SET);

  if(!fread(&registro, sizeof(Tarea), 1, pFile)){
    registro.setID(-1);  
  }
  
  fclose(pFile);
  
  return registro;
}

int TareaArchivo::getCantidadRegistros(){
  FILE *pFile;
  bool result;
  int cantidad;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return 0; 
  }
  
  /// posiciona el cursor en el final del archivo 
  fseek(pFile, 0, SEEK_END);
  /// ftell da el bite donde esta el cursor actualmente 
  cantidad = ftell(pFile) / sizeof(Tarea);
  
  fclose(pFile);
  
  return cantidad;
}

int TareaArchivo::getNuevoID(){
 //return getCantidadRegistros() + 1;
 
 if(getCantidadRegistros() == 0){
  return 1; 
 }
 
 return leer(getCantidadRegistros() - 1).getID() + 1;
}


int TareaArchivo::buscarID(int id){
  FILE *pFile;
  Tarea registro;
  int pos = -1;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return -1;  
  }
   
  while(fread(&registro, sizeof(Tarea), 1, pFile)){
    if(registro.getID() == id){
      pos = ftell(pFile)/sizeof(Tarea) - 1;
      break;
    }
  }
 
  fclose(pFile);
  
  return pos;
}


bool TareaArchivo::eliminar(int pos){
  Tarea tarea = leer(pos);
  
  if(tarea.getID() != -1){
    tarea.setEliminado(true);
    return guardar(pos, tarea);
  }
  
  return false;
}
