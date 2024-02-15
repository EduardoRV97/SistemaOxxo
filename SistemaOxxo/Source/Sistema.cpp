
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
	cout << "Espere un momento en lo que carga la GRAN cantidad, GRAN variedad y GRAN calidad de los productos que vendemos en OXO" << endl;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 95) {//Al llegar al 97%, se muestra un mensaje y el programa espera 2 segundos para continuar
			cout << " Si se pregunta porque tarda mas en ver los productos que en venderlos, es porque aqui aplicamos matematicas avanzadas para muestra de valores finitos" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}
		if (i == 98) {//Al llegar al 99%, se muestra  un mensaje y el programa espera 3 segundos para continuar
			cout << " Alguna vez a calculado cuantos metros son de aqui al sol?, ese es el tamano de nuestras ecuaciones para procesar la GRAN cantidad de datos que tenemos" << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(30)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
	cout << "Inventario actual:       " << endl;
	for (Proveedor proveedor : m_proovedores) {//Un for que recorre toda la lista de objetos existentes
		proveedor.imprimirInv();//Cada valor existente lo manda a un metodo que lo imprime
	}
}

void Sistema::venderProductos()//Metodo que permite la venta de productos, imprimiendo la lista, para que el usuario elija que le gutaria comprar
//Exceptuando los producto con un ID 999 que son los no existentes, y recorriendo la lista para borrar ese objeto
{cout << " Espere un momento en lo que carga el sistema de venta" << endl;
for (int i = 0; i <= 100; i+=2) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
	cout << "Cargando " << i << "%";
	if (i == 60) {//Al llegar al 97%, se muestra un mensaje y el programa espera 6 segundos para continuar
		cout << " Al parecer se ha detectado un fallo que podria eliminar todo el sistema" << endl;
		this_thread::sleep_for(chrono::seconds(6));
		cout << " Al parecer no era nada, solo se me olvido poner un ;" << endl;
	}
	if (i == 98) {//Al llegar al 99%, se muestra  un mensaje y el programa espera 3 segundos para continuar
		cout << " Esta opcion carga mas rapido, para que el cliente no ponga mas quejas y tenga que trabajar mas" << endl;
		this_thread::sleep_for(chrono::seconds(3));
	}
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(10)); // Velocidad de la impresion, marcada en 50 milisegundos
}
cout << "Inventario actual:       " << endl;
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

			for (int i = 0; i < m_proovedores.size(); i++) {//Un for que recorre el tamaño de la lista de proveedores, para obtener la lista actualizada con el objeto borrado
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
	cout << " Espere un momento en lo que carga el sistema" << endl;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 97) {//Al llegar al 97%, se muestra un mensaje y el programa espera 2 segundos para continuar
			cout << " SI SE ATORO EN 97 ES PORQUE EL DESARROLLADOR NO HA COMIDA EN EL DIA" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}
		if (i == 99) {//Al llegar al 99%, se muestra  un mensaje y el programa espera 3 segundos para continuar
			cout << " YA COMI, PERO SIGO EN HUELGA. LOS ERRORES SEGUIRAN HASTA QUE ME AUMENTEN EL SUELDO" << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(25)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
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
			cout << "Ingrese un ID del producto que desee añadir: " << endl;
			cin >> ID;
			cout << "Ingrese el nombre del producto que desee añadir: " << endl;
			cin >> nombre;
			cin.ignore();
			cout << "Ingrese el peso del producto que desee añadir: " << endl;
			cin >> peso;
			m_proovedores[1].AddProduct(Producto(ID, nombre, peso));//Metodo que añade un producto a la lista.
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
	cout << "Un momento en lo que se cargan los datos" << endl;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 10) {//Al llegar al 10%, se muestra un mensaje y el programa espera 2 segundos para continuar
			cout << " Cargando las quejas de los clientes" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}
		if (i == 80) {//Al llegar al 80%, se muestra  un mensaje y el programa espera 3 segundos para continuar
			cout << " Otro cliente se volvio a quejar, eso limita al servidor, ya que primero lo que manda el cliente" << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(25)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
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
		cout << "Ingrese el nombre del usuario que quiere incluir: " << endl;
		cin >> nombre;
		cin.ignore();
		cout << "Ingrese la cantidad de puntos que registra el cliente: " << endl;
		cin >> puntos;
		cout << "Ingrese el numero de telefono del cliente: " << endl;
		cin >> telefono;
		cout << "Ingrese el correo del cliente: " << endl;
		cin >> correo;
		cin.ignore();
		Cliente cliente(nombre, puntos, telefono, correo);//Se crea un objeto, al cual se le incluiran los datos que se llenaron previamente.
		m_clientes.push_back(cliente);

		cout << "------CLiente registrado exitosamente---------" << endl;

	//}
}

