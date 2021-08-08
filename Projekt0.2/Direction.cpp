#pragma once
#include "Direction.h"

Direction randDir() {
	Direction randomDirection = Direction(rand()%4);
	return randomDirection;
}