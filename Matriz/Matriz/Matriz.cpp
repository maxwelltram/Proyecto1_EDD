#include "Matriz.h"
#include "Nodo.h"


void Matriz::InsertarElemento(string usuario,string contrasenia, string nombreComple, string empresa, string departamento)
{
	Nodo* NodoUser;
	Nodo* NodoDepa;
	Nodo* NodoEmpre;
	NodoUser = new Nodo(usuario, contrasenia, nombreComple);

	NodoDepa = BuscarDepartamento(departamento, Cabecera);
	NodoEmpre = BuscarEmpresa(empresa, Cabecera);
	
	//REVISANDO SI EXISTEN LOS ENCABEZADOS
	if (NodoDepa==nullptr)
	{
		NodoDepa = CrearDepartamento(departamento);
	}
	if (NodoEmpre == nullptr)
	{
		NodoEmpre = CrearEmpresa(empresa);
	}
	//REVISANDO SI EXISTEN LOS ENCABEZADOS TERMINA ACA

	//INSERTANDO EN LOS DEPARTAMENTOS 
		/*INSERTANDO AL INICIO SI ESTA NULL
		LA COLUMNA DEPA*/
	if (NodoDepa->Abajo==nullptr)
	{
		NodoDepa->Abajo = NodoUser;
		NodoUser->Arriba = NodoDepa;
		//INSERTANDO AL FINAL
	}
	else if (NodoEmpre->Abajo  == nullptr)
	{
		Nodo* aux = NodoDepa->Abajo;
		while (aux->Abajo!=nullptr)
		{
			aux = aux->Abajo;
		}
		if (!VerificarEmpresa(empresa, aux, NodoUser))
		{
			aux->Abajo = NodoUser;
			NodoUser->Arriba = aux;
		}
		//INSERTANDO AL MEDIO
	}
	else {
		Nodo* aux = NodoDepa;
		do
		{
			aux = aux->Abajo;
			if (!VerificarEmpresa(empresa, aux, NodoUser))
			{
				Nodo* auxEmpre = aux->Anterior;
				while (auxEmpre->Anterior != nullptr)
				{
					auxEmpre = auxEmpre->Anterior;
				}
				while (auxEmpre->Arriba != nullptr)
				{
					if (auxEmpre->Nombre == empresa)
					{
						NodoUser->Abajo = aux;
						NodoUser->Arriba = aux->Arriba;

						aux->Arriba->Abajo = NodoUser;
						aux->Arriba = NodoUser;
						break;
					}
					auxEmpre = auxEmpre->Arriba;
				}
			}
		} while (aux->Abajo != nullptr && NodoUser->Arriba == nullptr);
		if (NodoUser->Arriba == nullptr && NodoUser->Adelante == nullptr)
		{
			aux->Abajo = NodoUser;
			NodoUser->Arriba = aux;
		}
		
	}

	if (NodoUser->Adelante!= nullptr)
	{
		return;
	}



	//INSERTANDO EN LAS EMPRESAS
		/*INSERTANDO AL INICIO SI ESTA NULL 
		LA FILA EMPRESA*/
	if (NodoEmpre->Siguiente==nullptr)
	{
		NodoEmpre->Siguiente = NodoUser;
		NodoUser->Anterior = NodoEmpre;
	}
	else if (NodoDepa->Siguiente==nullptr)
	{
		Nodo* aux = NodoEmpre->Siguiente;
		while (aux->Siguiente!=nullptr)
		{
			aux = aux->Siguiente;
		}
		if (!VerificarDepartamento(departamento, aux, NodoUser))
		{
			aux->Siguiente = NodoUser;
			NodoUser->Anterior = aux;
		}
		//INSERTANDO AL MEDIO
	}
	else {
		Nodo* aux = NodoEmpre;
		do
		{
			aux = aux->Siguiente;
			if (!VerificarDepartamento(departamento, aux, NodoUser))
			{
				Nodo* auxDepa = aux->Arriba;
				while (auxDepa->Arriba != nullptr)
				{
					auxDepa = auxDepa->Arriba;
				}
				while (auxDepa->Anterior != nullptr)
				{
					if (auxDepa->Nombre == departamento)
					{
						NodoUser->Siguiente = aux;
						NodoUser->Anterior = aux->Anterior;

						aux->Anterior->Siguiente = NodoUser;
						aux->Anterior = NodoUser;
						break;
					}
					auxDepa = auxDepa->Anterior;
				}
			}
		} while (aux->Siguiente != nullptr && NodoUser->Anterior == nullptr);
		if (NodoUser->Anterior == nullptr && NodoUser->Adelante == nullptr)
		{
			aux->Siguiente = NodoUser;
			NodoUser->Anterior = aux;
		}
	}

}

//------------CREANDO CABECERAS INICIA------------
Nodo* Matriz::CrearEmpresa(string empresa)
{
	Nodo* empresaInsertar;
	empresaInsertar = new Nodo(empresa,"","");

	Nodo* aux = Cabecera;

	/*RECORRE MIENTRAS EL NODO AUX SEA 
	DIFERENTE DE NULLO*/
	while (aux->Abajo!=nullptr)
	{
		aux = aux->Abajo;
	}
	/*TERMINA EL WHILE E INSERTA EN EL ABAJO
	Y LE ASIGNA AL NUEVO EL AUX COMO ARRIBA*/
	aux->Abajo = empresaInsertar;
	empresaInsertar->Arriba = aux;
	return empresaInsertar; 
}
//------------CREANDO CABECERAS TERMINA------------

