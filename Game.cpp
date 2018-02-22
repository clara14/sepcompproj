#include "Game.h"

Game::Game() {
	barr = new Bullet[MAX_BULLETS];
	nasteroids = 0;
	nbullets = 0;
	mouseThrustOn = false;
	clock_gettime(CLOCK_REALTIME, &bulletTimer);
}

Game::~Game() {
	delete [] barr;
}
