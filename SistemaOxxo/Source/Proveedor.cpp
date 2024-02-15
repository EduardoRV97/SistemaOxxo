//Codigo fuente de la clase Proovedor, donde se crearan los metodos para obtener y asignar valores
#include "Proveedor.h"

void Proveedor::AddProduct(Producto _producto)
{
	m_productos.push_back(_producto); //Metodo para asignar valores a m_producto
}

void Proveedor::SetMarca(string _marca)
{
	m_marca = _marca; //Metodo para asignar valores a marca
}

void Proveedor::imprimirInv()
{
	for (Producto producto : m_productos) {
		cout << "ID: " << producto.m_ID << " Nombre: " << producto.m_nombre << " Peso: " << producto.m_peso << "gr" << endl;
	}
}

vector<Producto>& Proveedor::GetProducts()
{
	return m_productos;
}

void Proveedor::eliminarProductos(int m_ID)
{
	for (int i = 0; i < m_productos.size(); i++)
	{
		if (m_ID == m_productos[i].m_ID) {
			cout << i << endl;
			m_productos.erase(m_productos.begin() + i);
		}
	};
}

string Proveedor::GetMarca()
{
	return m_marca;  //Metodo para obtener marca
}

Producto Proveedor::GetProducto(int _ID) //Metodo para obtener un producto medinte ID
{
	for (Producto producto : m_productos) {//El ciclo termina al acabar los valores que tenga el vector m_productos
		if (producto.m_ID == _ID) { //Si el ID de producto es igual al ID solicitado, entonces te regresa un producto
			return producto;
		}
	}return Producto(999, "none", 0); //Al terminar el ciclo, te regresa a Producto
}


