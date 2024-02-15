
#include "Sistema.h"



Sistema::Sistema() {//Al incializar el constructor, se inicializan los metodos que anaden datos iniciales asi como el menu
	inicalizarDatos();
	menu();
}
Sistema::~Sistema()
{

}

void Sistema::mostrarProductos()//Metodo que nos permite ver a todos los objetos de la lista
{
	for (Proveedor proveedor : m_proovedores) {//Un for que recorre toda la lista de objetos existentes
		proveedor.imprimirInv();//Cada valor existente lo manda a un metodo que lo imprime
	}
}

void Sistema::venderProductos()//Metodo que permite la venta de productos, imprimiendo la lista, para que el usuario elija que le gutaria comprar
//Exceptuando los producto con un ID 999 que son los no existentes, y recorriendo la lista para borrar ese objeto
{
	for (Proveedor proveedor : m_proovedores) {//For que recorre toda la lista e imprimirla.
		proveedor.imprimirInv();
	}
	int productoDeseado = 0; //Producto que desea el cliente
	cout << "Que le gustaria comprar? " << endl;
	cin >> productoDeseado;//El usuario un objeto de la lista que se le mostro anteriormente
	for (Proveedor proveedor : m_proovedores) {//Un for que recorre entre todos los proovedores, para darle el valor del producto seleccionado al producto deseado
		Producto productoSeleccionado = proveedor.GetProducto(productoDeseado);//Aqui producto seleccionado se le asigna un valor como producto deseadpo

		if (productoSeleccionado.m_ID != 999) {//Si el ID del producto deseado es diferente a 999, entonce se eliminara
			proveedor.eliminarProductos(productoDeseado);

			for (int i = 0; i < m_proovedores.size(); i++) {//Un for que recorre el tama�o de la lista de proveedores, para obtener la lista actualizada con el objeto borrado
				if (proveedor.GetMarca() == m_proovedores[i].GetMarca()) {//Aqui se recorre las marcas
					m_proovedores.erase(m_proovedores.begin() + i);//En caso de que la encuentre la pondre un lugar adelante

					m_proovedores.push_back(proveedor);//Nos regresa la lista
				}
			}
			break;
		}
	}
}


void Sistema::registrarProductos()//Metodo para registrar productos
{	//Variables locales que se utilizaran en la funcion
	string eleccion;
	int ID;
	string nombre;
	float peso;
	cout << "Seleccione al provedor donde le gustaria anadir un producto" << endl;
	//Un for que recorra la lista de proovedores, que ayudara a identificar donde se incluira el producto
	for (Proveedor proveedor : m_proovedores) {
		cout << "------------" << proveedor.GetMarca() << "---------------" << endl;
	};
	cin >> eleccion;
	cin.ignore();
	//Unfor que recorre la lista de productos a partir de la marca seleccionada y permite ingresar los valores del nuevo producto
	for (Proveedor proveedor : m_proovedores) {
		if (eleccion == proveedor.GetMarca()) {
			cout << "Ingrese un ID del producto que desee a�adir: " << endl;
			cin >> ID;
			cout << "Ingrese el nombre del producto que desee a�adir: " << endl;
			cin >> nombre;
			cin.ignore();
			cout << "Ingrese el peso del producto que desee a�adir: " << endl;
			cin >> peso;
			m_proovedores[1].AddProduct(Producto(ID, nombre, peso));//Metodo que a�ade un producto a la lista.
			cout << "------Producto registrado exitosamente---------" << endl;
		}
	}
}

void Sistema::registrarClientes()//Metodo que permite registrar cliente, dandote una lista donde poder verlos y poder ingresar sus datos	
{	//Variables locales que se utilizaran en el metodo
	string nombre;
	int puntos;
	double telefono;
	string correo;
	cout << "Los clientes registrado actualmente son: " << endl;
	//Un for que recorre la lista m_clientes, para mostrarte todos los clientes y su informacion registrada
	for (Cliente cliente : m_clientes) {
			cout << "---Nombre del cliente: " << cliente.m_nombre << endl
				<< "---Puntos en el sistema: " << cliente.m_puntos << endl
				<< "---Numero de telefono: " << cliente.m_telefono << endl
				<< "---Correo electronico: " << cliente.m_correo << endl;
		};
	//Un for que recorre la lista de m_clientes, y permite al usuario anadir sus datos.
	//for (Cliente cliente : m_clientes) {
		cout << "Ingrese un ID del producto que desee a�adir: " << endl;
		cin >> nombre;
		cin.ignore();
		cout << "Ingrese el nombre del producto que desee a�adir: " << endl;
		cin >> puntos;
		cout << "Ingrese el peso del producto que desee a�adir: " << endl;
		cin >> telefono;
		cout << "Ingrese el peso del producto que desee a�adir: " << endl;
		cin >> correo;
		cin.ignore();
		Cliente cliente(nombre, puntos, telefono, correo);//Se crea un objeto, al cual se le incluiran los datos que se llenaron previamente.
		m_clientes.push_back(cliente);

		cout << "------Producto registrado exitosamente---------" << endl;

	//}
}

