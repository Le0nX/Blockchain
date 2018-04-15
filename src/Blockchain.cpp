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

void BlockChain::replaceChain(const std::vector <Block*> &new_chain) {
	if (new_chain.size() <= _blockchain.size()) {
		return;//Записать в логи ошибку
	} else if (!isValidChain(new_chain)) {
		return; //запись в лог.
	}

	//Запись в лог, что заменяем цепь.
	_blockchain = new_chain;
}

std::string BlockChain::toJSON() {

	json j;
	j["length"] = this->_blockchain.size();
	for (size_t i = 0; i < this->_blockchain.size(); i++){
		j["Block"][i] = this->_blockchain[i]->toJSON();
	}
	return j.dump();
}

std::string BlockChain::JSON_of_last_block() const {
	return _blockchain.back()->toJSON();
}

