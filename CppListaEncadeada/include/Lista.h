#ifndef LISTA_H
#define LISTA_H

#include "No.h"
#include <iostream>

class Lista
{
private:
    No *inicio;
    int tamanho;

    /**
     * @brief Insere um nó na lista.
     *
     * Este método insere o nó na posição correta com base no expoente, mantendo a ordem da lista.
     *
     * @param no O nó a ser inserido.
     */
    void inserir(No *no);

public:
    /**
     * @brief Construtor padrão da lista encadeada.
     * Inicializa a lista com o ponteiro da cabeça como nullptr e o tamanho como 0.
     */
    Lista();

    /**
     * @brief Construtor de cópia para a lista encadeada.
     * Cria uma nova lista copiando os nós de outra lista.
     *
     * @param outra A lista a ser copiada.
     */
    Lista(const Lista &outra);

    /**
     * @brief Operador de atribuição para a lista encadeada.
     * Atribui o conteúdo de outra lista à lista atual, excluindo quaisquer nós existentes.
     *
     * @param outra A lista a ser atribuída.
     * @return Uma referência à lista atual.
     */
    Lista &operator=(const Lista &outra);

    /**
     * @brief Destrutor da lista encadeada.
     * Exclui todos os nós da lista.
     */
    ~Lista();

    /**
     * @brief Obtém o próximo nó da lista.
     *
     * @param no O nó a partir do qual obter o próximo nó.
     * @return Um ponteiro para o próximo nó, ou nullptr se não houver próximo nó.
     */
    No *obterProximoNo(No *no);

    /**
     * @brief Imprime o valor de um nó dado.
     *
     * @param no O nó cujo valor será impresso.
     */
    void obterValor(No *no);

    /**
     * @brief Altera o valor de um nó existente.
     *
     * Este método altera o coeficiente e o expoente de um nó. Se o expoente mudar
     * e já existir um nó com o novo expoente, a alteração não será permitida.
     *
     * @param no O nó a ser alterado.
     * @param coef O novo coeficiente.
     * @param exp O novo expoente.
     */
    void alterarNo(No *no, int coef, int exp);

    /**
     * @brief Retorna o tamanho da lista.
     *
     * @return O número de nós na lista.
     */
    int obterTamanho();

    /**
     * @brief Verifica se um nó com o expoente fornecido existe na lista.
     *
     * @param exp O expoente a ser verificado.
     * @return true se um nó com o expoente fornecido existir, false caso contrário.
     */
    bool existe(int exp);

    /**
     * @brief Exibe todos os nós da lista.
     * Imprime o coeficiente e o expoente de cada nó na lista.
     */
    void exibirTodos();

    /**
     * @brief Procura um nó com um expoente específico.
     *
     * @param exp O expoente a ser procurado.
     * @return Um ponteiro para o nó com o expoente fornecido, ou nullptr se não encontrado.
     */
    No *procurar(int exp);

    /**
     * @brief Insere um novo nó com o coeficiente e o expoente fornecidos.
     *
     * Este método insere o nó na lista mantendo a ordem com base nos expoentes.
     *
     * @param coef O coeficiente do novo nó.
     * @param exp O expoente do novo nó.
     */
    void inserir(int coef, int exp);

    /**
     * @brief Exclui um nó com o expoente fornecido da lista.
     *
     * @param exp O expoente do nó a ser excluído.
     */
    void excluirNo(int exp);

    /**
     * @brief Destroi um nó removendo-o da lista e excluindo-o.
     *
     * @param no O nó a ser destruído.
     */
    void destruirNo(No *no);
};

#endif