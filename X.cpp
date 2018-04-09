//============================================================================
// Name        : main.cpp
// Author      : Denis Nefedov
// Version     : 0.01
// Copyright   : LGPL
// Description : main source file.
//============================================================================

#include "Block.h"

int main(void) {

	Block* first = Block::genesis();
	first->info();

	Block second(0,0,"none","none");
	second.info();
	return 0;
}
