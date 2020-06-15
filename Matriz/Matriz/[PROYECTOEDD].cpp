

#include <iostream>
#include "Matriz.h"
#include <cctype>
#include "Admin.h"
#include "NodoC.h";


int main()
{
    Admin* inicia = new Admin();
    NodoC* llama = new NodoC();

    llama->InsertarElemento("aa","aa","A","guatemala","max","12/13/15");
    llama->InsertarElemento("aa", "aa", "B", "guatemala", "max", "12/13/15");
    llama->InsertarElemento("aa", "aa", "C", "guatemala", "max", "12/13/15");
    llama->InsertarElemento("aa", "aa", "D", "guatemala", "max", "12/13/15");
    llama->Mostrar();
    //Matriz* matri = new Matriz();
    //matri->InsertarElemento("maxwelltram", "maxwelltram","MaxwelltRamirez","walmart","guatemala");
    //matri->InsertarElemento("prueba", "prueba", "pruebasnumerouno", "walmart", "guatemala");
    //matri->InsertarElemento("pruebados", "pruebados", "pruebasnumerodos", "walmart", "guatemala");
    inicia->Menu();
    
}

