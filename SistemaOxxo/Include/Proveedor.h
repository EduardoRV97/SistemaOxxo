#pragma once
#include "Prerequisitosh.h"

class Proveedor {

public:
	Proveedor(string _marca, string _productos) {}
	~Proveedor() {}

	void AddProduct(string _producto); 

private:
	string m_marca;
	vector<string> m_productos;
};