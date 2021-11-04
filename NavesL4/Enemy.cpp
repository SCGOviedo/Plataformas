#include "Enemy.h"

Enemy::Enemy(float x, float y, Game* game)
	: Actor("res/enemigo.png", x, y, 36, 40, game) {

	state = game->stateMoving;

	aDying = new Animation("res/enemigo_morir.png", width, height,
		280, 40, 6, 8, false, game);

	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, true, game);
	animation = aMoving;

	vx = 1;
	vxIntelligence = -1;
	vx = vxIntelligence;

}

void Enemy::update(float playerX) {
	// Actualizar la animaci�n
	bool endAnimation = animation->update();

	// Acabo la animaci�n, no sabemos cual
	if (endAnimation) {
		// Estaba muriendo
		if (state == game->stateDying) {
			state = game->stateDead;
		}
	}


	if (state == game->stateMoving) {
		animation = aMoving;
	}
	if (state == game->stateDying) {
		animation = aDying;
	}

	// Establecer velocidad
	if (state != game->stateDying) {
		// no est� muerto y busca al jugador
		if (x<playerX) {
			vx = 1;
		}
		else if (x > playerX) {
			vx = -1;
		}
		else {
			vx = 0;//si est� en la posici�n del jugador, para que no "parpade�"
		}
	}
	else {//muerto
		vx = 0;
	}



}

void Enemy::impacted() {
	if (state != game->stateDying) {
		state = game->stateDying;
	}
}


void Enemy::draw(float scrollX,float scrolly) {
	animation->draw(x - scrollX, y - scrolly);
}


