#include "NodoA.h"

int NodoA::altura(NodoA* N)
{
    if (N == NULL)
        return 0;
    return N->alturas;
}

int NodoA::max(int a, int b)
{
    return (a > b) ? a : b;
}

NodoA* NodoA::NuevoNodo(int key, string nombre, string descripcion, string ID)
{
    NodoA* node = new NodoA();
    node->key = key;
    node->nombre = nombre;
    node->descripcion = descripcion;
    node->ID = ID;
    node->izquierda = NULL;
    node->Derecha = NULL;
    node->alturas = 1; 

    return(node);
}

NodoA* NodoA::RotacionDerecha(NodoA* y)
{
    NodoA* x = y->izquierda;
    NodoA* T2 = x->Derecha;

      
    x->Derecha = y;
    y->izquierda = T2;

      
    y->alturas = max(altura(y->izquierda),
        altura(y->Derecha)) + 1;
    x->alturas = max(altura(x->izquierda),
        altura(x->Derecha)) + 1;

      
    return x;
}

NodoA* NodoA::RotacionIzquierda(NodoA* x)
{
    NodoA* y = x->Derecha;
    NodoA* T2 = y->izquierda;

     
    y->izquierda = x;
    x->Derecha = T2;

     
    x->alturas = max(altura(x->izquierda),
        altura(x->Derecha)) + 1;
    y->alturas = max(altura(y->izquierda),
        altura(y->Derecha)) + 1;

     
    return y;
}

int NodoA::Balancear(NodoA* N)
{
    if (N == NULL)
        return 0;
    return altura(N->izquierda) - altura(N->Derecha);
}

NodoA* NodoA::Insertar(NodoA* node, int key, string nombre, string descripcion, string ID)
{
    
    if (node == NULL)
        return(NuevoNodo(key, nombre, descripcion, ID));

    if (key < node->key)
        node->izquierda = Insertar(node->izquierda, key, nombre, descripcion, ID);
    else if (key > node->key)
        node->Derecha = Insertar(node->Derecha, key, nombre, descripcion, ID);
    else 
        return node;

    
    node->alturas = 1 + max(altura(node->izquierda),
        altura(node->Derecha));

    
    int balance = Balancear(node);

    

      
    if (balance > 1 && key < node->izquierda->key)
        return RotacionDerecha(node);

    
    if (balance < -1 && key > node->Derecha->key)
        return RotacionIzquierda(node);

      
    if (balance > 1 && key > node->izquierda->key)
    {
        node->izquierda = RotacionIzquierda(node->izquierda);
        return RotacionDerecha(node);
    }

     
    if (balance < -1 && key < node->Derecha->key)
    {
        node->Derecha = RotacionDerecha(node->Derecha);
        return RotacionIzquierda(node);
    }

    
    return node;
}

NodoA* NodoA::ValorMin(NodoA* node)
{
    NodoA* current = node;

    
    while (current->izquierda != NULL)
        current = current->izquierda;

    return current;
}


NodoA* NodoA::BorrarNodo(NodoA* root, int key)
{

    
    if (root == NULL)
        return root;

    
    if (key < root->key)
        root->izquierda = BorrarNodo(root->izquierda, key);

    
    else if (key > root->key)
        root->Derecha = BorrarNodo(root->Derecha, key);

     
    else
    {
          
        if ((root->izquierda == NULL) ||
            (root->Derecha == NULL))
        {
            NodoA* temp = root->izquierda ?
                root->izquierda :
                root->Derecha;

   
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
                *root = *temp; 
            free(temp);
        }
        else
        {
 
            NodoA* temp = ValorMin(root->Derecha);

  
            root->key = temp->key;


            root->Derecha = BorrarNodo(root->Derecha,
                temp->key);
        }
    }


    if (root == NULL)
        return root;
 
    root->alturas = 1 + max(altura(root->izquierda),
        altura(root->Derecha));


    int balance = Balancear(root);



 
    if (balance > 1 &&
        Balancear(root->izquierda) >= 0)
        return RotacionDerecha(root);
 
    if (balance > 1 &&
        Balancear(root->izquierda) < 0)
    {
        root->izquierda = RotacionDerecha(root->izquierda);
        return RotacionDerecha(root);
    }

 
    if (balance < -1 &&
        Balancear(root->Derecha) <= 0)
        return RotacionIzquierda(root);


    if (balance < -1 &&
        Balancear(root->Derecha) > 0)
    {
        root->Derecha = RotacionDerecha(root->Derecha);
        return RotacionIzquierda(root);
    }

    return root;
}


void NodoA::preOrder(NodoA* root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->izquierda);
        preOrder(root->Derecha);
    }
}