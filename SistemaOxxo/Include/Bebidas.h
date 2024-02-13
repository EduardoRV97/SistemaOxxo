//Clase derivada llamada Bebida, de la clase padre Producto
#pragma once
#include "Producto.h"

class Bebidas : public Producto {
public:
	Bebidas(int _ID, string _nombre, float _peso) : Producto(_ID, _nombre, _peso){} //Constructor
	~Bebidas() {} //Destructor
public:
	void Proporcionar(); //Inicializacion del metodo Proporcionar
};
