#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    /**
     * @brief Construtor da classe Node.
     *
     * @param coef O coeficiente.
     * @param exp O expoente.
     */
    Node(int coef, int exp);
};

#endif