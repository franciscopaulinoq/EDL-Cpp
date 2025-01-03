# Estruturas de Dados em C++

Este repositório contém projetos em C++ relacionados a estruturas de dados lineares.

## Estrutura dos Projetos

Cada projeto segue a seguinte estrutura de diretórios:

- **include/**: Contém os arquivos de cabeçalho (.h).
- **source/**: Contém os arquivos de código-fonte (.cpp).
- **resources/**: Contém arquivos auxiliares, como entradas e saídas de dados.
- **objects/**: Contém os arquivos gerados durante a compilação.
- **Makefile**: Script para compilar o projeto.

## Projetos Disponíveis

1. [LinkedList](./LinkedList/README.md)
2. [Polynomial](./Polynomial/README.md)
3. [HashTable](./HashTable/README.md)
4. [ChallengeCollatz](./ChallengeCollatz/README.md)
5. [TrappedMouse](./TrappedMouse/README.md)

## Como Usar

1. Entre na pasta do projeto desejado:
   ```bash
   cd NomeDoProjeto
   ```

2. Compile e execute o projeto usando o Makefile:
    ```bash
    make run
    ```
3. Execute o projeto com a opção -C:  

   Se você não quiser entrar na pasta do projeto, pode usar a opção -C do make, que permite especificar o diretório onde o Makefile está localizado. Por exemplo:

   ```bash
    make -C NomeDoProjeto run
    ```


## Compatibilidade do Makefile

O Makefile está configurado para sistemas Windows. Para que funcione no Linux/Mac, faça as seguintes alterações:

- Na variável `TARGET` retire o sufixo ".exe"

- Substitua:

   @if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
   por:
   @mkdir -p "$(OBJ_DIR)"

   if not exist "$(@D)" mkdir "$(@D)"
   por:
   @mkdir -p "$(@D)"

- Ajuste o target `clean` para usar os comandos `rm`:

  ```bash
  clean:
	-@rm -rvf "$(OBJ_DIR)"
	-@rm -vf "$(TARGET)"
   ```