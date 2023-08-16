#pragma once
#include "Player.hpp"

class Tile {
private:
  string tileValue;

public:
  Tile();
  string GetTileValue();
  void SetTileValue(string value);
};