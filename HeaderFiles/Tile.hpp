#pragma once
#include "Player.hpp"

class Tile {
private:
  std::string tileValue;

public:
  Tile();
  std::string GetTileValue();
  void SetTileValue(std::string value);
};