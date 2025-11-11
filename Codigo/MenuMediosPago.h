#ifndef MENUMEDIOSPAGO_H
#define MENUMEDIOSPAGO_H

#include "ListaMediosPago.h"

class MenuMediosPago
{
    public:
        MenuMediosPago();
        virtual ~MenuMediosPago();

        void mostrarMenu();

    private:
        void agregarMedioPago(ListaMediosPago& lista);
        void activarMedioPago(ListaMediosPago& lista);
        void desactivarMedioPago(ListaMediosPago& lista);
        void eliminarMedioPago(ListaMediosPago& lista);
};

#endif // MENUMEDIOSPAGO_H
