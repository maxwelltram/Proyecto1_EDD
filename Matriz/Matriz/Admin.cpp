#include "Admin.h"
#include "Reportes.h"
#include "Matriz.h"
#include <iostream>



void Admin::MenuAdmin() {
	cout << "**********   BIENVENIDO DE NUEVO ADMIN  ***********\n";
	cout << "**********1.	CREAR  NUEVO  USUARIO	***********\n";
	cout << "**********2.	CREAR  NUEVO  REPORTE	***********\n";
	cout << "**********3.	 CERRAR LA SESION   	***********\n";
	cin >> opcion;
	system("cls");
	Reportes* reporte = new Reportes();
	
	switch (opcion)
	{
	case 1:
		CrearUsuario();
		break;
	case 2:
		reporte->MenuReportes();
		break;
	case 3:
		Menu();
		break;
	}
}

void Admin::CrearUsuario()
{
	cout << "**********	   BIENVENIDO AL MENU  PARA	   *********\n";
	cout << "**********		CREAR  USUARIO		   *********\n";
	cout << "**********1.  ESCRIBA EL NOMBRE DE USUARIO         *********\n";
	cin >> usuario;
	cout << "**********2.  ESCRIBA LA NUEVA CONTRASENIA         *********\n";
	cin >> contrasenia;
	cout << "**********3.  ESCRIBA EL NOMBRE COMPLETO	   *********\n";
	cin >> nombreCom;
	cout << "**********4.  ESCRIBA EL NOMBRE DE EMPRESA         *********\n";
	cin >> empresa;
	cout << "**********5.  ESCRIBA EL NOMBRE DEL DEPARTAMENTO   *********\n";
	cin >> departamento;

	
	system("cls");
	
	for (int i = 0; i < usuario.size(); i++)
	{
		usuario[i] = tolower(usuario[i]);
	}
	for (int i = 0; i < contrasenia.size(); i++)
	{
		contrasenia[i] = tolower(contrasenia[i]);
	}
	for (int i = 0; i < nombreCom.size(); i++)
	{
		nombreCom[i] = tolower(nombreCom[i]);
	}
	for (int i = 0; i < empresa.size(); i++)
	{
		empresa[i] = tolower(empresa[i]);
	}
	for (int i = 0; i < departamento.size(); i++)
	{
		departamento[i] = tolower(departamento[i]);
	}
	
	
	if (matri->VerificarCreaciónUsuario(empresa, usuario, departamento) == true) {
		matri->InsertarElemento(usuario, contrasenia, nombreCom, empresa, departamento);
		cout << "**********	   CREADO EXITOSAMENTE	       *********\n\n\n\n";
	}
	else {
		cout << "**********	   YA EXISTE EL USUARIO		   *********\n";
		cout << "**********	   UTILIZA OTRO NOMBRE		   *********\n\n\n\n";
		MenuAdmin();
	}
	MenuAdmin();
}
void Admin::Menu() {
    
    cout << "**********BIENVENIDO AL INICIO DE SESION**********\n";
    cout << "**********INGRESE SU NOMBRE DE USUARIO ***********\n";
    cin >> user;
    cout << "**********INGRESE  SU   CONTRASEÑA     ***********\n";
    cin >> contra;

    /*Ciclos que funcionan solo para volver
   la cadena de strings  a minusculas*/
    for (int i = 0; i < user.size(); i++)
    {
        user[i] = tolower(user[i]);
    }
    for (int i = 0; i < contra.size(); i++)
    {
        contra[i] = tolower(contra[i]);
    }
    /*Ciclos que funcionan solo para volver
    la cadena de strings  a minusculas*/

    if (user == admin && contra == admin)
    {
        MenuAdmin();
        system("cls");
    }
    else if(matri->AccesoUsuario(user,contra)==true) {
        cout << "****** SE PUDO INGRESAR    *********\n\n\n\n\n";
        
    }
    else {
        cout << "******LO  SENTIMOS, NO SE PUDO INGRESAR*********\n\n\n\n\n";
        Menu();
    }
}