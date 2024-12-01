#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Node.h"
#include <string>
#include <ostream>

class Polynomial
{
private:
    Node *head;
    size_t _size;

    /**
     * @brief Adiciona um monômio ao polinômio usando um nó existente.
     *
     * @param node Um ponteiro para o nó que contém o monômio a ser adicionado.
     */
    void addMonomial(Node *node);

public:
    /**
     * @brief Construtor padrão para o polinômio.
     */
    Polynomial();

    /**
     * @brief Construtor de cópia para o polinômio.
     *
     * @param other O polinômio do qual copiar.
     */
    Polynomial(const Polynomial &other);

    /**
     * @brief Operador de atribuição para o polinômio.
     *
     * @param other O polinômio a ser atribuído.
     * @return Uma referência ao polinômio atual.
     */
    Polynomial &operator=(const Polynomial &other);

    /**
     * @brief Destrutor para o polinômio.
     */
    ~Polynomial();

    /**
     * @brief Retorna a soma de dois polinômios.
     *
     * @param other O polinômio a ser adicionado.
     * @return O polinômio resultante da soma.
     */
    Polynomial operator+(const Polynomial &other) const;

    /**
     * @brief Subtrai dois polinômios.
     *
     * @param other O polinômio a ser subtraído do polinômio atual.
     * @return Um novo polinômio que representa a diferença.
     */
    Polynomial operator-(const Polynomial &other) const;

    /**
     * @brief Multiplica dois polinômios.
     *
     * @param other O polinômio a ser multiplicado com o polinômio atual.
     * @return Um novo polinômio que representa o produto.
     */
    Polynomial operator*(const Polynomial &other) const;

    /**
     * @brief Adiciona outro polinômio ao polinômio atual.
     *
     * @param other O polinômio a ser adicionado.
     * @return Referência ao polinômio atual, atualizado após a soma.
     */
    Polynomial &operator+=(const Polynomial &other);

    /**
     * @brief Subtrai outro polinômio do polinômio atual.
     *
     * @param other O polinômio a ser subtraído.
     * @return Referência ao polinômio atual, atualizado após a subtração.
     */
    Polynomial &operator-=(const Polynomial &other);

    /**
     * @brief Multiplica o polinômio atual por outro polinômio.
     *
     * @param other O polinômio pelo qual o polinômio atual será multiplicado.
     * @return Referência ao polinômio atual, atualizado após a multiplicação.
     */
    Polynomial &operator*=(const Polynomial &other);

    /**
     * @brief Adiciona um nó (monômio) ao polinômio.
     *
     * @param coef O coeficiente do monômio.
     * @param exp O expoente do monômio.
     */
    void addMonomial(double coef, double exp);

    /**
     * @brief Remove um monômio do polinômio com base no expoente fornecido.
     *
     * @param exp O expoente do monômio a ser removido.
     */
    void removeMonomial(int exp);

    /**
     * @brief Obtém o grau do polinômio.
     *
     * @return O grau do polinômio (maior expoente).
     */
    int degree() const;

    /**
     * @brief Obtém o número de termos no polinômio.
     *
     * @return O número de termos do polinômio.
     */
    size_t size() const;

    /**
     * @brief Avalia o polinômio para um valor específico de x.
     *
     * @param x O valor de x para a avaliação.
     * @return O valor resultante da avaliação do polinômio.
     */
    double evaluate(double x) const;

    /**
     * @brief Converte uma linha em um polinômio.
     *
     * Converte uma linha em polinômio por pares de valores.
     * A linha "3 4 5 6" torna-se um polinômio com nós (3, 4)
     * e (5, 6).
     *
     * @param line A linha que deve ser convertida.
     * @return Um novo polinômio que representa a linha.
     */
    static Polynomial parser(std::string line);

    /**
     * @brief Sobrecarga do operador de saída para exibir o polinômio.
     *
     * @param os O fluxo de saída.
     * @param Polynomial O polinômio a ser exibido.
     * @return O fluxo de saída atualizado.
     */
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &Polynomial);

    /**
     * @brief Converte o polinômio em uma representação de string.
     *
     * @return Uma string representando o polinômio.
     */
    std::string toString() const;
};

#endif