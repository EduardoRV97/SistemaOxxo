//Codigo fuente de la clase Producto, donde se crearan los metodos para obtener y asignar valores
#include "Producto.h"

void Producto::setProducto(int _ID, string _nombre, float _peso) //Con este metodo se asignan los valores a 
{
	m_ID = _ID;
	m_nombre = _nombre;
	m_peso = _peso;
}

int Producto::getID() //Obtener el ID del producto
{
	return m_ID;
}

string Producto::getNombre() //Obtener el nombre del producto
{
	return m_nombre;
}

float Producto::getPeso() //Obtener el Peso de producto
{
	return m_peso;
}