void Sistema::registroProvedores()//Metodo que nos permite ingresa un nuevo proovedor al sistema
{
	string marca;
	cout << "En un momento se le mostraran las marcas registradas actualmente" << endl;
	int a;
	for (int i = 0; i <= 100; ++i) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 33) {//Al llegar al 33%, se muestra un mensaje y el programa espera 4 segundos para continuar
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
	Proveedor nuevo(marca);//Crea un nuevo objeto donde se anadira la marca registrada por el usuario
	m_proovedores.push_back(nuevo);//Empuja al vector el nuevo valor de la marca
	cout << "Se le mostrara la lista actual de proveedores" << endl;//Nos vuelve a mostrar la lista de proveedores actualizada
	for (Proveedor proveedor : m_proovedores) {
		cout << "------------" << proveedor.GetMarca() << "---------------" << endl;
	};
}

void Sistema::borrarClientes()//Metodo que eliminara a los clientes seleccionados por su nombre
{
	cout << "Un momento en lo que carga la base de datos de los amados y respetados clientes, nuestros dioses" << endl;
	for (int i = 0; i <= 100; i+=4) {//Un recorrido que muestra un porcentaje de avance con varios "errores" entre ciertos porcentajes
		cout << "Cargando " << i << "%";
		if (i == 40) {//Al llegar al 40%, se muestra un mensaje y el programa espera 2 segundos para continuar
			cout << " Se registrado una persona que tiene un nombre de 10 palabras y crasheo el servidor" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}
		if (i == 80) {//Al llegar al 80%, se muestra  un mensaje y el programa espera 3 segundos para continuar
			cout << " Como es posible que alguien le meta 999999999 puntos al sistema" << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(60)); // Velocidad de la impresion, marcada en 50 milisegundos
	}
	int i = 0;
	string cliente2;
	cout << "Se le mostrara la lista de clientes: " << endl;
	for (Cliente cliente : m_clientes) {//Para mostrar la lista de clientes
		cout << "---Nombre del cliente: " << cliente.m_nombre << endl
			<< "---Puntos en el sistema: " << cliente.m_puntos << endl
			<< "---Numero de telefono: " << cliente.m_telefono << endl
			<< "---Correo electronico: " << cliente.m_correo << endl;
			cout << endl;
	};
	cout << "Que usuario le gustaria eliminar: " << endl;
	cin >> cliente2;
	auto it = m_clientes.begin();//Con la funcion auto, se deduce el tipo de variable el cual es string, y le da esas propiedades, permitiendole comparar el resultado con
	//"it" que apunta a m_nombre, con el valor que ingreso el usuario
	while (it != m_clientes.end()) {//No para hasta que el valor de "it" sea diferente que toda la lista de clientes
		if (cliente2 == it->m_nombre) {//Si cliente 2 en identico a "it" que apunta a m_nombre, entonces lo eliminar
			it = m_clientes.erase(it); // Elimina el valor del vector m_clientes usando a it como indicador y luego le da su valor.
		}
		else {
			++it;//Si no lo encuentra, va al siguiente espacio de la lista
		}
	}
	for (Cliente cliente : m_clientes) {//Para mostrar la lista de clientes
		cout << "---Nombre del cliente: " << cliente.m_nombre << endl
			<< "---Puntos en el sistema: " << cliente.m_puntos << endl
			<< "---Numero de telefono: " << cliente.m_telefono << endl
			<< "---Correo electronico: " << cliente.m_correo << endl;
		cout << endl;
	}
}

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
	Cliente juan("Eduardo", 9999999, 4423456785, "gmail");
	Cliente pepe("JuanaPerezGarciaDelCarmenCruzAguilarBazcaMariaJose", 45, 4423457854, "outlook");
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
			<< "3.----------Añadir al inventario un producto" << endl
			<< "4.----------Añadir cliente al sistema" << endl
			<< "5.----------Añadir proovedores al sistema" << endl
			<< "6.----------Eliminar clientes del sistema" << endl;
			
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
		case 6:
			borrarClientes(); //En caso de presionar 6, lleva al metodo borrarClientes
			break;
		default:
			cout << "Has seleccionado salir, se le sacara del programa y se borrara todo el inventario" << endl;

		}
	} while (a >= 1 && a <= 7);//Cualquier numero incorrecto los sacara del programa
	}

/*void Sistema::AddCliente(Cliente _clientes)
{
	m_clientes.push_back(_clientes); //Metodo para asignar valores a m_clientes
}*/
