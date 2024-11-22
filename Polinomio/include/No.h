#ifndef NO_H
#define NO_H

class No
{
public:
    double coeficiente;
    int expoente;
    No *proximo;

    /**
     * @brief Construtor para a classe Node.
     *
     * Inicializa um nó com o coeficiente e expoente fornecidos e define o ponteiro para o próximo nó como nullptr.
     *
     * @param coef O coeficiente do nó.
     * @param exp O expoente do nó.
     */
    No(double coef, int exp);
};

#endif