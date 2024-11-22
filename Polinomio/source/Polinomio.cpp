#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "No.h"
#include "Polinomio.h"

Polinomio::Polinomio() : inicio(nullptr), tamanho(0) {}

Polinomio::Polinomio(const Polinomio &outro) : inicio(nullptr), tamanho(0)
{
    No *atual = outro.inicio;
    while (atual)
    {
        addMonomio(atual->coeficiente, atual->expoente);
        atual = atual->proximo;
    }
}

Polinomio &Polinomio::operator=(const Polinomio &outro)
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
            addMonomio(atual->coeficiente, atual->expoente);
            atual = atual->proximo;
        }
    }
    return *this;
}

Polinomio::~Polinomio()
{
    while (inicio)
    {
        No *temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

Polinomio Polinomio::operator+(const Polinomio &outro) const
{
    Polinomio resultado;
    No *p1 = inicio;
    No *p2 = outro.inicio;

    while (p1 || p2)
    {
        if (p1 && (!p2 || p1->expoente > p2->expoente))
        {
            resultado.addMonomio(p1->coeficiente, p1->expoente);
            p1 = p1->proximo;
        }
        else if (p2 && (!p1 || p2->expoente > p1->expoente))
        {
            resultado.addMonomio(p2->coeficiente, p2->expoente);
            p2 = p2->proximo;
        }
        else
        {
            resultado.addMonomio(p1->coeficiente + p2->coeficiente, p1->expoente);
            p1 = p1->proximo;
            p2 = p2->proximo;
        }
    }

    return resultado;
}

Polinomio Polinomio::operator-(const Polinomio &outro) const
{
    Polinomio resultado;
    No *p1 = inicio;
    No *p2 = outro.inicio;

    while (p1 || p2)
    {
        if (p1 && (!p2 || p1->expoente > p2->expoente))
        {
            resultado.addMonomio(p1->coeficiente, p1->expoente);
            p1 = p1->proximo;
        }
        else if (p2 && (!p1 || p2->expoente > p1->expoente))
        {
            resultado.addMonomio(-p2->coeficiente, p2->expoente);
            p2 = p2->proximo;
        }
        else
        {
            resultado.addMonomio(p1->coeficiente - p2->coeficiente, p1->expoente);
            p1 = p1->proximo;
            p2 = p2->proximo;
        }
    }

    return resultado;
}

Polinomio Polinomio::operator*(const Polinomio &outro) const
{
    Polinomio resultado;

    for (No *p1 = inicio; p1 != nullptr; p1 = p1->proximo)
    {
        for (No *p2 = outro.inicio; p2 != nullptr; p2 = p2->proximo)
        {
            resultado.addMonomio(p1->coeficiente * p2->coeficiente, p1->expoente + p2->expoente);
        }
    }

    return resultado;
}

Polinomio &Polinomio::operator+=(const Polinomio &outro)
{
    No *p2 = outro.inicio;

    while (p2)
    {
        addMonomio(p2->coeficiente, p2->expoente);
        p2 = p2->proximo;
    }

    return *this;
}

Polinomio &Polinomio::operator-=(const Polinomio &outro)
{
    No *p2 = outro.inicio;

    while (p2)
    {
        addMonomio(-p2->coeficiente, p2->expoente);
        p2 = p2->proximo;
    }

    return *this;
}

Polinomio &Polinomio::operator*=(const Polinomio &outro)
{
    Polinomio resultado;

    for (No *p1 = inicio; p1 != nullptr; p1 = p1->proximo)
    {
        for (No *p2 = outro.inicio; p2 != nullptr; p2 = p2->proximo)
        {
            resultado.addMonomio(p1->coeficiente * p2->coeficiente, p1->expoente + p2->expoente);
        }
    }

    *this = resultado;

    return *this;
}

void Polinomio::addMonomio(double coef, double exp)
{
    if (floor(exp) != exp || exp < 0)
    {
        std::ostringstream oss;
        oss << exp;
        throw std::invalid_argument("O expoente deve ser um numero inteiro positivo. Valor encontrado: " + oss.str());
    }

    if (coef == 0)
        return;

    No *novoNo = new No(coef,  static_cast<int>(exp));

    addMonomio(novoNo);
}

void Polinomio::addMonomio(No *no)
{
    if (!no)
        return;

    if (!inicio || inicio->expoente < no->expoente)
    {
        no->proximo = inicio;
        inicio = no;
    }
    else
    {
        No *atual = inicio;
        while (atual->proximo && atual->proximo->expoente >= no->expoente)
        {
            atual = atual->proximo;
        }
        if (atual->expoente == no->expoente)
        {
            atual->coeficiente += no->coeficiente;
            if (atual->coeficiente == 0)
            {
                removeMonomio(no->expoente);
            }
            delete no;
            return;
        }
        else
        {
            no->proximo = atual->proximo;
            atual->proximo = no;
        }
    }

    tamanho++;
}

void Polinomio::removeMonomio(int exp)
{
    No *atual = inicio;
    No *prev = nullptr;

    while (atual && atual->expoente != exp)
    {
        prev = atual;
        atual = atual->proximo;
    }

    if (!atual)
    {
        return;
    }

    if (prev)
    {
        prev->proximo = atual->proximo;
    }
    else
    {
        inicio = atual->proximo;
    }

    delete atual;
    tamanho--;
}

int Polinomio::obterGrau() const
{
    return inicio->expoente;
}

int Polinomio::obterTamanho() const
{
    return tamanho;
}

double Polinomio::avaliar(double x) const
{
    double sum = 0.0;
    No *atual = inicio;

    while (atual)
    {
        sum += atual->coeficiente * pow(x, atual->expoente);
        atual = atual->proximo;
    }

    return sum;
}

Polinomio Polinomio::parser(std::string linha)
{
    Polinomio polinomio;
    std::stringstream ss(linha);
    double coef, exp;

    while (ss >> coef >> exp)
    {
        polinomio.addMonomio(coef, exp);
    }

    return polinomio;
}

std::ostream &operator<<(std::ostream &os, const Polinomio &Polinomio)
{
    os << Polinomio.toString();
    return os;
}

std::string Polinomio::toString() const
{
    std::ostringstream oss;
    No *atual = inicio;

    while (atual)
    {
        if (atual->coeficiente > 0 && atual != inicio)
            oss << " + ";

        if (atual->coeficiente < 0)
            oss << " - ";

        oss << fabs(atual->coeficiente);

        if (atual->expoente > 0)
        {
            if (atual->expoente == 1)
            {
                oss << "x";
            }
            else
            {
                oss << "x^" << atual->expoente;
            }
        }

        atual = atual->proximo;
    }

    return oss.str();
}