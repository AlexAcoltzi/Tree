#include<iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T Object;
    Node<T> *Child;
    Node<T> *Sibling;

public:
    Node(T Object);
    template <typename U>
    friend class Tree_B;
};
template <typename T>
Node<T>::Node(T Object)
{
    this->Object = Object;
    Child = nullptr;
    Sibling = nullptr;
}
template <typename T>
class Tree_b
{
private:
    Node<T> *Root;
public:
    Tree_b();
    void Add_Root(T,int);
};
template <typename T>
Tree_b<T>::Tree_b()
{
    Root = nullptr;
}
