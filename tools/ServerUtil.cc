#include "ServerUtil.h"

ServerUtil::ServerUtil(int port) {
	int sock = Socket::createSock();
	if ((sock == DEFAULT_SOCK_VALUE)
			|| (Socket::setSock(sock) != true)) {
		Socket::printErr(__func__, "Fail to create server sock");
	}

	if (!Socket::bind(port)) {
		Socket::printErr(__func__, "Fail to bind server sock");
	}

	if (!Socket::listen()) {
		Socket::printErr(__func__, "Fail to listen");
	}
}

ServerUtil::~ServerUtil() {
}

int ServerUtil::sendToClient(const std::string& data) const {
	if (!Socket::sendData(data)) {
		Socket::printErr(__func__, "Fail send data to client");
	}

	return 0;
}

int ServerUtil::recvToClient(std::string& data) const {
	if (!Socket::recvData(data)) {
		Socket::printErr(__func__, "Fail recv data from client");
	}

	return 0;
}

void ServerUtil::accept(ServerUtil &sock) {
//	if(!Socket::accept(sock));
	Socket::accept(sock);
}

