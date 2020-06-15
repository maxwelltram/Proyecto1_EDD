#pragma once
#include <iostream>
class Nodo
{
public:
	//PUNTEROS PARA  EJE Y 
	Nodo* Siguiente;
	Nodo* Anterior;
	
	//PUNTEROS PARA EJE X
	Nodo* Adelante;
	Nodo* Atras;

	//PUNTEROS PARA EJE Z
	Nodo* Arriba; 
	Nodo* Abajo;

	std::string Nombre;
	std::string Contra;
	std::string NomCom;


	Nodo(std::string dato1, std::string dato2, std::string dato3)
	{
		Siguiente = nullptr;
		Anterior = nullptr;

		Adelante = nullptr;
		Atras = nullptr;

		Arriba = nullptr;
		Abajo = nullptr;

		Nombre = dato1;
		Contra = dato2;
		NomCom = dato3;
	}
};

