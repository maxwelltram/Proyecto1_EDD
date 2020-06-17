

#include <iostream>
#include "Matriz.h"
#include <cctype>
#include "Admin.h"
#include "NodoC.h";
#include "NodoA.h"
#include "Arbol.h"


int main()
{
    Admin* inicia = new Admin();
    //NodoC* llama = new NodoC();
    

    
    /*NodoA* llama = new NodoA();
    NodoA* raiz = nullptr;


    raiz = llama->Insertar(raiz, 1, "HOLA","aa", "fasdfasdf");
    raiz= llama->Insertar(raiz, 2, "HOLA", "aa", "fasdfasdf");
    raiz= llama->Insertar(raiz, 3, "HOLA", "aa", "fasdfasdf");
    raiz= llama->Insertar(raiz, 4, "HOLA", "aa", "fasdfasdf");
    raiz = llama->Insertar(raiz, 6, "HOLA", "aa", "fasdfasdf");
    raiz = llama->Insertar(raiz, 10, "HOLA", "aa", "fasdfasdf");
    raiz = llama->Insertar(raiz, 18, "HOLA", "aa", "fasdfasdf");
    llama->preOrder(raiz);*/



    //llama->InsertarElemento("aa","aa","A","guatemala","max","12/13/15");
    //llama->InsertarElemento("aa", "aa", "B", "guatemala", "max", "12/13/15");
    //llama->InsertarElemento("aa", "aa", "C", "guatemala", "max", "12/13/15");
    //llama->InsertarElemento("aa", "aa", "D", "guatemala", "max", "12/13/15");
    //llama->Mostrar();





    //Matriz* matri = new Matriz();
    //matri->InsertarElemento("maxwelltram", "maxwelltram","MaxwelltRamirez","walmart","guatemala");
    //matri->InsertarElemento("prueba", "prueba", "pruebasnumerouno", "walmart", "guatemala");
    //matri->InsertarElemento("pruebados", "pruebados", "pruebasnumerodos", "walmart", "guatemala");
    inicia->Menu();
    
}

