#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>

class List
{
private:
    Node *head;
    size_t _size;

    /**
     * @brief Insere um nó na lista.
     *
     * @param node O nó a ser inserido.
     */
    void insert(Node *node);

public:
    /**
     * @brief Construtor padrão da lista encadeada.
     */
    List();

    /**
     * @brief Construtor de cópia para a lista encadeada.
     *
     * @param other A lista a ser copiada.
     */
    List(const List &other);

    /**
     * @brief Operador de atribuição para a lista encadeada.
     *
     * @param other A lista a ser atribuída.
     * @return Uma referência à lista atual.
     */
    List &operator=(const List &other);

    /**
     * @brief Destrutor da lista encadeada.
     */
    ~List();

    /**
     * @brief Obtém o próximo nó da lista.
     *
     * @param node O nó a partir do qual obter o próximo nó.
     * @return Um ponteiro para o próximo nó, ou nullptr se não houver próximo nó.
     */
    Node *getNext(Node *node);

    /**
     * @brief Imprime o valor de um nó dado.
     *
     * @param node O nó cujo valor será impresso.
     */
    void getValue(Node *node);

    /**
     * @brief Altera o valor de um nó existente.
     *
     * @param node O nó a ser alterado.
     * @param coef O novo coeficiente.
     * @param exp O novo expoente.
     */
    void changeNode(Node *node, int coef, int exp);

    /**
     * @brief Retorna o tamanho da lista.
     *
     * @return O número de nós na lista.
     */
    size_t size();

    /**
     * @brief Verifica se um nó com o expoente fornecido existe na lista.
     *
     * @param exp O expoente a ser verificado.
     * @return true se um nó com o expoente fornecido existir, false caso contrário.
     */
    bool exists(int exp);

    /**
     * @brief Exibe todos os nós da lista.
     */
    void showAll();

    /**
     * @brief Procura um nó com um expoente específico.
     *
     * @param exp O expoente a ser procurado.
     * @return Um ponteiro para o nó com o expoente fornecido, ou nullptr se não encontrado.
     */
    Node *search(int exp);

    /**
     * @brief Insere um novo nó com o coeficiente e o expoente fornecidos.
     *
     * @param coef O coeficiente do novo nó.
     * @param exp O expoente do novo nó.
     */
    void insert(int coef, int exp);

    /**
     * @brief Exclui um nó com o expoente fornecido da lista.
     *
     * @param exp O expoente do nó a ser excluído.
     */
    void excludeNode(int exp);

    /**
     * @brief Destroi um nó removendo-o da lista e excluindo-o.
     *
     * @param node O nó a ser destruído.
     */
    void destroyNode(Node *node);
};

#endif