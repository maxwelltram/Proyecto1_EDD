#pragma once
#include "NodoA.h"
class Arbol
{
public:

	int max(int, int);

	int altura(NodoA* n);

	NodoA* NuevoNodo(int key, string nombre, string descripcion, string id);

	NodoA* RotacionDerecha(NodoA* y);

	NodoA* RotacionIzquierda(NodoA* x);

	int Balancear(NodoA* N);

	NodoA* Insertar(NodoA* nodo, int key, string nombre, string descripcion, string id);

	void preOrder(NodoA*);
};

