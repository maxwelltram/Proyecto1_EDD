#pragma once
#include  <iostream>
using namespace std;
class NodoA
{
	public:
		NodoA* raiz = NULL;
		int key;
		string nombre;
		string descripcion;
		string ID;
		NodoA* izquierda;
		NodoA* Derecha;
		int alturas;

		int max(int, int);

		int altura(NodoA* n);

		NodoA* NuevoNodo(int key, string nombre, string descripcion, string id);

		NodoA* RotacionDerecha(NodoA* y);

		NodoA* RotacionIzquierda(NodoA* x);

		int Balancear(NodoA* N);

		NodoA* Insertar(NodoA* nodo, int key, string nombre, string descripcion, string id);

		NodoA* BorrarNodo(NodoA*, int);

		NodoA* ValorMin(NodoA*);

		void preOrder(NodoA*);
};

