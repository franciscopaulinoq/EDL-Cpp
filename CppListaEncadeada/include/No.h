#ifndef NO_H
#define NO_H

class No
{
public:
    int coeficiente;
    int expoente;
    No *proximo;

    /**
     * @brief Construtor da classe No.
     * Inicializa o nó com o coeficiente e o expoente fornecidos.
     *
     * @param coef O coeficiente.
     * @param exp O expoente.
     */
    No(int coef, int exp);
};

#endif