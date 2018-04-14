//============================================================================
// Name        : main.cpp
// Author      : Denis Nefedov
// Version     : 0.01
// Copyright   : LGPL
// Description : main source file.
//============================================================================

#include "Block.h"
#include "Blockchain.h"
#include "httpServer.h"
#include <iostream>
int main(void) {
	//Dataset 1
	std::string x = "data";
	std::vector<std::string> data;
	data.push_back(x);


	Block* second = Block::mineBlock(Block::genesis(),data);
	second->info();

	//DEBUG INFO for JSON
//	json j = second->toJSON();
//	std::cout << j << std::endl;

	BlockChain* chain = new BlockChain(); 	//валидная цепь

	chain->addBlock(data);
	chain->addBlock(data);

//	//Подменяем данные в блоке. Проверяем работу метода isValidChain, который проверяет всю цепь.
//	chain->_blockchain[1]->_data[0] = "wn";
//	std::cout << chain->isValidChain(chain->get_chain());

	return 0;
}
