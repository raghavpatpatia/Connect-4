#include "../Headerfiles/Board.hpp"

void Board::SetBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      board[i][j].SetTileValue(" ");
    }
  }
}

void Board::PrintBoard() {
  cout << endl << "********** GAME BOARD **********" << endl;
  cout << "Column:  1  2  3  4  5  6  7  " << endl;
  cout << "------------------------------" << endl;
  for (int i = 0; i < rows; i++) {
    cout << "        |";
    for (int j = 0; j < columns; j++) {
      cout << board[i][j].GetTileValue() << " |";
    }
    cout << endl << "        ----------------------" << endl;
  }
  cout << endl << "------------------------------" << endl;
}

bool Board::UpdateGrid(int columnNumber, string value, int &rowNumber) {
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
