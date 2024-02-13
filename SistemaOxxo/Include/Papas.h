//Clase derivada llamada Papas, de la clase padre Producto
#pragma once
#include "Producto.h"


class Papas : public Producto {
public:
	Papas(int _ID, string _nombre, float _peso) : Producto(_ID, _nombre, _peso) {} //Constructor
	~Papas() {} //Destructor
public:
	void Proporcionar(); //Inicializacion del Metodo Proporcionar
};