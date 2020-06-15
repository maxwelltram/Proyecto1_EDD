#pragma once
#include <iostream>

using namespace std;
class NodoC
{
public:
	NodoC* Siguiente;
	NodoC* Anterior;

	NodoC* Primero=nullptr;
	NodoC* Ultimo=nullptr;

	string idtransaccion;
	string idactivo;
	string usuario;
	string empresa;
	string departamento;
	string fecha;

	NodoC() {

	}
	NodoC(string Idtransaccion, string Idactivo, string Usuario, string Empresa, string Departamento, string Fecha) {
		Siguiente = nullptr;
		Anterior = nullptr;

		idtransaccion = Idtransaccion;
		idactivo = Idactivo;
		usuario = Usuario;
		empresa = Empresa;
		departamento = Departamento;
		fecha = Fecha;
	}


	void InsertarElemento(string idTransaccion, string idActivo, string usuario, string departamento, string empresa, string fecha);

	void Mostrar();
};

