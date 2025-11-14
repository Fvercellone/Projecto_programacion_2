#include "ListaVentas.h"
#include "Manejo_Archivos.h"  // ← Asegurar que este include existe
#include "Factura.h"
#include <iostream>
#include <limits>

using namespace std;

ListaVentas::ListaVentas() {
    // Constructor vacío - no necesitamos inicializar nada
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
                system("pause");
                system("cls");
                    break;
                }

                // Seleccionar producto
                int idProducto, cantidad;
                cout << "Ingrese ID del producto: ";
                cin >> idProducto;

                Producto* producto = inventario.buscarProducto(idProducto);
                if (!producto || !producto->getActivo()) {
                    cout << "Error: Producto no encontrado o inactivo.\n";
                system("pause");                system("cls");
                    break;
                }

                cout << "Ingrese cantidad: ";
                cin >> cantidad;

                if (cantidad <= 0) {
                    cout << "Error: Cantidad debe ser mayor a 0.\n";
                    system("pause");
                system("cls");
                    break;
                }

                if (cantidad > producto->getStock()) {
                    cout << "Error: Stock insuficiente. Stock disponible: " << producto->getStock() << "\n";
                    system("pause");
                system("cls");
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
                if (nuevaVenta.getItems().empty()) {
                    cout << "Error: No hay productos en la venta.\n";
                    system("pause");
                system("cls");
                    break;
                }

                // Seleccionar medio de pago
                cout << "\n--- MEDIOS DE PAGO DISPONIBLES ---\n";
                listaMediosPago.mostrarMediosPagoActivos();

                int idMedioPago;
                cout << "Ingrese ID del medio de pago: ";
                cin >> idMedioPago;

                MedioPago* medio = listaMediosPago.buscarMedioPago(idMedioPago);
                if (!medio || !medio->getActivo()) {
                    cout << "Error: Medio de pago no encontrado o inactivo.\n";
                    system("pause");
                system("cls");
                    break;
                }

                // Configurar medio de pago
                nuevaVenta.setMedioPago(medio->getIdMedioPago(), medio->getNombre(), medio->getAjuste());

                // Descontar stock
                if (descontarStock(inventario, nuevaVenta)) {
                    // ========== FACTURA AUTOMÁTICA ==========
                    // Cargar facturas existentes
                    std::vector<Factura> facturas = ManejadorArchivos::cargarFacturas();
                    int ultimoIDFactura = ManejadorArchivos::cargarUltimoIDFactura();
                    int nuevoIDFactura = ultimoIDFactura + 1;

                    // Crear nueva factura
                    Factura facturaAutomatica;
                    facturaAutomatica.generarDesdeVenta(nuevaVenta);
                    facturaAutomatica.setIdFactura(nuevoIDFactura);

                    // Datos del cliente
                    string nombre, ruc;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "\n--- DATOS PARA FACTURA ---\n";
                    cout << "Nombre del cliente (Enter para CONSUMIDOR FINAL): ";
                    getline(cin, nombre);
                    if (nombre.empty()) nombre = "CONSUMIDOR FINAL";

                    cout << "Ingrese su DNI (Enter para 9999999999999): ";
                    getline(cin, ruc);
                    if (ruc.empty()) ruc = "9999999999999";

                    facturaAutomatica.setCliente(nombre, ruc, "NO ESPECIFICADA");

                    // Guardar SOLO la factura
                    facturas.push_back(facturaAutomatica);
                    ManejadorArchivos::guardarFacturas(facturas);
                    ManejadorArchivos::guardarUltimoIDFactura(nuevoIDFactura);

                    // Mostrar factura generada
                    cout << "\n=== FACTURA GENERADA ===\n";
                    facturaAutomatica.mostrarFacturaCompleta();
                    cout << "ID de factura: " << nuevoIDFactura << "\n";
                    // ========== FIN FACTURA AUTOMÁTICA ==========
                } else {
                    cout << "Error al procesar la venta.\n";
                    system("pause");
                system("cls");
                }
                return;
            }

            case 0:
                cout << "Venta cancelada.\n";
                system("pause");
                system("cls");
                return;

            default:
                cout << "Opcion no valida.\n";
                system("pause");
                system("cls");
        }
    } while(true);
}

bool ListaVentas::descontarStock(Inventario& inventario, const Venta& venta) {
    for (const auto& item : venta.getItems()) {
        Producto* producto = inventario.buscarProducto(item.getIdProducto());
        if (!producto) {
            cout << "Error: Producto no encontrado durante el descuento de stock.\n";
            system("pause");
                system("cls");
            return false;
        }

        if (producto->getStock() < item.getCantidad()) {
            cout << "Error: Stock insuficiente para " << producto->getNombre() << "\n";
            system("pause");
                system("cls");
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
