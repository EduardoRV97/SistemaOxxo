//Codigo fuente de la clase Cliente, donde incluiremos nuestros metodos para asignar y obtener valores.
#include "Cliente.h"

void Cliente::setCliente(string _nombre, int _puntos, double _telefono, string _correo)
{
	m_nombre = _nombre;
	m_puntos = _puntos;
	m_telefono = _telefono;
	m_correo = _correo;
}

string Cliente::getNombre()
{
	return m_nombre;
}

int Cliente::getPuntos()
{
	return m_puntos;
}

double Cliente::getTelefono()
{
	return m_telefono;
}

string Cliente::getCorreo()
{
	return m_correo;
}



