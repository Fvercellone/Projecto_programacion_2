#ifndef SELECCIONADOR_H
#define SELECCIONADOR_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <functional>
using namespace std;

class Seleccionador {
public:
    template<typename T>
    static int mostrar(
        const vector<T>& elementos,
        function<void(const T&, bool)> mostrarElemento,
        const string& titulo = "Seleccionar opción",
        int porPagina = 5
    ) {
        if (elementos.empty()) {
            cout << "No hay elementos disponibles.\n";
            system("pause");
            return -1;
        }

        int indice = 0;
        int pagina = 0;
        int total = elementos.size();
        int totalPaginas = (total + porPagina - 1) / porPagina;

        while (true) {
            system("cls");
            cout << "=== " << titulo << " ===\n";
            cout << "Usa las flechas De Arriba y Abajo para moverte, Izq. y Der. para cambiar pagina."<<endl<<"ENTER para seleccionar, ESC para cancelar.\n\n";

            int inicio = pagina * porPagina;
            int fin = min(inicio + porPagina, total);

            for (int i = inicio; i < fin; i++) {
                bool seleccionado = (i == indice);
                mostrarElemento(elementos[i], seleccionado);
            }

            cout << "\nPagina " << (pagina + 1) << " / " << totalPaginas << "\n";

            int tecla = _getch();
            if (tecla == 13) return indice;      // ENTER
            if (tecla == 27) return -1;          // ESC para cancelar
            if (tecla == 224) {                  // Flechas
                int dir = _getch();
                if (dir == 72 && indice > 0) indice--;                 // ↑
                else if (dir == 80 && indice < total - 1) indice++;    // ↓
                else if (dir == 75 && pagina > 0) {                    // ←
                    pagina--;
                    indice = pagina * porPagina;
                } else if (dir == 77 && pagina < totalPaginas - 1) {   // →
                    pagina++;
                    indice = pagina * porPagina;
                }
            }
        }
    }
};

#endif
