#ifndef MEDIOPAGO_H
#define MEDIOPAGO_H

#include <string>
#include <iostream>
#include <fstream>

class MedioPago
{
    //aca encapsulamos los atributos
    //asi solo los metodos pueden acceder a ellos
    private:
        int idMedioPago; //ejemplo: 10001 para efectivo
        std::string nombre;   //"Efectivo", "Debito", "Credito"...
        float descuento;      //porcentaje de descuento 10.0???

    //esto se puede utilizar fuera de la clase, aca deberiamos de usar los metodos
    public:
        //funcion constructora
        // MedioPago m1; // llama al constructor por defecto → id=0, nombre="", descuento=0
        // MedioPago m2(30001, "Efectivo", 10.0); // llama al constructor con esos valores
        MedioPago(int id = 0, const std::string& n = "", float d = 0.0f); //ponemos valores por defecto asi podemos crear un objeto vacio
        virtual ~MedioPago(); // ??? que puso lauti ni idea
        //Ese es el destructor.

        //Un destructor es una función especial que se ejecuta automáticamente cuando un objeto se destruye (por ejemplo, al salir de un bloque o al liberar memoria).

        //Su nombre siempre empieza con ~ (tilde).

        //Sirve para limpiar recursos, cerrar archivos, liberar memoria, etc.

        //Getters
        int getIdMedioPago() const;   //ponemos const en todos porque estas funciones sirven para traer lo
        std::string getNombre() const; //que tiene por defecto y no lo queremos modificar.
        float getDescuento() const;


        //Setters
        void setIdMedioPago(int id);          //setters para modificar atributos
        void setNombre(const std::string& n); //despues si alguein pone un descuento no disponible como -5 o 200
        void setDescuento(float d);           //en el .cpp lo podemos corregir con una validacion.


        //mostrar informacion en pantalla
        void mostrarInfo() const;

        // Métodos para archivos
        void guardarEnArchivo(std::ofstream& archivo) const;
        bool cargarDesdeArchivo(std::ifstream& archivo);  //esto lo copie de lauti pero no deberia de estar aca

    protected:



};

#endif // MEDIOPAGO_H
