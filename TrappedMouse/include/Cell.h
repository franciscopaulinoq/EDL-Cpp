#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int x;
    int y;

public:
    Cell();
    Cell(int x, int y);
    ~Cell();
    bool operator==(Cell const &other);
    int getX();
    int getY();
};

Cell::Cell() : x(0), y(0) {}

Cell::Cell(int x, int y) : x(x), y(y) {}

Cell::~Cell()
{
}

bool Cell::operator==(Cell const &other)
{
    return this->x == other.x && this->y == other.y;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

#endif