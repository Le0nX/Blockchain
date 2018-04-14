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

std::vector <Block*> BlockChain::get_chain() const {
	return _blockchain;
}

bool BlockChain::isValidChain(const std::vector <Block*> &chain) {
	// если первый элемент цепи не совпадает с нашим генезис блоком, то вся цепь - лажа.
	if (chain[0]->toJSON() != Block::genesis()->toJSON()) return false;

	for (uint64_t i=1; i < chain.size(); i++) {
		const Block* temp 	   = chain[i];   // Текущий блок
		const Block* lastBlock = chain[i-1]; // Предыдущий блок

		//Сверяем last_hash поле с хешем предыдущего блока + сверяем свой хеш с вновь вычесленной хешфункцией
		if ((lastBlock->get_hash() != temp->get_last_hash()) ||
				(temp->get_hash() != Block::generateHash(temp))) {
			return false;
		}
	}

	return true;
}
