#pragma once
#include "zlib.h"


class Ship {
public:
	Vec dir;
	Vec pos;
	Vec vel;
	float angle;
	float color[3];
public:
	Ship();
};
