#include "ListaVentas.h"
#include "Manejo_Archivos.h"
#include <iostream>
#include <limits>

using namespace std;

ListaVentas::ListaVentas() {
    ventas = ManejadorArchivos::cargarVentas();
    ultimoID = ManejadorArchivos::cargarUltimoIDVenta();
}

void ListaVentas::crearVenta(Inventario& inventario, ListaMediosPago& listaMediosPago) {
    cout << "\n--- NUEVA VENTA ---\n";

    Venta nuevaVenta;
    int opcion;

    do {
        cout << "\n1. Agregar producto\n";
        cout << "2. Finalizar venta\n";
        cout << "0. Cancelar venta\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                system("cls");
                // Mostrar productos activos
                cout << "\n--- PRODUCTOS DISPONIBLES ---\n";
                const auto& productos = inventario.getProductos();
                int contador = 0;
                for (const auto& producto : productos) {
                    if (producto.getActivo() && producto.getStock() > 0) {
                        producto.mostrarInfo();
                        contador++;
                    }
                }

                if (contador == 0) {
                    cout << "No hay productos disponibles para vender.\n";
                    break;
                }

                // Seleccionar producto
                int idProducto, cantidad;
                cout << "Ingrese ID del producto: ";
                cin >> idProducto;

                Producto* producto = inventario.buscarProducto(idProducto);
                if (!producto || !producto->getActivo()) {
                    cout << "Error: Producto no encontrado o inactivo.\n";
                    break;
                }

                cout << "Ingrese cantidad: ";
                cin >> cantidad;

                if (cantidad <= 0) {
                    cout << "Error: Cantidad debe ser mayor a 0.\n";
                    break;
                }

                if (cantidad > producto->getStock()) {
                    cout << "Error: Stock insuficiente. Stock disponible: " << producto->getStock() << "\n";
                    break;
                }

                // Crear item de venta
                ItemVenta item(producto->getIdProducto(), producto->getNombre(), cantidad, producto->getPrecio());
                nuevaVenta.agregarItem(item);

                cout << "Producto agregado a la venta.\n";
                system("pause");
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                if (nuevaVenta.getItems().empty()) {
                    cout << "Error: No hay productos en la venta.\n";
                    system("cls");
                    break;
                }

                // Seleccionar medio de pago
                cout << "\n--- MEDIOS DE PAGO DISPONIBLES ---\n";
                listaMediosPago.mostrarMediosPagoActivos();

                int idMedioPago;
                cout << "Ingrese ID del medio de pago: ";
                cin >> idMedioPago;

                 MedioPago* medio = listaMediosPago.buscarMedioPagoActivo(idMedioPago);
                        if (!medio) {
                            cout << "Error: Medio de pago no encontrado o inactivo.\n";
                            break;
                        }

                // Configurar medio de pago
                nuevaVenta.setMedioPago(medio->getIdMedioPago(), medio->getNombre(), medio->getAjuste());

                // Generar ID y guardar
                int nuevoID = generarNuevoID();
                nuevaVenta.setIdVenta(nuevoID);

                // Descontar stock
                if (descontarStock(inventario, nuevaVenta)) {
                    ventas.push_back(nuevaVenta);
                    ManejadorArchivos::guardarVentas(ventas);
                    cout << "\n=== VENTA FINALIZADA ===\n";
                    nuevaVenta.mostrarVenta();
                    cout << "ID de venta: " << nuevoID << "\n";
                } else {
                    cout << "Error al procesar la venta.\n";
                }
            }

            case 0:
                cout << "Venta cancelada.\n";
                system("cls");
                return;

            default:
                cout << "Opcion no valida.\n";
        } system("cls");
    } while(true);
}

bool ListaVentas::descontarStock(Inventario& inventario, const Venta& venta) {
    for (const auto& item : venta.getItems()) {
        Producto* producto = inventario.buscarProducto(item.getIdProducto());
        if (!producto) {
            cout << "Error: Producto no encontrado durante el descuento de stock.\n";
            return false;
        }

        if (producto->getStock() < item.getCantidad()) {
            cout << "Error: Stock insuficiente para " << producto->getNombre() << "\n";
            return false;
        }

        producto->quitarStock(item.getCantidad());
    }
    ManejadorArchivos::guardarProductos(inventario.getProductos());
    return true;
}

void ListaVentas::restaurarStock(Inventario& inventario, const Venta& venta) {
    for (const auto& item : venta.getItems()) {
        Producto* producto = inventario.buscarProducto(item.getIdProducto());
        if (producto) {
            producto->agregarStock(item.getCantidad());
        }
    }
    ManejadorArchivos::guardarProductos(inventario.getProductos());
}

void ListaVentas::anularVenta(int idVenta) {
    Venta* venta = buscarVenta(idVenta);
    if (venta && venta->getActivo()) {
        venta->setActivo(false);
        ManejadorArchivos::guardarVentas(ventas);
        cout << "Venta anulada exitosamente.\n";
    } else {
        cout << "Error: Venta no encontrada o ya anulada.\n";
    }
}

void ListaVentas::mostrarVentas() const {
    cout << "=== TODAS LAS VENTAS ===\n";
    if (ventas.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    for (const auto& venta : ventas) {
        venta.mostrarVenta();
        cout << "------------------------\n";
    }
    cout << "Total ventas: " << ventas.size() << "\n";
}

void ListaVentas::mostrarVentasActivas() const {
    cout << "=== VENTAS ACTIVAS ===\n";
    int contador = 0;
    for (const auto& venta : ventas) {
        if (venta.getActivo()) {
            venta.mostrarVenta();
            cout << "------------------------\n";
            contador++;
        }
    }
    cout << "Total ventas activas: " << contador << "\n";
}

Venta* ListaVentas::buscarVenta(int id) {
    for (auto& venta : ventas) {
        if (venta.getIdVenta() == id) {
            return &venta;
        }
        system("pause");
    system("cls");
    }
    return nullptr;
}

const std::vector<Venta>& ListaVentas::getVentas() const {
    return ventas;
}

int ListaVentas::generarNuevoID() {
    ultimoID++;
    ManejadorArchivos::guardarUltimoIDVenta(ultimoID);
    return ultimoID;
}
