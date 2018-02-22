#pragma once
#include "zlib.h"

class Game {
public:
	Ship ship;
	Bullet *barr;
	int nasteroids;
	int nbullets;
	struct timespec bulletTimer;
	struct timespec mouseThrustTimer;
	bool mouseThrustOn;
public:
	Game();
	~Game();
} g;
