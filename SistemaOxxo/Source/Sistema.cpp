
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
			break;
		}
	}
}
/*void Sistema::eliminarProducto(vector<Producto>& _productos, Producto _producto)
{
	for (int i = 0; i < _productos.size(); i++) {
		if (_producto.m_ID == _productos[i].m_ID) {
			_productos.erase(_productos.begin() + i);
		}
	};
}*/


void Sistema::registrarProductos()
{
}

void Sistema::registrarClientes()
{
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
	Proveedor pepsico("Papas");
	Proveedor cocacolafemsa("Refrescos");
	cocacolafemsa.AddProduct(Bebidas(11, "Coca Cola", 600));
	cocacolafemsa.AddProduct(Bebidas(12, "Coca Cola Light", 600));
	cocacolafemsa.AddProduct(Bebidas(13, "Sidral Mundet", 600));
	cocacolafemsa.AddProduct(Bebidas(14, "Victoria Manzana", 600));
	cocacolafemsa.AddProduct(Bebidas(15, "Delaware", 600));
	cocacolafemsa.AddProduct(Bebidas(16, "Fanta", 600));
	cocacolafemsa.AddProduct(Bebidas(17, "7up", 600));
	cocacolafemsa.AddProduct(Bebidas(18, "pepsi", 600));
	cocacolafemsa.AddProduct(Bebidas(19, "Coca Cola", 600));
	pepsico.AddProduct(Papas(20, "Doritos", 58.0f));
	pepsico.AddProduct(Papas(21, "Sabritas", 45.0f));
	pepsico.AddProduct(Papas(22, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(23, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(24, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(25, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(26, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(27, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(28, "Cheetos Torciditos", 145.0f));
	pepsico.AddProduct(Papas(29, "Cheetos Torciditos", 145.0f));
	m_proovedores.push_back(cocacolafemsa);
	m_proovedores.push_back(pepsico);
}

void Sistema::menu()
{
	int a;
	do {
		cout << "Ingresando al sistema oxxo, espere un momento" << endl
			<< "Que le gustaria hacer?" << endl;
		cout << "1.- Mostrar la lista de productos" << endl
			<< "2.-Vender un producto" << endl;
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
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			cout << "Escoje un opcion valida" << endl;
		}

	} while (a >= 1 && a<=6);
}
