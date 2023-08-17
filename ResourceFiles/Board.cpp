#include "../Headerfiles/Board.hpp"

void Board::SetBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      board[i][j].SetTileValue(" ");
    }
  }
}

void Board::PrintBoard() {
  std::cout << std::endl << "********** GAME BOARD **********" << std::endl;
  std::cout << "Column:  1  2  3  4  5  6  7  " << std::endl;
  std::cout << "------------------------------" << std::endl;
  for (int i = 0; i < rows; i++) {
    std::cout << "        |";
    for (int j = 0; j < columns; j++) {
      std::cout << board[i][j].GetTileValue() << " |";
    }
    std::cout << std::endl << "        ----------------------" << std::endl;
  }
  std::cout << std::endl << "------------------------------" << std::endl;
}

bool Board::UpdateGrid(int columnNumber, std::string value, int &rowNumber) {
  for (int i = 5; i >= 0; i--) {
    if (columnNumber >= 0 && columnNumber <= 6 &&
        board[i][columnNumber].GetTileValue() == " ") {
      rowNumber = i;
      if (value == "R") {
        board[i][columnNumber].SetTileValue(RED_TEXT + value + DEFAULT_COLOR);
      } else {
        board[i][columnNumber].SetTileValue(BLUE_TEXT + value + DEFAULT_COLOR);
      }
      return true;
    }
  }
  return false;
}

bool Board::HorizontalCheck(int row, int column)
{
  int counter = 1;
  for (int i = 1; i < columns; i++)
  {
    if (board[row][i].GetTileValue() != " " && board[row][i].GetTileValue() == board[row][i - 1].GetTileValue())
    {
      counter += 1;
      if (counter == 4)
      {
        return true;
      }
    }
    else
    {
      counter = 1;
    }
  }
  return false;
}

bool Board::VerticalCheck(int row, int column)
{
  int counter = 1;
  for (int i = 1; i < rows; i++)
  {
    if (board[i][column].GetTileValue() != " " && board[i][column].GetTileValue() == board[i - 1][column].GetTileValue())
    {
      counter += 1;
      if (counter == 4)
      {
        return true;
      }
    }
    else
    {
      counter = 1;
    }
  }
  return false;
}