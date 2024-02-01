#pragma once
#include "Prerequisitosh.h"

class Cliente{
	
public:
	Cliente(string _nombre, int _puntos, double _telefono, string _correo) :
		m_nombre(_nombre), m_puntos(_puntos), m_telefono(_telefono), m_correo(_correo) {}
	~Cliente() {}

	void setCliente(string nombre, int puntos, double telefono, string correo);

	string getNombre();
	int getPuntos();
	double getTelefono();
	string getCorreo();

private:
	string m_nombre;
	int m_puntos;
	double m_telefono;
	string m_correo;
};