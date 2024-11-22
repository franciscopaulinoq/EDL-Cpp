#ifndef POLINOMIO_H
#define POLINOMIO_H

#include "No.h"
#include <string>
#include <ostream>

class Polinomio
{
private:
    No *inicio;
    int tamanho;

    /**
     * @brief Adiciona um monômio ao polinômio usando um nó existente.
     *
     * Insere um nó já criado que representa um monômio no polinômio baseado no
     * valor do expoente, mantendo a ordem do polinômio.
     * Se um monômio com o mesmo expoente já existir, os coeficientes serão somados,
     *  seguindo a operação de simplificação.
     * Caso o coeficiente resultante seja zero, o monômio será removido.
     *
     * @param node Um ponteiro para o nó que contém o monômio a ser adicionado.
     */
    void addMonomio(No *no);

public:
    /**
     * @brief Construtor padrão para o polinômio.
     * Inicializa o polinômio com o ponteiro "head" como nullptr e tamanho como 0.
     */
    Polinomio();

    /**
     * @brief Construtor de cópia para o polinômio.
     * Cria um novo polinômio copiando os nós de outro polinômio.
     *
     * @param outro O polinômio do qual copiar.
     */
    Polinomio(const Polinomio &outro);

    /**
     * @brief Operador de atribuição para o polinômio.
     * Atribui o conteúdo de outro polinômio ao polinômio atual, excluindo todos os nós existentes.
     *
     * @param outro O polinômio a ser atribuído.
     * @return Uma referência ao polinômio atual.
     */
    Polinomio &operator=(const Polinomio &outro);

    /**
     * @brief Destrutor para o polinômio.
     * Exclui todos os nós no polinômio.
     */
    ~Polinomio();

    /**
     * @brief Retorna a soma de dois polinômios.
     *
     * Cria um novo polinômio que representa a soma dos termos do polinômio atual
     *  e dos termos de outro polinômio.
     *
     * @param outro O polinômio a ser adicionado.
     * @return O polinômio resultante da soma.
     */
    Polinomio operator+(const Polinomio &outro) const;

    /**
     * @brief Subtrai dois polinômios.
     *
     * Retorna um novo polinômio que representa a diferença entre o polinômio atual e o polinômio fornecido.
     *
     * @param outro O polinômio a ser subtraído do polinômio atual.
     * @return Um novo polinômio que representa a diferença.
     */
    Polinomio operator-(const Polinomio &outro) const;

    /**
     * @brief Multiplica dois polinômios.
     *
     * Retorna um novo polinômio que representa o produto do polinômio atual e o polinômio fornecido.
     *
     * @param outro O polinômio a ser multiplicado com o polinômio atual.
     * @return Um novo polinômio que representa o produto.
     */
    Polinomio operator*(const Polinomio &outro) const;

    /**
     * @brief Adiciona outro polinômio ao polinômio atual.
     *
     * Atualiza o polinômio atual somando-o com o polinômio fornecido.
     *
     * @param outro O polinômio a ser adicionado.
     * @return Referência ao polinômio atual, atualizado após a soma.
     */
    Polinomio &operator+=(const Polinomio &outro);

    /**
     * @brief Subtrai outro polinômio do polinômio atual.
     *
     * Atualiza o polinômio atual subtraindo o polinômio fornecido.
     *
     * @param outro O polinômio a ser subtraído.
     * @return Referência ao polinômio atual, atualizado após a subtração.
     */
    Polinomio &operator-=(const Polinomio &outro);

    /**
     * @brief Multiplica o polinômio atual por outro polinômio.
     *
     * Atualiza o polinômio atual multiplicando-o pelo polinômio fornecido.
     *
     * @param outro O polinômio pelo qual o polinômio atual será multiplicado.
     * @return Referência ao polinômio atual, atualizado após a multiplicação.
     */
    Polinomio &operator*=(const Polinomio &outro);

    /**
     * @brief Adiciona um nó (monômio) ao polinômio.
     *
     * Insere um novo monômio, representado por seu coeficiente e expoente, no polinômio.
     * Se um monômio com o mesmo expoente já existir, os coeficientes serão somados.
     * Caso o coeficiente resultante seja zero, o monômio será removido.
     *
     * @param coef O coeficiente do monômio.
     * @param exp O expoente do monômio.
     */
    void addMonomio(double coef, double exp);

    /**
     * @brief Remove um monômio do polinômio com base no expoente fornecido.
     *
     * Procura no polinômio um monômio cujo expoente seja igual ao valor fornecido e o remove.
     * Se não houver um monômio correspondente, nenhuma ação será tomada.
     *
     * @param exp O expoente do monômio a ser removido.
     */
    void removeMonomio(int exp);

    /**
     * @brief Obtém o grau do polinômio.
     *
     * Retorna o maior expoente presente no polinômio.
     * Se o polinômio for vazio, o comportamento pode variar dependendo da implementação.
     *
     * @return O grau do polinômio (maior expoente).
     */
    int obterGrau() const;

    /**
     * @brief Obtém o número de termos no polinômio.
     *
     * @return O número de termos do polinômio.
     */
    int obterTamanho() const;

    /**
     * @brief Avalia o polinômio para um valor específico de x.
     *
     * Calcula o valor do polinômio substituindo x pelo valor fornecido.
     *
     * @param x O valor de x para a avaliação.
     * @return O valor resultante da avaliação do polinômio.
     */
    double avaliar(int x) const;

    /**
     * @brief Converte uma linha em um polinômio.
     *
     * Converte uma linha em polinômio por pares de valores.
     * A linha "3 4 5 6" torna-se um polinômio com nós (3, 4)
     * e (5, 6). 
     *
     * @param linha A linha que deve ser convertida.
     * @return Um novo polinômio que representa a linha.
     */
    static Polinomio parser(std::string linha);

    /**
     * @brief Sobrecarga do operador de saída para exibir o polinômio.
     *
     * Permite que o polinômio seja exibido diretamente em um fluxo de saída (por exemplo, `std::cout`).
     *
     * @param os O fluxo de saída.
     * @param Polinomio O polinômio a ser exibido.
     * @return O fluxo de saída atualizado.
     */
    friend std::ostream &operator<<(std::ostream &os, const Polinomio &Polinomio);

    /**
     * @brief Converte o polinômio em uma representação de string.
     *
     * Retorna uma representação textual do polinômio, onde cada termo é formatado
     * com o coeficiente, a variável 'x', e o expoente (se aplicável).
     *
     * @return Uma string representando o polinômio.
     */
    std::string toString() const;
};

#endif