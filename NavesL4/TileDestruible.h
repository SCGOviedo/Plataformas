#pragma once
#include "Tile.h"
class TileDestruible : public Tile
{
public:
	TileDestruible(string filename, float x, float y, Game* game);
	int destroy = 0;
	int duracion = 50;
};

