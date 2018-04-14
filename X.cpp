//============================================================================
// Name        : main.cpp
// Author      : Denis Nefedov
// Version     : 0.01
// Copyright   : LGPL
// Description : main source file.
//============================================================================

#include "Block.h"
#include "httpServer.h"

int main(void) {
	std::string x = "data";
	std::vector<std::string> data;
	data.push_back(x);


	Block* second = Block::mineBlock(Block::genesis(),data);
	second->info();
	return 0;
}
