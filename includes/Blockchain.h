/*
 * Blockchain.h
 *
 *  Created on: Apr 10, 2018
 *      Author: le0nx
 */

#ifndef INCLUDES_BLOCKCHAIN_H_
#define INCLUDES_BLOCKCHAIN_H_

#include "Block.h"
#include <vector>
#include <memory>

class BlockChain {
public:
	BlockChain();

	void addBlock(const uint64_t& data);


private:
	std::vector <Block*> _blockchain;
};



#endif /* INCLUDES_BLOCKCHAIN_H_ */
