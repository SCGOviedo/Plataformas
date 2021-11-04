#pragma once
#include "Actor.h"
class Door : public Actor
{public:
	Door(float x, float y, Game* game, int who);
	void update();
	int number;
	int cooldown = 0;
	bool tp = true;
};

