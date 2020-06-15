#pragma once
#include <string>
#include "Matriz.h"
#include <iostream>
using namespace std;
class Admin
{
public:
	Matriz* matri = new Matriz();
	string usuario, contrasenia, empresa, departamento,user, contra;
	string nombreCom;
	int opcion;
	string admin = "admin";
	Admin() {

	}


	void Menu();

	void MenuAdmin();

	void CrearUsuario();

};

