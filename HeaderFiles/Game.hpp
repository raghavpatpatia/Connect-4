#pragma once
#include "Board.hpp"

class Game
{
private:
    Board board;
    bool isGameOver, isGameDraw;
    int tilesLeft;
    Player currentPlayer;
    void WrongInput();
    void GameRules();
    void GameStatus(int rows, int columns);
    void PlayerInput(Player currentPlayer);
    void Play();
    void PlayerWon();
    void ResetGame();
public:
    Game();
};