# Polinomio

Este projeto implementa uma estrutura para manipulação de polinômios em C++ com base no conceito de lista encadeada. Ele suporta operações matemáticas, como soma, subtração e multiplicação, além de avaliar o polinômio para valores específicos. A entrada de dados ocorre por meio de um arquivo `.txt`.

## Como Compilar e Executar

1. Compile e execute o projeto:
   ```bash
   make run
   ```

## Formato do Arquivo de Entrada:

O arquivo de entrada deve ser estruturado da seguinte forma:

1. **Operação**
   - Cada linha deve conter uma operação seguida pelos polinômios necessários para a operação.
   - As operações válidas são:
     - `+`: Adição de polinômios
     - `-`: Subtração de polinômios
     - `*`: Multiplicação de polinômios
     - `g` ou `G`: Para calcular o grau do polinômio
     - `t` ou `T`: Para calcular o número de termos do polinômio
     - `a` ou `A`: Para avaliar o polinômio em um valor específico de `x`
     - `p` ou `P`: Para exibir o polinômio

2. **Polinômios**
   - Os polinômios devem ser inseridos nas linhas seguintes à operação.
   - Um polinômio deve ser representado na seguinte forma (os expoentes devem ser inteiros positivos), por exemplo:

     - `x^2 + 2x + 1` deve ser `1 2 2 1 1 0`
     - `x^3 - x + 5` deve ser `1 3 -1 1 5 0`

3. **Valor de x** (somente para a operação de avaliação)
   - Para a operação de avaliação (`a` ou `A`), o valor de `x` deve ser fornecido antes do polinômio.
   - O valor de `x` pode ser um número real, por exemplo: `2.5`.

## Exemplo de Arquivo de Entrada:

```bash
p
1 2 2 1 1 0
p
1 3 -1 1 5 0
+
1 2 2 1 1 0
1 3 -1 1 5 0
-
1 2 2 1 1 0
1 3 -1 1 5 0
*
1 2 2 1 1 0
1 3 -1 1 5 0
g
1 2 2 1 1 0
t
1 2 2 1 1 0
a
2.5
1 2 2 1 1 0
```

Saída:

```bash
Polinomio: 1x^2 + 2x + 1
Polinomio: 1x^3 - 1x + 5
Soma: 1x^3 + 1x^2 + 1x + 6
Substracao:  - 1x^3 + 1x^2 + 3x - 4
Multiplicacao: 1x^5 + 2x^4 + 3x^2 + 9x + 5
Grau do polinomio: 2
Termos do polinomio: 3
Avaliacao do polinomio com x = 2.5: 12.25
```