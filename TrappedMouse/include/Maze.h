#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <windows.h>
#include "Cell.h"
#include "Stack.h"

class Maze
{
private:
    Cell currentCell, exitCell, entryCell;
    static constexpr char exitMarker = 'e', entryMarker = 'm', visited = '.', passage = '0', wall = '1';
    Stack<Cell> mazeStack;
    char **maze;
    int rows, cols;

    void printMaze() const;
    bool isValidMove(int line, int col) const;
    void clearScreen() const;

public:
    Maze();
    ~Maze();

    bool loadFromFile(const std::string &filename);

    void exitMaze();
};

Maze::Maze() : maze(nullptr), rows(0), cols(0) {}

Maze::~Maze()
{
    if (maze)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] maze[i];
        }
        delete[] maze;
    }
}

bool Maze::loadFromFile(const std::string &filename)
{
    std::ifstream arquivo(filename);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de entrada.\n";
        return false;
    }

    std::string linha;
    std::getline(arquivo, linha);
    std::stringstream ss(linha);
    ss >> rows >> cols;

    maze = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        maze[i] = new char[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        std::getline(arquivo, linha);
        std::stringstream ss(linha);
        for (int j = 0; j < cols; j++)
        {
            char valor;
            ss >> valor;

            if (valor != passage && valor != wall && valor != entryMarker && valor != exitMarker)
            {
                std::cerr << "Invalid value found: " << valor << " at position (" << i << ", " << j << ")\n";
                return false;
            }

            maze[i][j] = valor;

            if (valor == entryMarker)
            {
                entryCell = Cell(i, j);
            }
            else if (valor == exitMarker)
            {
                exitCell = Cell(i, j);
            }
        }
    }

    if (entryCell == Cell())
    {
        std::cerr << "Character 'm' not found in text file\n";
        return false;
    }

    if (exitCell == Cell())
    {
        std::cerr << "Character 'e' not found in text file\n";
        return false;
    }

    currentCell = entryCell;
    return true;
}

bool Maze::isValidMove(int line, int col) const
{
    return line >= 0 && line < rows && col >= 0 && col < cols &&
           (maze[line][col] == passage || maze[line][col] == exitMarker);
}

void Maze::clearScreen() const
{
    COORD cursorPosition = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Maze::printMaze() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            char c = maze[i][j];
            switch (c)
            {
            case wall:
                std::cout << "# ";
                break;
            case entryMarker:
                std::cout << "\033[1;32mM\033[0m ";
                break;
            case exitMarker:
                std::cout << "\033[1;33mE\033[0m ";
                break;
            case visited:
                std::cout << "  ";
                break;
            default:
                std::cout << "  ";
                break;
            }
        }
        std::cout << std::endl;
    }
}
void Maze::exitMaze()
{
    mazeStack.push(currentCell);

    while (!(currentCell == exitCell) && !mazeStack.empty())
    {
        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &dir : directions)
        {
            int newLine = currentCell.getX() + dir[0];
            int newCol = currentCell.getY() + dir[1];
            if (isValidMove(newLine, newCol))
            {
                mazeStack.emplace(newLine, newCol);
            }
        }

        maze[currentCell.getX()][currentCell.getY()] = visited;

        if (!mazeStack.empty())
        {
            currentCell = mazeStack.top();
            mazeStack.pop();
            maze[currentCell.getX()][currentCell.getY()] = entryMarker;
        }

        clearScreen();
        printMaze();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    if (currentCell == exitCell)
    {
        std::cout << "\nSAIDA ENCONTRADA!" << std::endl;
    }
    else
    {
        std::cout << "\nSEM SAIDA POSSIVEL!" << std::endl;
    }
}

#endif