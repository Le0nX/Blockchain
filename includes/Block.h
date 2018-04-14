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
#include <vector>
#include <stdint.h>
#include "sha256.h"
#include <sstream>
#include <memory>

#include <iostream>
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
		Block(time_t timestamp, std::vector<std::string> data, std::string hash, std::string last_hash):
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
		static Block* mineBlock(const Block* lastBlock, std::vector<std::string> data);

		/**
		 * Геттер на хеш блока из приватной секции.
		 */
		std::string get_hash() const;

		std::vector<std::string> get_data() const;

		std::string print_data() const;
private:

		/**
		 * Инлайн метод генерации нового хеша блока.
		 * \param [in]	Время генерации текущего блока.
		 * \param [in]	Хеш предыдущего блока.
		 * \param [in]	Данные текущего блока.
		 */
		inline static std::string calcHash(const time_t& time,
										   const std::string& prev_hash,
										   const std::vector<std::string>& data) {
				std::string temp;
				for (auto str : data) {
					temp += str + ", ";
					std::cout << temp << std::endl;
				}
				//std::string temp = print_data();

				std::stringstream ss;
				ss << time << prev_hash << temp;

				std::string result = ss.str();
				return sha256(result);

		}


		time_t 						_timestamp;		///< Время генерации блока
		std::vector<std::string> 	_data;			///< Данные блока
		std::string 				_hash;			///< Хеш текущего блока
		std::string 				_last_hash;		///< Хеш предыдущего блока
};



#endif /* BLOCK_H_ */
