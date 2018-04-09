/*
 * Block.h
 *
 *  Created on: Apr 9, 2018
 *  Author: Denis Nefedov
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <ctime>
#include <string>
#include <stdint.h>

class Block{
public:
		Block(time_t timestamp, uint64_t data, std::string hash, std::string last_hash):
			_timestamp(timestamp), _data(data), _hash(hash), _last_hash(last_hash) {}

		void info() const;

		static Block* genesis();
private:
		time_t 			_timestamp;
		uint64_t 		_data;
		std::string 	_hash;
		std::string 	_last_hash;
};



#endif /* BLOCK_H_ */