//------------BUSCANDO CABECERAS INICIA----------
Nodo* Matriz::CrearDepartamento(string depa)
{
	Nodo* departamentoInsertar;
	departamentoInsertar = new Nodo(depa, "","");

	Nodo* aux = Cabecera;

	/*RECORRE MIENTRAS EL NODO AUX SEA
	DIFERENTE DE NULLO*/
	while (aux->Siguiente != nullptr)
	{
		aux = aux->Siguiente;
	}
	/*TERMINA EL WHILE E INSERTA EN EL SIGUIENTE
	Y LE ASIGNA AL NUEVO EL AUX COMO ANTERIOR*/
	aux->Siguiente = departamentoInsertar;
	departamentoInsertar->Anterior = aux;
	return departamentoInsertar;
}

bool Matriz::VerificarCreaciónUsuario(string empresa, string user, string departamento) {
	Nodo* NodoDepa = BuscarDepartamento(departamento, Cabecera);
	Nodo* NodoEmpre = BuscarEmpresa(empresa, Cabecera);

	if (NodoDepa == nullptr)
	{
		NodoDepa = CrearDepartamento(departamento);
	}
	if (NodoEmpre == nullptr)
	{
		NodoEmpre = CrearEmpresa(empresa);
	}
	Nodo* aux = NodoDepa;
	if (aux->Abajo!=nullptr) {
		do {
			aux = aux->Abajo;
			if (!VerificarEmpresita(empresa, aux)) {
				Nodo* auxEmpresita = aux->Anterior;
				while (auxEmpresita->Anterior != nullptr) {
					auxEmpresita = auxEmpresita->Anterior;
				}
				while (auxEmpresita->Arriba != nullptr) {
					if (auxEmpresita->Nombre == empresa) {
						break;
					}
					auxEmpresita = auxEmpresita->Arriba;
				}
			}
		} while (aux->Abajo != nullptr);
		if (aux->Atras != nullptr) {
			if (aux->Nombre == user) {
				return false;
			}
			else {
				while (aux->Atras != nullptr) {
					aux = aux->Atras;
					if (aux->Nombre == user) {
						return false;
						break;
					}
					else {
						return true;
						
					}
				}
			}
		}
	}
	else {
		return true;
	}
}

bool Matriz::AccesoUsuario(string usuario, string contrasenia) {
	Nodo* aux = Cabecera;
	Nodo* auxUsuario;
	if (aux->Abajo!=nullptr) {
		while (aux->Abajo!=nullptr) {
			aux = aux->Abajo;
			while (aux->Siguiente != nullptr) {
			    auxUsuario = aux->Siguiente;
				if (auxUsuario->Nombre == usuario) {
					if (auxUsuario->Contra == contrasenia) {
						return true;
					}
				}
				else if (auxUsuario->Atras != nullptr) {
					while (auxUsuario->Atras != nullptr) {
						auxUsuario = auxUsuario->Atras;
						if (auxUsuario->Nombre == usuario) {
							if (auxUsuario->Contra == contrasenia) {
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	else {
		cout << "**********	   NO SE HA CREADO UN NADA    *********\n\n\n\n";
		return false;
	}
}

Nodo* Matriz::BuscarDepartamento(string depa, Nodo* inicio)
{
	Nodo* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->Nombre == depa)
		{
			return aux;
		}
		aux = aux->Siguiente;
	}
	return nullptr;
}





Nodo* Matriz::BuscarEmpresa(string empre, Nodo* inicio)
{
	Nodo* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->Nombre == empre)
		{
			return aux;
		}
		aux = aux->Abajo;
	}
	return nullptr;
}
//------------BUSCANDO CABECERAS TERMINA----------

bool Matriz::VerificarEmpresa(string empresa, Nodo* inicio, Nodo* User)
{
	Nodo* auxEmpresa = inicio->Anterior;
	while (auxEmpresa->Anterior!=nullptr)
	{
		auxEmpresa = auxEmpresa->Anterior;
	}
	if (auxEmpresa->Nombre==empresa)
	{ 
		while (inicio->Atras !=nullptr)
		{
			inicio = inicio->Atras;
		}
		inicio->Atras = User;
		User->Adelante = inicio;
		return true;
	}
	return false;
}

bool Matriz::VerificarEmpresita(string empresa, Nodo* inicio) {
	Nodo* auxEmpresita = inicio->Anterior;
	while (auxEmpresita->Anterior!=nullptr) {
		auxEmpresita = auxEmpresita->Anterior;
	}
	if (auxEmpresita->Nombre == empresa) {
		return true;
	}
	return false;
}

bool Matriz::VerificarDepartamento(string departamento, Nodo* inicio, Nodo* User)
{
	Nodo* auxDepartamento = inicio->Arriba;
	while (auxDepartamento->Arriba != nullptr)
	{
		auxDepartamento = auxDepartamento->Arriba;
	}
	if (auxDepartamento->Nombre == departamento)
	{
		while (inicio->Atras!=nullptr)
		{
			inicio = inicio->Atras;
		}
		inicio->Atras = User;
		User->Adelante = inicio;
		return true;
	}
	return false;
}