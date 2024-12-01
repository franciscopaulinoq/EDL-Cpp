#ifndef NODE_H
#define NODE_H

class Node
{
public:
    double coefficient;
    int exponent;
    Node *next;

    /**
     * @brief Construtor para a classe Node.
     *
     * @param coef O coeficiente do nó.
     * @param exp O expoente do nó.
     */
    Node(double coef, int exp);
};

#endif