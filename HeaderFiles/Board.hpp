#pragma once
#include "Tile.hpp"
#define RED_TEXT "\033[31m"
#define BLUE_TEXT "\033[34m"
#define DEFAULT_COLOR "\033[0m"

class Board
{
private:
    static const int rows = 6;
    static const int columns = 7;
    Tile board[rows][columns];
public:
    void SetBoard();
    void PrintBoard();
    bool UpdateGrid(int columnNumber, std::string value, int& rowNumber);
    bool HorizontalCheck(int row, int column);
    bool VerticalCheck(int row, int column);
    bool DiagonalCheck(int row, int column);
};