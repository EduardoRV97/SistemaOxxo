//Clase Cliente, en el cual ingresaremos los valores de nombre, puntos, telefono y correo
#pragma once
#include "Prerequisitosh.h"

class Cliente{
//Datos publicos
public:
	//Constructor de las variables con inicializacion
	Cliente(string _nombre, int _puntos, double _telefono, string _correo) :
	m_nombre(_nombre), m_puntos(_puntos), m_telefono(_telefono), m_correo(_correo) {}
	~Cliente() {} //Destructor

	//Metodos de la Clase Cliente
	void setCliente(string _nombre, int _puntos, double _telefono, string _correo);
	string getNombre();
	int getPuntos();
	double getTelefono();
	string getCorreo();
//Datos privados del Cliente (Nombre, Puntos, Telefono y Correo)
public:
	string m_nombre;
	int m_puntos;
	double m_telefono;
	string m_correo;
};