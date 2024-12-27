# TrappedMouse

O programa lê um labirinto a partir de um arquivo de texto, e tenta encontrar o caminho da entrada (m) até a saída (e) utilizando uma abordagem de backtracking.

O labirinto é representado por uma matriz onde:

- `1` representa uma parede;
- `0` representa um caminho livre;
- `m` é a entrada;
- `e` é a saída.

A solução é realizada utilizando uma pilha (stack), onde a exploração do labirinto é feita por tentativa e erro, movendo-se para células adjacentes até encontrar a saída ou até esgotar todas as possibilidades. O programa exibirá o labirinto a cada passo e indicará,
ao final, se encontrou ou não uma solução.

## Formato do Arquivo de Entrada:

O arquivo de entrada deve ser estruturado da seguinte forma:

```bash
5 5
1 1 1 1 1
1 m 0 0 1
1 0 1 0 1
1 0 1 0 1
1 1 1 e 1
```

- A primeira linha contém dois números inteiros: o número de linhas e o número de colunas do labirinto.
- As linhas seguintes constroem o labirinto.

## Como Compilar e Executar

1. Compile e execute o projeto:

   ```bash
   make run
   ```