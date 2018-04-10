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

	Block* second = Block::mineBlock(first,2);
	second->info();
	return 0;
}
