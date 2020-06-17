#include "Arbol.h"
#include "NodoA.h"

int altura(NodoA* N)
{
    if (N == NULL)
        return 0;
    return N->alturas;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

NodoA* NuevoNodo(int key,string nombre, string descripcion, string ID)
{
    NodoA* node = new NodoA();
    node->key = key;
    node->nombre = nombre;
    node->descripcion = descripcion;
    node->ID = ID;
    node->izquierda = NULL;
    node->Derecha = NULL;
    node->alturas = 1; // new node is initially 
                      // added at leaf  
    return(node);
}

NodoA* RotacionDerecha(NodoA* y)
{
    NodoA* x = y->izquierda;
    NodoA* T2 = x->Derecha;

    // Perform rotation  
    x->Derecha = y;
    y->izquierda = T2;

    // Update heights  
    y->alturas = max(altura(y->izquierda),
        altura(y->Derecha)) + 1;
    x->alturas = max(altura(x->izquierda),
        altura(x->Derecha)) + 1;

    // Return new root  
    return x;
}

NodoA* RotacionIzquierda(NodoA* x)
{
    NodoA* y = x->Derecha;
    NodoA* T2 = y->izquierda;

    // Perform rotation  
    y->izquierda = x;
    x->Derecha = T2;

    // Update heights  
    x->alturas = max(altura(x->izquierda),
        altura(x->Derecha)) + 1;
    y->alturas = max(altura(y->izquierda),
        altura(y->Derecha)) + 1;

    // Return new root  
    return y;
}

int Balancear(NodoA* N)
{
    if (N == NULL)
        return 0;
    return altura(N->izquierda) - altura(N->Derecha);
}

NodoA* insert(NodoA* node, int key, string nombre, string descripcion, string ID)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(NuevoNodo(key,  nombre,  descripcion,  ID));

    if (key < node->key)
        node->izquierda = insert(node->izquierda, key, nombre, descripcion, ID);
    else if (key > node->key)
        node->Derecha = insert(node->Derecha, key, nombre, descripcion, ID);
    else // Equal keys are not allowed in BST  
        return node;

    /* 2. Update height of this ancestor node */
    node->alturas = 1 + max(altura(node->izquierda),
        altura(node->Derecha));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = Balancear(node);

    // If this node becomes unbalanced, then  
    // there are 4 cases  

    // Left Left Case  
    if (balance > 1 && key < node->izquierda->key)
        return RotacionDerecha(node);

    // Right Right Case  
    if (balance < -1 && key > node->Derecha->key)
        return RotacionIzquierda(node);

    // Left Right Case  
    if (balance > 1 && key > node->izquierda->key)
    {
        node->izquierda = RotacionIzquierda(node->izquierda);
        return RotacionDerecha(node);
    }

    // Right Left Case  
    if (balance < -1 && key < node->Derecha->key)
    {
        node->Derecha = RotacionDerecha(node->Derecha);
        return RotacionIzquierda(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void preOrder(NodoA* root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->izquierda);
        preOrder(root->Derecha);
    }
}