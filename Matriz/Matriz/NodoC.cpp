#include "NodoC.h"
using namespace std;

void NodoC::InsertarElemento(string idTransa, string idActivo, string Usuario, string Depa, string Empre, string Fecha) {
	NodoC* NodoTransaccion;
	NodoTransaccion = new NodoC(idTransa, idActivo, Usuario, Depa, Empre, Fecha);


	if (Primero== nullptr) {
		Primero = NodoTransaccion;
		Primero->Siguiente = Primero;
		Primero->Anterior = Primero;
		Ultimo = Primero;
	}
	else {
		Ultimo->Siguiente = NodoTransaccion;
		NodoTransaccion->Anterior = Ultimo;
		NodoTransaccion->Siguiente = Primero;
		Ultimo = NodoTransaccion;
		Primero->Anterior = Ultimo;
	}

}

void NodoC::Mostrar() {
	NodoC* aux;
	aux = Primero;
	if (aux!=nullptr) {
		do {
			cout << "<<" << aux->usuario << ">>";
			aux = aux->Siguiente;
		} while (aux != Primero);
	}
	else {
		cout << "****************CHINGE A SU MADRE, ESTA VACIA ESTA COSA************\n\n\n";
		system("pause");
	}
}