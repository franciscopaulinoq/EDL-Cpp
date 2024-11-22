#include "Lista.h"

using namespace std;

Lista::Lista() : inicio(nullptr), tamanho(0) {}

Lista::Lista(const Lista &outro) : inicio(nullptr), tamanho(0)
{
    No *atual = outro.inicio;
    while (atual)
    {
        inserir(atual->coeficiente, atual->expoente);
        atual = atual->proximo;
    }
}

Lista &Lista::operator=(const Lista &outro)
{
    if (this != &outro)
    {
        while (inicio)
        {
            No *temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }

        No *atual = outro.inicio;
        while (atual)
        {
            inserir(atual->coeficiente, atual->expoente);
            atual = atual->proximo;
        }
    }
    return *this;
}

Lista::~Lista()
{
    while (inicio)
    {
        No *temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

No *Lista::obterProximoNo(No *no)
{
    return no ? no->proximo : nullptr;
}

void Lista::obterValor(No *no)
{
    if (!no)
    {
        return;
    }
    cout << "(" << no->coeficiente << ", " << no->expoente << ")" << endl;
}

void Lista::alterarNo(No *no, int coef, int exp)
{
    int expAntigo = no->expoente;

    if (!no)
    {
        return;
    }

    if (existe(exp))
    {
        No *no = procurar(exp);
        no->coeficiente = no->coeficiente + coef;
    }
    else
    {
        no->coeficiente = coef;
        no->expoente = exp;
    }

    if (exp != expAntigo)
    {
        excluirNo(no->expoente);
        inserir(no);
    }
}

int Lista::obterTamanho()
{
    return tamanho;
}

bool Lista::existe(int exp)
{
    No *atual = inicio;
    while (atual)
    {
        if (atual->expoente == exp)
        {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void Lista::exibirTodos()
{
    No *atual = inicio;
    while (atual)
    {
        cout << "(" << atual->coeficiente << ", " << atual->expoente << ") ";
        atual = atual->proximo;
    }
    cout << endl;
}

No *Lista::procurar(int exp)
{
    No *atual = inicio;
    while (atual)
    {
        if (atual->expoente == exp)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void Lista::inserir(int coef, int exp)
{
    if (existe(exp))
    {
        No *no = procurar(exp);
        no->coeficiente = no->coeficiente + coef;
    }
    No *novoNo = new No(coef, exp);
    inserir(novoNo);
}

void Lista::inserir(No *no)
{
    if (!no)
    {
        return;
    }
    if (!inicio || inicio->expoente < no->expoente)
    {
        no->proximo = inicio;
        inicio = no;
    }
    else
    {
        No *atual = inicio;
        while (atual->proximo && atual->proximo->expoente > no->expoente)
        {
            atual = atual->proximo;
        }
        no->proximo = atual->proximo;
        atual->proximo = no;
    }
    tamanho++;
}

void Lista::excluirNo(int exp)
{
    No *atual = inicio;
    No *anterior = nullptr;

    while (atual && atual->expoente != exp)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (!atual)
    {
        return;
    }
    if (anterior)
    {
        anterior->proximo = atual->proximo;
    }
    else
    {
        inicio = atual->proximo;
    }

    tamanho--;
}

void Lista::destruirNo(No *no)
{
    if (!no)
        return;

    excluirNo(no->expoente);

    delete no;
}