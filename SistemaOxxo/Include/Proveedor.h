//Clase Proovedor, donde daremos un razgo de marca y ingresaremos lo valores con ID
#pragma once
#include "Prerequisitosh.h"
#include "Producto.h"

class Proveedor {

public:
	Proveedor(string _marca) : m_marca(_marca) {} //Constructor de tu prooveedor

public:
	void AddProduct(Producto _producto);  //Metodo para asignar valores al vector Producto
	void SetMarca(string _marca); //Metodo para asignar una Marca
	void imprimirInv();//Metodo que imprime los datos de los productos
	vector < Producto>& GetProducts();//Metodo que regresa la lista de productos
	void eliminarProductos(int m_ID);

	string GetMarca(); //Metodo para obtener Marca
	Producto GetProducto(int _ID); //Metodo para obtener producto mediante ID

private:  //Variables de nuestra clase Proovedor
	string m_marca;
	vector<Producto> m_productos;
};