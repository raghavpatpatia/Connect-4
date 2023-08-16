#include "../Headerfiles/Tile.hpp"

Tile::Tile()
{
    this->tileValue = " ";
}

void Tile::SetTileValue(string value)
{
    this->tileValue = value;
}

string Tile::GetTileValue()
{
    return tileValue;
}