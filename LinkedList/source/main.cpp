#include <iostream>
#include <list>
#include "List.h"

using namespace std;

int main()
{
    List lista;

    cout << "Testando a implementacao da lista encadeada" << endl;

    cout << "\nTestando a insercao de nos:" << endl;
    lista.insert(5, 3);
    lista.insert(4, 1);
    lista.insert(3, 2);
    lista.insert(4, 3);
    lista.showAll();

    cout << "\nTestando a procura por um no:" << endl;
    Node *no = lista.search(2);
    if (no)
    {
        cout << "Encontrado: (" << no->coefficient << ", " << no->exponent << ")" << endl;
    }
    else
    {
        cout << "Nao encontrado!" << endl;
    }

    cout << "\nTestando a alteracao de um no:" << endl;
    no = lista.search(2);
    if (no)
    {
        lista.changeNode(no, 6, 2);
        lista.showAll();
    }

    cout << "\nTamanho da lista: " << lista.size() << endl;

    cout << "\nTestando a exclusao de um no:" << endl;
    lista.excludeNode(3);
    lista.showAll();

    cout << "\nTestando a destrucao de um no:" << endl;
    no = lista.search(4);
    if (no)
    {
        lista.destroyNode(no);
        lista.showAll();
    }

    cout << "\nTestando a existencia de um no:" << endl;
    if (lista.exists(1))
    {
        cout << "O no com expoente 1 existe!" << endl;
    }
    else
    {
        cout << "O no com expoente 1 nao existe!" << endl;
    }

    cout << "\nTamanho da lista: " << lista.size() << endl;

    return 0;
}