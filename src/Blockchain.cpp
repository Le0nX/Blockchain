/*
 * Blockchain.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: le0nx
 */

#include "Block.h"
#include "Blockchain.h"

BlockChain::BlockChain() {
	/// Создаем первый генезис-блок и кладем его в цепь.
	_blockchain.push_back(Block::genesis());
}

void BlockChain::addBlock(const std::vector<std::string>& data) {
	_blockchain.push_back(Block::mineBlock(this->_blockchain[_blockchain.size()-1], data));
}

bool BlockChain::isValidChain(const BlockChain& chain) {
	(void) chain;
	return true;
}
