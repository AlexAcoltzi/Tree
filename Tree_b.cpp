#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T Object;
    Node<T> *ChildLeft;
    Node<T> *ChildRight;
    Node<T> *SiblingLeft;
    Node<T> *SiblingRight;

public:
    Node(T Object);
    template <typename U>
    friend class Tree_B;
};
template <typename T>
Node<T>::Node(T Object)
{
    this->Object = Object;
    ChildLeft = nullptr;
    ChildRight = nullptr;
    SiblingLeft = nullptr;
    SiblingRight = nullptr;
}
template <typename T>
class Tree_b
{
private:
    Node<T> *Root;
    void Add_Node(Node<T> *, T, int); //funcion principal de añadir un nodo
    bool Full_node(Node<T> *, int);

public:
    Tree_b();
    void Add_Root(T, int); //funcion para añadir la raiz
    void Add_Node(T, int); // funcion publica que se invoca en el main e invocara la funcion principal
};
template <typename T>
Tree_b<T>::Tree_b()
{
    Root = nullptr;
}
template <typename T>
void Tree_b<T>::Add_Root(T Element, int Max)
{
    if (Root == nullptr)
    {
        Root = new Node<T>(Element);
    }
    else
    {
        int result = (2 * Max);            //result cumple con la condicion de la raiz del arbol que puede tener de un elemento o 2n elementos
        int n = 1;                         //n es un contador y comienza en uno porque la posicion 0 ya esta ocupada
        Node<T> *aux = Root->SiblingRight; // empezamos en el hermano de la raiz puesto que ya sabemos que hay un elemento
        while (aux != nullptr && n < result)
        {
            aux = aux->SiblingRight;
            n++;
        }
        if (n < result) // verificamos que el ciclo se haya cerrado por que hay un espacio libre y no porque ya esta lleno el nodo
        {
            aux = new Node<T>(Element);
        }
        else
        {
            cout << "No se pudo ingresar el elemento porque la raiz ya esta llena/n";
        }
    }
}
template <typename T>
bool Tree_b<T>::Full_node(Node<T> *nodeRef, int Max)
{
    int result = (2 * Max) - 1;
    int n = 0;
    Node<T> *aux = nodeRef;
    while (aux->SiblingRight != nullptr && n < result)
    {
        aux = aux->SiblingRight;
        n++;
    }
    if (n == result)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
void Tree_b<T>::Add_Node(T Element, int Max)
{
    if (Root != nullptr)
    {
        Add_Node(Root, Element, Max);
    }
    else
    {
        cout << "No hay un arbol existente primero cree un arbol agregando una raiz /n";
    }
}
template <typename T>
void Tree_b<T>::Add_Node(Node<T> *nodeRef, T Element, int Max)
{
    Node<T> *aux = new Node<T>(Element);
    Node<T> *auxF = nodeRef;
    if (Full_node(nodeRef,Max) != )
    {
        /* code */
    }
    
    while (auxF != nullptr && Element > auxF->Object)
    {
        auxF = auxF->SiblingRight;
    }
    if (Element > auxF->Object)
    {
        if (auxF->ChildRight == nullptr)
        {
            auxF->ChildRight = aux;
            if (auxF->SiblingRight != nullptr)
            {
                auxF->SiblingRight->ChildLeft = aux;
            }
        }
        else if (Full_node(auxF->ChildRight, Max) == true)
        {
            Add_Node(auxF->ChildRight, Element, Max)
        }
        else if (Full_node(auxF->ChildRight, Max) == false)
        {
            Add_Element(auxF->ChildRight, Element, Max);
        }
    }
    else if (Element < auxF->Object)
    {
        if (auxF->ChildLeft == nullptr)
        {
            auxF->ChildLeft = aux;
            if (auxF->SiblingLeft != nullptr)
            {
                auxF->SiblingLeft->ChildRight = aux;
            }
        }
        else if (Full_node(auxF->ChildLeft, Max) == true)
        {
            Add_Node(auxF->ChildLeft, Element, Max)
        }
        else if (Full_node(auxF->ChildLeft, Max) == false)
        {
            Add_Element(auxF->ChildLeft, Element, Max);
        }
    }
}
template <typename T>
