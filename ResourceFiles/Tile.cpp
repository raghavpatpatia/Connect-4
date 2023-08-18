#include "../HeaderFiles/Tile.hpp"

Tile::Tile()
{
    this->tileValue = " ";
}

void Tile::SetTileValue(std::string value)
{
    this->tileValue = value;
}

std::string Tile::GetTileValue()
{
    return tileValue;
}