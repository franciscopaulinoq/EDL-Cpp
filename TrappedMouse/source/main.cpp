#include <iostream>
#include <windows.h>
#include "Maze.h"

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
    Maze maze;

    if (!maze.loadFromFile("resources/input.txt"))
    {
        return 1;
    }

    ShowConsoleCursor(false);
    system("cls");

    maze.exitMaze();

    return 0;
}