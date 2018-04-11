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
#include "sha256.h"
#include <sstream>
#include <memory>

/**
 * Класс блока сети.
 */
class Block{
public:
		/**
		 * Конструктор блока.
		 * \param[in] 	timestamp 	текущее время.(время генерации блока)
		 * \param[in] 	data 		Данные в блоке. Пока просто переменная, потом можно заменить на структуру.
		 * \param[in]	hash 		Хеш самого блока.
		 * \param[in]	last_hash	Хеш предыдущего блока.
		 */
		Block(time_t timestamp, uint64_t data, std::string hash, std::string last_hash):
			_timestamp(timestamp), _data(data), _hash(hash), _last_hash(last_hash) {}

		/**
		 * Метод класса Block. Выводит всю информацию о блоке.
		 */
		void info() const;

		/**
		 * Статический метод генерации первого блока сети.
		 */
		static Block* genesis();

		/**
		 * Статическйи метод майнинга нового блока.
		 * \param[in]	lastBlock	Указатель на предыдущий блока
		 * \param[in]	data		Данные для нового блока
		 */
		static Block* mineBlock(const Block* lastBlock, uint64_t data);

		/**
		 * Геттер на хеш блока из приватной секции.
		 */
		std::string get_hash() const;

private:

		/**
		 * Инлайн метод генерации нового хеша блока.
		 * \param [in]	Время генерации текущего блока.
		 * \param [in]	Хеш предыдущего блока.
		 * \param [in]	Данные текущего блока.
		 */
		inline static std::string calcHash(const time_t& time,
										   const std::string& prev_hash,
										   const uint64_t& data) {

				std::stringstream ss;
				ss << time << prev_hash << data;

				std::string result = ss.str();
				return sha256(result);

		}


		time_t 			_timestamp;		///< Время генерации блока
		uint64_t 		_data;			///< Данные блока
		std::string 	_hash;			///< Хеш текущего блока
		std::string 	_last_hash;		///< Хеш предыдущего блока
};



#endif /* BLOCK_H_ */
