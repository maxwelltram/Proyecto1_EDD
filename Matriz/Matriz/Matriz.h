#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

class Matriz
{
public:
	Nodo* Cabecera;

	Matriz() 
	{
		Cabecera = new Nodo("admin", "admin","admin");
	}

	void InsertarElemento(string usuario,string contrasenia, string nombreComple, string empresa, string departamento);

	//INICIA CREANDO CABECERAS
	Nodo* CrearEmpresa(string departa);
	Nodo* CrearDepartamento(string empre);
	//TERMINA CREANDO CABECERAS

	//INICIA SI EXISTEN LAS CABECERAS
	Nodo* BuscarEmpresa(string empre, Nodo* inicio);
	Nodo* BuscarDepartamento(string depa, Nodo* inicio);
	//TERMINA SI EXISTEN LAS CABECERAS


	//VERIFICAR SI SON LOS MISMOS
	bool VerificarDepartamento(string depa,Nodo* inicio,Nodo* User);
	bool VerificarEmpresa(string empre,Nodo* inicio,Nodo* User);
	//VERIFICAR SI SON LOS MISMOS


	bool VerificarEmpresita(string empresa, Nodo* inicio);
	bool VerificarCreaciónUsuario(string empre, string user, string departamento);
	bool AccesoUsuario(string usuario, string contrasenia);
};

