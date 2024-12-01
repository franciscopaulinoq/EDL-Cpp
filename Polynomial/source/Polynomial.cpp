#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Node.h"
#include "Polynomial.h"

Polynomial::Polynomial() : head(nullptr), _size(0) {}

Polynomial::Polynomial(const Polynomial &other) : head(nullptr), _size(0)
{
    Node *current = other.head;
    while (current)
    {
        addMonomial(current->coefficient, current->exponent);
        current = current->next;
    }
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        Node *current = other.head;
        while (current)
        {
            addMonomial(current->coefficient, current->exponent);
            current = current->next;
        }
    }
    return *this;
}

Polynomial::~Polynomial()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Polynomial Polynomial::operator+(const Polynomial &other) const
{
    Polynomial result;
    Node *p1 = head;
    Node *p2 = other.head;

    while (p1 || p2)
    {
        if (p1 && (!p2 || p1->exponent > p2->exponent))
        {
            result.addMonomial(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p2 && (!p1 || p2->exponent > p1->exponent))
        {
            result.addMonomial(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        else
        {
            result.addMonomial(p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial &other) const
{
    Polynomial result;
    Node *p1 = head;
    Node *p2 = other.head;

    while (p1 || p2)
    {
        if (p1 && (!p2 || p1->exponent > p2->exponent))
        {
            result.addMonomial(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p2 && (!p1 || p2->exponent > p1->exponent))
        {
            result.addMonomial(-p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        else
        {
            result.addMonomial(p1->coefficient - p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other) const
{
    Polynomial result;

    for (Node *p1 = head; p1 != nullptr; p1 = p1->next)
    {
        for (Node *p2 = other.head; p2 != nullptr; p2 = p2->next)
        {
            result.addMonomial(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
        }
    }

    return result;
}

Polynomial &Polynomial::operator+=(const Polynomial &other)
{
    Node *p2 = other.head;

    while (p2)
    {
        addMonomial(p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &other)
{
    Node *p2 = other.head;

    while (p2)
    {
        addMonomial(-p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &other)
{
    Polynomial result;

    for (Node *p1 = head; p1 != nullptr; p1 = p1->next)
    {
        for (Node *p2 = other.head; p2 != nullptr; p2 = p2->next)
        {
            result.addMonomial(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
        }
    }

    *this = result;

    return *this;
}

void Polynomial::addMonomial(double coef, double exp)
{
    if (floor(exp) != exp || exp < 0)
    {
        std::ostringstream oss;
        oss << exp;
        throw std::invalid_argument("The exponent must be a positive integer. Value found: " + oss.str());
    }

    if (coef == 0)
        return;

    Node *novoNo = new Node(coef, static_cast<int>(exp));

    addMonomial(novoNo);
}

void Polynomial::addMonomial(Node *node)
{
    if (!node)
        return;

    if (!head || head->exponent < node->exponent)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node *current = head;
        while (current->next && current->next->exponent >= node->exponent)
        {
            current = current->next;
        }
        if (current->exponent == node->exponent)
        {
            current->coefficient += node->coefficient;
            if (current->coefficient == 0)
            {
                removeMonomial(node->exponent);
            }
            delete node;
            return;
        }
        else
        {
            node->next = current->next;
            current->next = node;
        }
    }

    _size++;
}

void Polynomial::removeMonomial(int exp)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current && current->exponent != exp)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
    {
        return;
    }

    if (prev)
    {
        prev->next = current->next;
    }
    else
    {
        head = current->next;
    }

    delete current;
    _size--;
}

int Polynomial::degree() const
{
    return head->exponent;
}

size_t Polynomial::size() const
{
    return _size;
}

double Polynomial::evaluate(double x) const
{
    double sum = 0.0;
    Node *current = head;

    while (current)
    {
        sum += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }

    return sum;
}

Polynomial Polynomial::parser(std::string linha)
{
    Polynomial polynomial;
    std::stringstream ss(linha);
    double coef, exp;

    while (ss >> coef >> exp)
    {
        polynomial.addMonomial(coef, exp);
    }

    return polynomial;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &Polynomial)
{
    os << Polynomial.toString();
    return os;
}

std::string Polynomial::toString() const
{
    std::ostringstream oss;
    Node *current = head;

    while (current)
    {
        if (current->coefficient > 0 && current != head)
            oss << " + ";

        if (current->coefficient < 0)
            oss << " - ";

        oss << fabs(current->coefficient);

        if (current->exponent > 0)
        {
            if (current->exponent == 1)
            {
                oss << "x";
            }
            else
            {
                oss << "x^" << current->exponent;
            }
        }

        current = current->next;
    }

    return oss.str();
}