# HashTable

Este projeto visa encontrar pares de números que somam um valor alvo em uma lista de inteiros. Para isso, ele implementa uma estrutura de tabela hash com encadeamento em C++. Ele permite realizar operações básicas, como inserção, remoção, busca e verificação de existência de chaves.

## Estrutura do Projeto

- **Tabela Hash:** Implementada com vetores de listas para tratar colisões usando encadeamento.
- **Funções Suportadas:**
  - `insert(key, value)`: Insere um par chave-valor na tabela.
  - `remove(key)`: Remove a chave (e seu valor associado) da tabela.
  - `find(key)`: Retorna o valor associado a uma chave.
  - `contains(key)`: Verifica se uma chave existe na tabela.

## Como Compilar e Executar

1. Compile e execute o projeto:

   ```bash
   make run
   ```

## Entrada e Saída de Exemplo

### Entrada

```bash
int target = 8;
list<int> intList = {1, 2, 3, 4, 5, 6, 7, 4, 5, 9, -1};
```

### Saída

```bash
Pares que somam 8:
(-1, 9)
(1, 7)
(2, 6)
(3, 5)
(4, 4)
```