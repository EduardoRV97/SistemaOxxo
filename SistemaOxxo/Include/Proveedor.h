#pragma once
#include "Prerequisitosh.h"
#include "Producto.h"

class Proveedor {

public:
	Proveedor(string _marca, Producto _productos) {}
	~Proveedor() {}

	void AddProduct(Producto _producto); 
	void SetProduct(string _marca);

	string GetMarca();
	Producto GetProducto(int ID);

private:
	string m_marca;
	vector<Producto> m_productos;
};