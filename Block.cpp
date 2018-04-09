/*
 * Block.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: le0nx
 */

#include "Block.h"
#include <iostream>

void Block::info() const {
	std::cout << "Timestamp: " << this->_timestamp << std::endl;
	std::cout << "Last Hash: " << this->_last_hash << std::endl;
	std::cout << "Hash     : " << this->_hash 	   << std::endl;
	std::cout << "Data     : " << this->_data	   << std::endl;

}


