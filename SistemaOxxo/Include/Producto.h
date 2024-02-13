//Clase Producto, aqui crearemos la clase Padre que contendra los rasgos basicos de los alimentos
#pragma once
#include "Prerequisitosh.h"

class Producto{

public:
	Producto(){}
	Producto(int _ID, string _nombre, float _peso) : m_ID(_ID), m_nombre(_nombre), m_peso(_peso) {}
	~Producto() {}
public:
	string m_nombre;//Nombre del Producto
	float m_peso;//Peso del producto
public:
	int m_ID; //ID unico por objeto
public:
	void setProducto(int _ID, string _nombre, float _peso);//Asignacion de valores
private://Metodos para obetner los valores
	int getID();
	string getNombre();
	float getPeso();
};

