#include "List.h"

List::List() : head(nullptr), _size(0) {}

List::List(const List &other) : head(nullptr), _size(0)
{
    Node *current = other.head;
    while (current)
    {
        insert(current->coefficient, current->exponent);
        current = current->next;
    }
}

List &List::operator=(const List &other)
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
            insert(current->coefficient, current->exponent);
            current = current->next;
        }
    }
    return *this;
}

List::~List()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *List::getNext(Node *node)
{
    return node ? node->next : nullptr;
}

void List::getValue(Node *node)
{
    if (!node)
    {
        return;
    }
    std::cout << "(" << node->coefficient << ", " << node->exponent << ")" << std::endl;
}

void List::changeNode(Node *node, int coef, int exp)
{
    int oldExp = node->exponent;

    if (!node)
    {
        return;
    }

    if (exists(exp))
    {
        Node *node = search(exp);
        node->coefficient = node->coefficient + coef;
    }
    else
    {
        node->coefficient = coef;
        node->exponent = exp;
    }

    if (exp != oldExp)
    {
        excludeNode(node->exponent);
        insert(node);
    }
}

size_t List::size()
{
    return _size;
}

bool List::exists(int exp)
{
    Node *current = head;
    while (current)
    {
        if (current->exponent == exp)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void List::showAll()
{
    Node *current = head;
    while (current)
    {
        std::cout << "(" << current->coefficient << ", " << current->exponent << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node *List::search(int exp)
{
    Node *current = head;
    while (current)
    {
        if (current->exponent == exp)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::insert(int coef, int exp)
{
    if (exists(exp))
    {
        Node *node = search(exp);
        node->coefficient = node->coefficient + coef;
    }
    Node *newNode = new Node(coef, exp);
    insert(newNode);
}

void List::insert(Node *node)
{
    if (!node)
    {
        return;
    }
    if (!head || head->exponent < node->exponent)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node *current = head;
        while (current->next && current->next->exponent > node->exponent)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    _size++;
}

void List::excludeNode(int exp)
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

    _size--;
}

void List::destroyNode(Node *node)
{
    if (!node)
        return;

    excludeNode(node->exponent);

    delete node;
}