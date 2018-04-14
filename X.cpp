//============================================================================
// Name        : main.cpp
// Author      : Denis Nefedov
// Version     : 0.01
// Copyright   : LGPL
// Description : main source file.
//============================================================================

#include "Block.h"
#include "httpServer.h"
#include <iostream>
int main(void) {
	std::string x = "data";
	std::vector<std::string> data;
	data.push_back(x);


	Block* second = Block::mineBlock(Block::genesis(),data);
	second->info();

	//DEBUG INFO for JSON
	json j = second->toJSON();
	std::cout << j << std::endl;

	return 0;
}
