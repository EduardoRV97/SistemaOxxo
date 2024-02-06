#include "Proveedor.h"

void Proveedor::AddProduct(Producto _producto)
{
	m_productos.push_back(_producto);
}

void Proveedor::SetProduct(string _marca)
{
	m_marca = _marca;
}

string Proveedor::GetMarca()
{
	return string(m_marca);
}

Producto Proveedor::GetProducto(int ID)
{
	for (Producto producto : m_productos) {
		if (producto.m_ID == ID) {
			return producto;
		}
	}
	return Producto();
}


