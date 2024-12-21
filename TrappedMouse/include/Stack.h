#ifndef STACK_H
#define STACK_H

#include <stdexcept>

/**
 * @brief Classe que implementa uma pilha (Stack).
 *
 * @tparam T O tipo de dados armazenado na pilha.
 */
template <class T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node *_top; /**< Ponteiro para o topo da pilha. */

    size_t _size; /**< Número de elementos na pilha. */

public:
    /**
     * @brief Construtor da pilha.
     */
    Stack();

    /**
     * @brief Destruidor da pilha.
     */
    ~Stack();

    /**
     * @brief Constrói e adiciona um novo elemento ao topo da pilha.
     *
     * @param args Os argumentos para construir o novo elemento.
     */
    template <typename... Args>
    void emplace(Args &&...args);

    /**
     * @brief Verifica se a pilha está vazia.
     *
     * @return Retorna `true` se a pilha estiver vazia, caso contrário, retorna `false`.
     */
    bool empty() const;

    /**
     * @brief Remove o elemento do topo da pilha.
     */
    void pop();

    /**
     * @brief Adiciona um elemento ao topo da pilha.
     *
     * @param value O valor a ser adicionado.
     */
    void push(const T &value);

    /**
     * @brief Retorna o número de elementos na pilha.
     *
     * @return O número de elementos na pilha.
     */
    size_t size() const;

    /**
     * @brief Troca o conteúdo de duas pilhas.
     *
     * @param other A pilha a ser trocada com a pilha atual.
     */
    void swap(Stack<T> &other);

    /**
     * @brief Retorna o elemento do topo da pilha.
     *
     * @return O valor armazenado no topo da pilha.
     */
    T top() const;
};

template <class T>
Stack<T>::Stack() : _top(nullptr), _size(0) {}

template <class T>
Stack<T>::~Stack()
{
    while (_top)
    {
        Node *temp = _top;
        _top = _top->next;
        delete temp;
    }
}

template <class T>
template <typename... Args>
void Stack<T>::emplace(Args &&...args)
{
    Node *newNode = new Node(T(std::forward<Args>(args)...));

    newNode->next = _top;
    _top = newNode;
    _size++;
}

template <class T>
bool Stack<T>::empty() const
{
    return _top == nullptr;
}

template <class T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::runtime_error("Empty stack!");
    }
    Node *temp = _top;
    _top = _top->next;
    delete temp;
    _size--;
}

template <class T>
void Stack<T>::push(const T &value)
{
    Node *newNode = new Node(value);
    newNode->next = _top;
    _top = newNode;
    _size++;
}

template <class T>
size_t Stack<T>::size() const
{
    return _size;
}

template <class T>
void Stack<T>::swap(Stack<T> &other)
{
    std::swap(_top, other._top);
    std::swap(_size, other._size);
}

template <class T>
T Stack<T>::top() const
{
    if (empty())
    {
        throw std::runtime_error("Empty stack!");
    }
    return _top->data;
}

#endif