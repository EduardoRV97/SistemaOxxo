#include "Cliente.h"

void Cliente::setCliente(string nombre, int puntos, double telefono, string correo)
{
	m_nombre = nombre;
	m_puntos = puntos;
	m_telefono = telefono;
	m_correo = correo;
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




