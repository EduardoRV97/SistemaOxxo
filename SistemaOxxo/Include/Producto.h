#pragma once
#include "Prerequisitosh.h"

class Producto{

public:
	Producto() {}
	Producto(string _nombre, float _peso) : m_nombre(_nombre), m_peso(_peso) {}
	~Producto() {}
protected:
	string m_nombre;
	float m_peso;
public:
	int m_ID;
};

class Papas : public Producto{
public: 
	Papas(string _nombre, float _peso) : Producto(_nombre, _peso){}
	~Papas() {}
public: 
	void Proporcionar();
};