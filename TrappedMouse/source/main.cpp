#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

struct Person
{
    string name;
    int age;

    Person(const string &n, int a) : name(n), age(a) {}
};

int main()
{
    Stack<double> pilhaD;

    pilhaD.push(10.4);
    pilhaD.push(20.2);
    pilhaD.push(30.5);

    cout << "Tamanho apos insercoes: " << pilhaD.size() << endl;
    cout << "Topo da pilha de doubles: " << pilhaD.top() << endl;

    pilhaD.pop();
    cout << "Tamanho apos pop: " << pilhaD.size() << endl;
    cout << "Topo apos pop: " << pilhaD.top() << endl;

    pilhaD.pop();
    pilhaD.pop();

    cout << "Tamanho apos remocoes: " << pilhaD.size() << endl;

    try
    {
        pilhaD.pop();
    }
    catch (const exception &e)
    {
        cout << "Erro: " << e.what() << endl;
    }

    pilhaD.emplace(40.7);
    pilhaD.emplace(50.1);

    cout << "Tamanho apos emplace: " << pilhaD.size() << endl;
    cout << "Topo apos emplace: " << pilhaD.top() << endl;

    Stack<double> pilhaTemp;
    pilhaTemp.push(60.9);
    pilhaTemp.push(70.3);
    pilhaTemp.push(80.7);

    cout << "\nAntes do swap:" << endl;
    cout << "Pilha original - Topo: " << pilhaD.top() << ", Tamanho: " << pilhaD.size() << endl;
    cout << "Pilha temporaria - Topo: " << pilhaTemp.top() << ", Tamanho: " << pilhaTemp.size() << endl;

    pilhaD.swap(pilhaTemp);

    cout << "\nApos o swap:" << endl;
    cout << "Pilha original - Topo: " << pilhaD.top() << ", Tamanho: " << pilhaD.size() << endl;
    cout << "Pilha temporaria - Topo: " << pilhaTemp.top() << ", Tamanho: " << pilhaTemp.size() << endl;

    Stack<Person> pilhaP;

    pilhaP.emplace("John Doe", 30);
    pilhaP.emplace("Jane Smith", 25);

    cout << endl;

    cout << "Tamanho apos emplace: " << pilhaP.size() << endl;
    cout << "Topo da pilha - Nome: " << pilhaP.top().name << ", Idade: " << pilhaP.top().age << endl;

    pilhaP.pop();
    cout << "Tamanho apos pop: " << pilhaP.size() << endl;
    cout << "Topo apos pop - Nome: " << pilhaP.top().name << ", Idade: " << pilhaP.top().age << endl;

    // ifstream arquivo("resources/input.txt");
    // if (!arquivo.is_open())
    // {
    //     cerr << "Erro ao abrir o arquvio de entrada.\n";
    //     return 1;
    // }

    // string linha;
    // int line, col;

    // while (getline(arquivo, linha))
    // {
    //     stringstream ss(linha);
    //     ss >> line >> col;
    // }

    // char **matrix = (char **)malloc(line * sizeof(char *));
    // if (matrix == NULL)
    // {
    //     perror("Erro ao alocar memoria para as linhas");
    //     return EXIT_FAILURE;
    // }

    // for (int i = 0; i < line; i++)
    // {
    //     matrix[i] = (char *)malloc(col * sizeof(char));
    //     if (matrix[i] == NULL)
    //     {
    //         perror("Erro ao alocar memoria para uma coluna");
    //         for (int j = 0; j < i; j++)
    //         {
    //             free(matrix[i]);
    //         }
    //         free(matrix);
    //         return EXIT_FAILURE;
    //     }
    // }

    // for (int i = 0; i < line; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         matrix[i][j] = '#';
    //     }
    // }

    // for (int i = 0; i < line; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // free(matrix);

    return 0;
}