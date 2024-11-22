#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista lista;

    cout << "Testando a implementacao da lista encadeada" << endl;

    cout << "\nTestando a insercao de nos:" << endl;
    lista.inserir(5, 3);
    lista.inserir(4, 1);
    lista.inserir(3, 2);
    lista.inserir(4, 3);
    lista.exibirTodos();

    cout << "\nTestando a procura por um no:" << endl;
    No *no = lista.procurar(2);
    if (no)
    {
        cout << "Encontrado: (" << no->coeficiente << ", " << no->expoente << ")" << endl;
    }
    else
    {
        cout << "Nao encontrado!" << endl;
    }

    cout << "\nTestando a alteracao de um no:" << endl;
    no = lista.procurar(2);
    if (no)
    {
        lista.alterarNo(no, 6, 2);
        lista.exibirTodos();
    }

    cout << "\nTamanho da lista: " << lista.obterTamanho() << endl;

    cout << "\nTestando a exclusao de um no:" << endl;
    lista.excluirNo(3);
    lista.exibirTodos();

    cout << "\nTestando a destrucao de um no:" << endl;
    no = lista.procurar(4);
    if (no)
    {
        lista.destruirNo(no);
        lista.exibirTodos();
    }

    cout << "\nTestando a existencia de um no:" << endl;
    if (lista.existe(1))
    {
        cout << "O no com expoente 1 existe!" << endl;
    }
    else
    {
        cout << "O no com expoente 1 nao existe!" << endl;
    }

    cout << "\nTamanho da lista: " << lista.obterTamanho() << endl;

    return 0;
}