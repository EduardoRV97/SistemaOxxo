
#include "Sistema.h"



Sistema::Sistema() {
	inicalizarDatos();
	menu();
}
Sistema::~Sistema()
{

}

void Sistema::mostrarProductos()
{
	for (Proveedor proveedor : m_proovedores) {
		proveedor.imprimirInv();
	}
}

void Sistema::venderProductos()
{
	for (Proveedor proveedor : m_proovedores) {
		proveedor.imprimirInv();
	}
	int productoDeseado = 0;
	cout << "Que le gustaria comprar? " << endl;
	cin >> productoDeseado;
	for (Proveedor proveedor : m_proovedores) {
		Producto productoSeleccionado = proveedor.GetProducto(productoDeseado);

		if (productoSeleccionado.m_ID != 999) {
			proveedor.eliminarProductos(productoDeseado);

			for (int i = 0; i < m_proovedores.size(); i++) {
				if (proveedor.GetMarca() == m_proovedores[i].GetMarca()) {
					m_proovedores.erase(m_proovedores.begin() + i);

					m_proovedores.push_back(proveedor);
				}
			}
			break;
		}
	}
}


void Sistema::registrarProductos()
{
	string eleccion;
	int ID;
	string nombre;
	float peso;
	cout << "Seleccione al provedor donde le gustaria anadir un producto" << endl;
	for (Proveedor proveedor : m_proovedores) {
		cout << "------------" << proveedor.GetMarca() << "---------------" << endl;
	};
	cin >> eleccion;
	cin.ignore();
	for (Proveedor proveedor : m_proovedores) {
		if (eleccion == proveedor.GetMarca()) {
			cout << "Ingrese un ID del producto que desee añadir: " << endl;
			cin >> ID;
			cout << "Ingrese el nombre del producto que desee añadir: " << endl;
			cin >> nombre;
			cin.ignore();
			cout << "Ingrese el peso del producto que desee añadir: " << endl;
			cin >> peso;
			m_proovedores[1].AddProduct(Producto(ID, nombre, peso));
			cout << "------Producto registrado exitosamente---------" << endl;
		}
	}
}

void Sistema::registrarClientes()
{
	string nombre;
	int puntos;
	double telefono;
	string correo;
	cout << "Los clientes registrado actualmente son: " << endl;
	for (Cliente cliente : m_clientes) {
			cout << "---Nombre del cliente: " << cliente.m_nombre << endl
				<< "---Puntos en el sistema: " << cliente.m_puntos << endl
				<< "---Numero de telefono: " << cliente.m_telefono << endl
				<< "---Correo electronico: " << cliente.m_correo << endl;
		};
	for (Cliente cliente : m_clientes) {
		cout << "Ingrese un ID del producto que desee añadir: " << endl;
		cin >> nombre;
		cin.ignore();
		cout << "Ingrese el nombre del producto que desee añadir: " << endl;
		cin >> puntos;
		cout << "Ingrese el peso del producto que desee añadir: " << endl;
		cin >> telefono;
		cout << "Ingrese el peso del producto que desee añadir: " << endl;
		cin >> correo;
		cin.ignore();
		Cliente cliente(nombre, puntos, telefono, correo);
		m_clientes.push_back(cliente);

		cout << "------Producto registrado exitosamente---------" << endl;

	}
}

void Sistema::registroProvedores()
{
}

void Sistema::borrarClientes()
{
}

void Sistema::errorSistema()
{
}

void Sistema::caerSistema()
{
}

void Sistema::eventoAleatorio()
{
}

void Sistema::inicalizarDatos()
{
	Proveedor pepsico("Sabritas");
	Proveedor cocacolafemsa("CocaCola");
	cocacolafemsa.AddProduct(Bebidas(1, "Coca Cola", 600));
	cocacolafemsa.AddProduct(Bebidas(2, "Coca Cola Light", 600));
	cocacolafemsa.AddProduct(Bebidas(3, "Sidral Mundet", 600));
	cocacolafemsa.AddProduct(Bebidas(4, "Victoria Manzana", 600));
	cocacolafemsa.AddProduct(Bebidas(5, "Delaware", 600));
	cocacolafemsa.AddProduct(Bebidas(6, "Fanta", 600));
	cocacolafemsa.AddProduct(Bebidas(7, "7up", 600));
	cocacolafemsa.AddProduct(Bebidas(8, "pepsi", 600));
	cocacolafemsa.AddProduct(Bebidas(9, "Coca Cola", 600));
	pepsico.AddProduct(Papas(10, "Doritos", 58.0f));
	pepsico.AddProduct(Papas(11, "Sabritas", 45.0f));
	pepsico.AddProduct(Papas(12, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(13, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(14, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(15, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(16, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(17, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(18, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(19, "Cheetos Torciditos", 145.0f));
	m_proovedores.push_back(cocacolafemsa);
	m_proovedores.push_back(pepsico);
	Cliente juan("Juan", 23, 4423456785, "gmail");
	m_clientes.push_back(juan);
}

void Sistema::menu()
{
	int a;
	for (int i = 0; i <= 100; ++i) {
		cout << "Cargando " << i << "%";
		if (i == 50) {
			cout << " Hemos encontrado un error, se ha enviado un reporte automaticamente al tecnico Tela Reglo" << endl;
			this_thread::sleep_for(chrono::seconds(4));
		}
		if (i == 99) {
			cout << " Acomodando todos lo inventarios mal ingresados, espere un momento..." << endl;
			this_thread::sleep_for(chrono::seconds(6));
		}
		for (int j = 0; j < i; ++j) {
			cout << ".";
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(50)); // Controla la velocidad de impresión
	}
	do {
		cout << "Bienvenido al Sistema del OXXO" << std::endl;
		cout << "Que le gustaria hacer?" << endl
			<< "1.----------Mostrar el inventario actual" << endl
			<< "2.----------Comprar un producto" << endl
			<< "3.----------Añadir al inventario un producto" << endl
			<< "4.----------Añadir cliente al sistema" << endl;
		cin >> a;

		switch (a)
		{
		case 1:
			mostrarProductos();
			break;
		case 2:
			venderProductos();
			break;
		case 3:
			registrarProductos();
			break;
		case 4:
			registrarClientes();
			break;
		case 5:
			registroProvedores();
			break;
		default:
			cout << "Escoje un opcion valida" << endl;

		}
	} while (a >= 1 && a <= 6);
	}

void Sistema::AddCliente(Cliente _clientes)
{
	m_clientes.push_back(_clientes); //Metodo para asignar valores a m_clientes
}
