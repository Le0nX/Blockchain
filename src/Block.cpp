/*
 * Block.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: le0nx
 */

#include "Block.h"
#include <iostream>
#include <time.h>
#include "sha256.h"


void Block::info() const {
	std::cout << "Timestamp: " << this->_timestamp 		<< std::endl;
	std::cout << "Last Hash: " << this->_last_hash 		<< std::endl;
	std::cout << "Hash     : " << this->_hash 	   		<< std::endl;
	std::cout << "Data     : " << print_data()			<< std::endl;

}

Block* Block::genesis() {
	time_t curr_time = time(&curr_time);
	const std::string prev_hash = "none";
	/* Рандомные данные для первого блока. */
	const std::string hash = "SS898--1-2asdf10234jasdfas-0i412-==faf";
	const std::vector<std::string> data;

	return new Block(curr_time,data,hash, prev_hash);
}

std::string Block::get_hash() const {
	return this->_hash;
}

std::string Block::get_last_hash() const {
	return _last_hash;
}

time_t Block::get_timestamp() const {
	return _timestamp;
}

Block* Block::mineBlock(const Block* lastBlock, std::vector<std::string> data) {
	time_t curr_time = time(&curr_time); // получаем текущее время
	const std::string prev_hash = lastBlock->get_hash();
	const std::string hash = Block::calcHash(curr_time, prev_hash, data);

	/* генерируем новый блок */
	return new Block(curr_time,data,hash, prev_hash);
}

std::string Block::generateHash(const Block* block) {
	return Block::calcHash(block->get_timestamp(),block->get_last_hash(), block->get_data());
}

std::vector<std::string> Block::get_data() const {
	return this->_data;
}

std::string Block::print_data() const {
	std::string temp;
	for (auto str : _data) {
		temp += str + ", ";
		std::cout << temp << std::endl;
	}
	return temp;
}

json Block::toJSON() {

	json j;
	j["hash"] = this->_hash;
	j["previousHash"] = this->_last_hash;
	j["time"] = this->_timestamp;
	j["data"] = this->_data;

	return j;
}


