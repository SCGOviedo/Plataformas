#include "Door.h"

Door::Door(float x, float y, Game* game, int who)
	: Actor("res/copa.png", x, y, 40, 32, game) {
	number = who;
}

void Door::update(){
	if (cooldown == 0) {
		tp = true;
	}
	else {
		tp = false;
		cooldown--;
	}
}