void Sistema::registroProvedores()
{
	string marca;
	cout << "En un momento se le mostraran las marcas registradas actualmente" << endl;
	int a;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 33) {//Al llegar al 50%, se muestra un mensaje y el programa espera 4 segundos para continuar
			cout << " Fallo al mostrar, haciendo el codigo de nuevo" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}
		if (i == 99) {//Al llegar al 99%, se muestra  un mensaje y el programa espera 6 segundos para continuar
			cout << " Fallo fatal, se saldra del programa. A menos que nuestro completamente capacitados desarrolladores lo arreglen repido" << endl;
			this_thread::sleep_for(chrono::seconds(3));
			cout << "ARREGLADO, deberian subirles el sueldo" << endl;
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(20)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
	for (Proveedor proveedor : m_proovedores) {
		cout << "------------" << proveedor.GetMarca() << "---------------" << endl;
	};
	cout << "Cual es el nombre de la marca que desea incluir al sistema?" << endl;
	cin >> marca;
	Proveedor nuevo(marca);
	m_proovedores.push_back(nuevo);
	cout << "Se le mostrara la lista actual de proveedores" << endl;
	for (Proveedor proveedor : m_proovedores) {
		cout << "------------" << proveedor.GetMarca() << "---------------" << endl;
	};
}

/*void Sistema::borrarClientes()
{
}*/

/*void Sistema::errorSistema()
{
}*/

/*void Sistema::caerSistema()
{
}*/

/*void Sistema::eventoAleatorio()
{
}*/

void Sistema::inicalizarDatos()//Metodo que esta ligado al constructor para inicializar los datos
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
	Cliente pepe("Pepe", 45, 4423457854, "outlook");
	m_clientes.push_back(juan);
	m_clientes.push_back(pepe);
}

void Sistema::menu()//Metodo que ingresa a un menu, al iniciar el programa
{
	int a;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 50) {//Al llegar al 50%, se muestra un mensaje y el programa espera 4 segundos para continuar
			cout << " Hemos encontrado un error, se ha enviado un reporte automaticamente al tecnico Tela Reglo" << endl;
			this_thread::sleep_for(chrono::seconds(4));
		}
		if (i == 99) {//Al llegar al 99%, se muestra  un mensaje y el programa espera 6 segundos para continuar
			cout << " Acomodando todos lo inventarios mal ingresados, espere un momento..." << endl;
			this_thread::sleep_for(chrono::seconds(6));
		}
		for (int j = 0; j < i; ++j) {//Un for para anadir puntos despues de cada porcentaje
			cout << ".";
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(50)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
	//Do-while que ingresa al menu
	do {
		cout << "Bienvenido al Sistema del OXXO" << std::endl;
		cout << "~Nota del desarrollador, es un sistema del oxxo y no me han pagado bien, por lo tanto ira lento. Gracias por su compresion empleados del Oxxo" << endl;
		cout << "Que le gustaria hacer?" << endl
			<< "1.----------Mostrar el inventario actual" << endl
			<< "2.----------Comprar un producto" << endl
			<< "3.----------A�adir al inventario un producto" << endl
			<< "4.----------A�adir cliente al sistema" << endl;
		cin >> a;

		switch (a)
		{
		case 1:
			mostrarProductos();//En caso de presionar 1, lleva al metodo MostrarProductos
			break;
		case 2:
			venderProductos();//En caso de presionar 2, lleva al metodo venderProductos
			break;
		case 3:
			registrarProductos();//En caso de presionar 3, lleva al metodo registrarProductos
			break;
		case 4:
			registrarClientes();//En caso de presionar 4, lleva al metodo registrarClientes
			break;
		case 5:
			registroProvedores();//En caso de presionar 5, lleva al metodo registro deProvedores
			break;
		default:
			cout << "Has seleccionado salir, se le sacara del programa y se borrara todo el inventario" << endl;

		}
	} while (a >= 1 && a <= 6);//Cualquier numero incorrecto los sacara del programa
	}

/*void Sistema::AddCliente(Cliente _clientes)
{
	m_clientes.push_back(_clientes); //Metodo para asignar valores a m_clientes
}*/
