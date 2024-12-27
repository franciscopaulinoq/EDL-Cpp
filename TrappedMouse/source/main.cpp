#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <windows.h>
#include "Cell.h"
#include "Stack.h"

using namespace std;

bool isValidMove(int line, int col, char **matrix)
{
    return matrix[line][col] == '0' || matrix[line][col] == 'e';
}

void printMaze(char **matrix, int line, int col)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < col; j++)
        {
            switch (matrix[i][j])
            {
            case '1':
                cout << "# ";
                break;
            case 'm':
                cout << "\033[1;32mM\033[0m ";
                break;
            case 'e':
                cout << "\033[1;33mE\033[0m ";
                break;
            default:
                cout << "  ";
                break;
            }
        }
        cout << "\n";
    }
}

void clearScreen()
{
    COORD cursorPosition = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void movePlayer(char **matrix, Cell &currentCell, Stack<Cell> &cellStack)
{
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto &dir : directions)
    {
        int newLine = currentCell.getX() + dir[0];
        int newCol = currentCell.getY() + dir[1];
        if (isValidMove(newLine, newCol, matrix))
        {
            cellStack.emplace(newLine, newCol);
        }
    }
}

bool loadMaze(const string &filename, char **&matrix, int &line, int &col, Cell &start, Cell &exit)
{
    ifstream arquivo(filename);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de entrada.\n";
        return false;
    }

    string linha;
    getline(arquivo, linha);
    stringstream ss(linha);
    ss >> line >> col;

    matrix = new char *[line];
    for (int i = 0; i < line; i++)
    {
        matrix[i] = new char[col];
    }

    for (int i = 0; i < line; i++)
    {
        getline(arquivo, linha);
        stringstream ss(linha);
        for (int j = 0; j < col; j++)
        {
            char valor;
            ss >> valor;

            if (valor != '0' && valor != '1' && valor != 'm' && valor != 'e')
            {
                cerr << "Invalid value found: " << valor << " at position (" << i << ", " << j << ")\n";
                return false;
            }

            if (valor == 'm')
            {
                start = Cell(i, j);
            }
            else if (valor == 'e')
            {
                exit = Cell(i, j);
            }
            matrix[i][j] = valor;
        }
    }
    return true;
}

int main()
{
    char **matrix;
    int line, col;
    Cell currentCell, exitCell;

    if (!loadMaze("resources/input.txt", matrix, line, col, currentCell, exitCell))
    {
        return 1;
    }

    Stack<Cell> cellStack;
    cellStack.push(currentCell);

    system("cls");
    ShowConsoleCursor(false);
    printMaze(matrix, line, col);

    while (!(currentCell == exitCell) && !cellStack.empty())
    {
        movePlayer(matrix, currentCell, cellStack);

        matrix[currentCell.getX()][currentCell.getY()] = '.';
        currentCell = cellStack.top();
        cellStack.pop();
        matrix[currentCell.getX()][currentCell.getY()] = 'm';

        clearScreen();
        printMaze(matrix, line, col);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    if (currentCell == exitCell)
    {
        cout << "\033[1;32m\nSAIDA ENCONTRADA!\033[0m" << endl;
    }
    else
    {
        cout << "\033[1;31m\nNAO HA SAIDA POSSIVEL!\033[0m" << endl;
    }

    for (int i = 0; i < line; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}