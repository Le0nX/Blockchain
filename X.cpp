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
int32_t PORT = 8090;
int main(int argc, char* argv[]) {
	if (argc >= 2) {
		PORT = atoi(argv[1]);
	} else perror("You forgot to type PORT for BlockChain Client... Default is 8090");

	BlockChain* chain = new BlockChain(); 	//валидная цепь

	HTTP_Server Server(PORT,2);
    std::vector<std::string> Data;


	Server.resources["^/signBlock/?$"]["^POST$"]=[Data, chain](std::ostream& response, const request_t& request, const std::smatch& path_match) mutable {
		        //Retrieve string from istream (*request.content)
				(void) path_match;
		        std::stringstream ss;
		        *request.payload >> ss.rdbuf();
		        json content;
		        ss >> content;
		        Data.clear();
		        Data.push_back(chain->gen_ID());
		        for (auto& element : content) {
		          Data.push_back(element);
		        }
		        for (auto& i : Data) {
				  std::cout << i << std::endl;
				}
		        chain->addBlock(Data);
		        response << "HTTP/1.1 200 OK\r\n";
		    };
	std::string j;
	Server.resources["^/signBlock$"]["^GET$"]=[j,chain](std::ostream& response, const request_t& request, const std::smatch& path_match) mutable {
				(void)path_match;
				(void)request;
				j = chain->JSON_of_last_block();
				response <<  "HTTP/1.1 200 OK\r\nContent-Length: " << j.size() << "\r\n\r\n" << j;
		    };


	Server.init();


	return 0;
}
