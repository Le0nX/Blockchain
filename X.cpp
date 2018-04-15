//============================================================================
// Name        : main.cpp
// Author      : Denis Nefedov
// Version     : 0.01
// Copyright   : LGPL
// Description : main source file.
//============================================================================

#include "Block.h"
#include "Blockchain.h"
#include "httpServer.h"
#include <iostream>
#include <cstdlib>

int main(void) {
//	if (argc >= 2) {
//		const uint32_t PORT = atoi(argv[1]);
//		(void)PORT;
//	} else perror("You forgot to type PORT for BlockChain Client..."); exit(1);

	//Здесь запускаем новый поток с HTTP_Server...

	//Dataset 1
	const std::string base = "DB67ZA";
	uint64_t counter = 1;
	std::stringstream ss;
	ss << counter++;
	const std::string ID = base + ss.str();
	std::vector<std::string> data;
	data.push_back(ID);



	BlockChain* chain = new BlockChain(); 	//валидная цепь

	chain->addBlock(data);
	chain->addBlock(data);

//	//Подменяем данные в блоке. Проверяем работу метода isValidChain, который проверяет всю цепь.
//	chain->_blockchain[1]->_data[0] = "wn";
//	std::cout << chain->isValidChain(chain->get_chain());

	HTTP_Server Server(8090,2);


	Server.resources["^/signBlock/?$"]["^POST$"]=[](std::ostream& response, const request_t& request, const std::smatch& path_match) {
		        //Retrieve string from istream (*request.content)
				(void) path_match;
		        std::stringstream ss;
		        *request.payload >> ss.rdbuf();
		        std::string content=std::move(ss.str());
		        std::cout << content << std::endl;
		        sleep(5);
		        response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
		    };
	Server.resources["^/signBlock$"]["^GET$"]=[chain](std::ostream& response, const request_t& request, const std::smatch& path_match) {
				(void)path_match;
				(void)request;
				std::string j = chain->toJSON();
		       response <<  "HTTP/1.1 200 OK\r\nContent-Length: " << j.size() << "\r\n\r\n" << j;
		    };
	Server.init();


	return 0;
}
