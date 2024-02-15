//Clase Sistema, sera la que tenga todos los metodos necesarios para el menu
#pragma once
#include "Prerequisitosh.h"
#include "Cliente.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Papas.h"
#include "Bebidas.h"

class Sistema {
public:
	Sistema();
	~Sistema();
private:
	vector<Proveedor> m_proovedores;
	vector<Cliente> m_clientes;
private:
	void mostrarProductos(); //Metodo que sirve para mostrar productos
	void venderProductos(); //Metodo para vender productos al cliente
	void registrarProductos(); //Metodo para registrar nuevos productos al sistema
	void registrarClientes(); //Metodo para registrar nuevos clientes al sistema
	void registroProvedores(); //Metodo para registrar nuevos provedores
	void borrarClientes(); //Metodo para borrar clientes
	void errorSistema(); //Metodo para que se genere un error de vez en cuando
	void caerSistema(); //Metodo para una salida forzada del sistema
	void eventoAleatorio(); //Metodo para eventos aleatorios
	void inicalizarDatos(); //Metodo que sirve para inicializar los datos
	void menu(); //Metodo para crear un menu del sistema
	void AddCliente(Cliente _clientes);
};