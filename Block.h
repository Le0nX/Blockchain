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
#include "crypto/sha256.h"
#include <sstream>

class Block{
public:
		Block(time_t timestamp, uint64_t data, std::string hash, std::string last_hash):
			_timestamp(timestamp), _data(data), _hash(hash), _last_hash(last_hash) {}

		void info() const;

		static Block* genesis();

		static Block* mineBlock(const Block* lastBlock, uint64_t data);

		std::string get_hash() const;

private:

		inline static std::string calcHash(const time_t& time,
										   const std::string& prev_hash,
										   const uint64_t& data) {

				std::stringstream ss;
				ss << time << prev_hash << data;

				std::string result = ss.str();
				return sha256(result);

		}


		time_t 			_timestamp;
		uint64_t 		_data;
		std::string 	_hash;
		std::string 	_last_hash;
};



#endif /* BLOCK_H_ */
