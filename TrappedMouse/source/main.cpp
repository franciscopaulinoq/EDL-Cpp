#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <windows.h>
#include <chrono>
#include <vector>
#include "Stack.h"

using namespace std;

struct Person
{
    string name;
    int age;

    Person(const string &n, int a) : name(n), age(a) {}
};

struct Cell
{
    int line;
    int col;

    Cell() : line(0), col(0) {}
    Cell(int l, int c) : line(l), col(c) {}
};

bool temDireita(Cell currentCell, char **mat) {
    return mat[currentCell.line][currentCell.col + 1] == '0' || mat[currentCell.line][currentCell.col + 1] == 'e';
}

bool temEsquerda(Cell currentCell, char **mat) {
    return mat[currentCell.line][currentCell.col - 1] == '0' || mat[currentCell.line][currentCell.col - 1] == 'e';
}

bool temAcima(Cell currentCell, char **mat) {
    return mat[currentCell.line - 1][currentCell.col] == '0' || mat[currentCell.line - 1][currentCell.col] == 'e';
}

bool temAbaixo(Cell currentCell, char **mat) {
    return mat[currentCell.line + 1][currentCell.col] == '0' || mat[currentCell.line + 1][currentCell.col] == 'e';
}

void printMaze(char** matrix, int line, int col) {
    string test = "";
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '1')
            {   
                test = test + "# ";
                // cout << "#" << " ";
            }
            else if (matrix[i][j] == '0')
            {
                test = test + "  ";
                // cout << " " << " ";
            }
            else if (matrix[i][j] == '.') {
                test = test + "  ";
            }
            else
            {
                test = test + matrix[i][j] + " ";
                // cout << matrix[i][j] << " ";
            }
        }
        test = test + "\n";
        // cout << endl;
    }
    cout << test;
}

void ClearScreen()
{	
COORD cursorPosition;	
cursorPosition.X = 0;	
cursorPosition.Y = 0;	
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int main()
{
    // Stack<double> pilhaD;

    // pilhaD.push(10.4);
    // pilhaD.push(20.2);
    // pilhaD.push(30.5);

    // cout << "Tamanho apos insercoes: " << pilhaD.size() << endl;
    // cout << "Topo da pilha de doubles: " << pilhaD.top() << endl;

    // pilhaD.pop();
    // cout << "Tamanho apos pop: " << pilhaD.size() << endl;
    // cout << "Topo apos pop: " << pilhaD.top() << endl;

    // pilhaD.pop();
    // pilhaD.pop();

    // cout << "Tamanho apos remocoes: " << pilhaD.size() << endl;

    // try
    // {
    //     pilhaD.pop();
    // }
    // catch (const exception &e)
    // {
    //     cout << "Erro: " << e.what() << endl;
    // }

    // pilhaD.emplace(40.7);
    // pilhaD.emplace(50.1);

    // cout << "Tamanho apos emplace: " << pilhaD.size() << endl;
    // cout << "Topo apos emplace: " << pilhaD.top() << endl;

    // Stack<double> pilhaTemp;
    // pilhaTemp.push(60.9);
    // pilhaTemp.push(70.3);
    // pilhaTemp.push(80.7);

    // cout << "\nAntes do swap:" << endl;
    // cout << "Pilha original - Topo: " << pilhaD.top() << ", Tamanho: " << pilhaD.size() << endl;
    // cout << "Pilha temporaria - Topo: " << pilhaTemp.top() << ", Tamanho: " << pilhaTemp.size() << endl;

    // pilhaD.swap(pilhaTemp);

    // cout << "\nApos o swap:" << endl;
    // cout << "Pilha original - Topo: " << pilhaD.top() << ", Tamanho: " << pilhaD.size() << endl;
    // cout << "Pilha temporaria - Topo: " << pilhaTemp.top() << ", Tamanho: " << pilhaTemp.size() << endl;

    // Stack<Person> pilhaP;

    // pilhaP.emplace("John Doe", 30);
    // pilhaP.emplace("Jane Smith", 25);

    // cout << endl;

    // cout << "Tamanho apos emplace: " << pilhaP.size() << endl;
    // cout << "Topo da pilha - Nome: " << pilhaP.top().name << ", Idade: " << pilhaP.top().age << endl;

    // pilhaP.pop();
    // cout << "Tamanho apos pop: " << pilhaP.size() << endl;
    // cout << "Topo apos pop - Nome: " << pilhaP.top().name << ", Idade: " << pilhaP.top().age << endl;

    system("cls");

    ifstream arquivo("resources/input.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquvio de entrada.\n";
        return 1;
    }

    string linha;
    int line, col;

    getline(arquivo, linha);

    stringstream ss(linha);
    ss >> line >> col;

    char **matrix = (char **)malloc(line * sizeof(char *));
    if (matrix == NULL)
    {
        perror("Erro ao alocar memoria para as linhas");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < line; i++)
    {
        matrix[i] = (char *)malloc(col * sizeof(char));
        if (matrix[i] == NULL)
        {
            perror("Erro ao alocar memoria para uma coluna");
            for (int j = 0; j < i; j++)
            {
                free(matrix[i]);
            }
            free(matrix);
            return EXIT_FAILURE;
        }
    }

    char valor;
    Cell currentCell;
    Cell exitCell;

    for (int i = 0; i < line; i++)
    {
        getline(arquivo, linha);
        stringstream ss(linha);
        for (int j = 0; j < col; j++)
        {
            ss >> valor;
            if (valor == 'm')
            {
                currentCell.line = i;
                currentCell.col = j;
            }
            else if (valor == 'e')
            {
                exitCell.line = i;
                exitCell.col = j;
            }
            matrix[i][j] = valor;
        }
    }

    Stack<Cell> testPilha;

    ClearScreen();
    printMaze(matrix, line, col);
    this_thread::sleep_for(std::chrono::milliseconds(500));

    while ((!(currentCell.line == exitCell.line) || !(currentCell.col == exitCell.col)))
    {
        if (temAbaixo(currentCell, matrix)) {
            testPilha.emplace(currentCell.line + 1, currentCell.col);
        }

        if (temAcima(currentCell, matrix)) {
            testPilha.emplace(currentCell.line -1, currentCell.col);
        }

        if (temEsquerda(currentCell, matrix)) {
            testPilha.emplace(currentCell.line, currentCell.col - 1);
        }

        if (temDireita(currentCell, matrix)) {
            testPilha.emplace(currentCell.line, currentCell.col + 1);
        }

        // break;

        matrix[currentCell.line][currentCell.col] = '.';
        // cout << "Caminho: (" << testPilha.top().line << ", " << testPilha.top().col << ")" << endl;
        currentCell.line = testPilha.top().line;
        currentCell.col = testPilha.top().col;
        testPilha.pop();
        matrix[currentCell.line][currentCell.col] = 'm';

        ClearScreen();
        printMaze(matrix, line, col);
        this_thread::sleep_for(std::chrono::milliseconds(500));

    }

    // while (!testPilha.empty()) {
    //     cout << "Caminho: (" << testPilha.top().line << ", " << testPilha.top().col << ")" << endl;
    //     testPilha.pop();
    // }

    // cout << "Current position: (" << currentCell.line << ", " << currentCell.col << ")" << endl;

    free(matrix);

    return 0;
}