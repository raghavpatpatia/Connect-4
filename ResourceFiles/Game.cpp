#include "../HeaderFiles/Game.hpp"

void Game::WrongInput()
{
    std::cout << "*------------------------------------------*\n"
              << "|                                          |\n"
              << "|             WRONG INPUT...               |\n"
              << "|              TRY AGAIN                   |\n"
              << "|                                          |\n"
              << "*------------------------------------------*\n";
}

void Game::GameRules()
{
    std::cout << "*---------------------------------------------------------------------------------------*\n"
              << "|                                                                                       |\n"
              << "|                              WELCOME TO CONNECT-4 GAME                                |\n"
              << "|                                                                                       |\n"
              << "*---------------------------------------------------------------------------------------*\n"
              << "|                                                                                       |\n"
              << "|                                      RULES:                                           |\n"
              << "|                                                                                       |\n"
              << "| 1. Two-Player (Red-R & Blue-B) game.                                                  |\n"
              << "| 2. Board size (6 Rows X 7 Columns).                                                   |\n"
              << "| 3. A Player wins if manages to connect 4 dots Horizontally, Vertically or Diagonally. |\n"
              << "| 4. Draw when board is fully filled.                                                   |\n"
              << "|                                                                                       |\n"
              << "*---------------------------------------------------------------------------------------*\n"
              << "|                                                                                       |\n"
              << "|                                   HOW TO PLAY:                                        |\n"
              << "|                                                                                       |\n"
              << "| 1. Game starts with Red Player.                                                       |\n"
              << "| 2. In each step, choose column to drop ball.                                          |\n"
              << "| 3. Rows will be filled from bottom to top in any column.                              |\n"
              << "|                                                                                       |\n"
              << "*---------------------------------------------------------------------------------------*\n";
    
    board.PrintBoard();
}

void Game::GameStatus(int rows, int columns)
{
    if (tilesLeft == 0)
    {
        isGameDraw = true;
        isGameOver = true;
    }
    else
    {
        isGameOver = board.HorizontalCheck(rows, columns) || board.VerticalCheck(rows, columns) || board.DiagonalCheck(rows, columns);
    }
}

void Game::PlayerInput(Player currentPlayer)
{
    int column, row = -1;
    std::string currentValue = " ";
    bool isInputCorrect = false;
    while (!isInputCorrect)
    {
        std::cout << "\n*-------------------- INPUT --------------------*\n";
        std::cout << "Player " << static_cast<int>(currentPlayer) + 1 << " (" << (currentPlayer == Player::Player1 ? "R" : "B") << ") - Enter column (1-7): ";
        std::cin >> column;
        if (column >= 1 && column <= 7)
        {
            column--;
            isInputCorrect = true;
            currentValue = currentPlayer == Player::Player1 ? "R" : "B";
            for (int i = 6 - 1; i >= 0; i--)
            {
                if (board.UpdateGrid(column, currentValue, i))
                {
                    row = i;
                    break;
                }
            }
        }
        else
        {
            WrongInput();
        }
    }
    tilesLeft -= 1;
    GameStatus(row, column);
}

void Game::Play()
{
    GameRules();
    while (!isGameOver)
    {
        PlayerInput(currentPlayer);
        board.PrintBoard();
        if (currentPlayer == Player::Player1){ currentPlayer = Player::Player2; }
        else { currentPlayer = Player::Player1; }
    }
    PlayerWon();
}

void Game::PlayerWon()
{
    std::string winner = currentPlayer == Player::Player1 ? "PLAYER 2 (B) WINS!" : "PLAYER 1 (R) WINS!";
    winner = isGameDraw ? "IT'S A DRAW!!" : winner;
    std::cout << "\n*-------------------- GAME OVER --------------------*";
    std::cout << std::endl << winner << std::endl;
    std::cout << "*---------------------------------------------------------------------------------------*\n"
              << "|                                                                                       |\n"
              << "|                        THANK YOU FOR PLAYING CONNECT-4 GAME                           |\n"
              << "|                                                                                       |\n"
              << "*---------------------------------------------------------------------------------------*\n";
}

void Game::ResetGame()
{
    board.SetBoard();
    isGameDraw = false;
    isGameOver = false;
    tilesLeft = 42;
    currentPlayer = Player::Player1;
}

Game::Game()
{
    ResetGame();
    Play();
}