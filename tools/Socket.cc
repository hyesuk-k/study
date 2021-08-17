#include <fcntl.h>

#include "Socket.h"

Socket::Socket() :
	_sock (-1)
{
	memset(&_srv_addr, 0, sizeof(_srv_addr));
	memset(&_cli_addr, 0, sizeof(_cli_addr));
}

Socket::~Socket() {
	if (isSocketValid())
		:: close(_sock);
}

void Socket::printErr(std::string func, std::string msg) const {
	if (DEBUG_FLAG == 1) {
		fprintf(stderr, "[%s] %s\n", func.c_str(), msg.c_str());
	} 
}

bool Socket::createSock() {
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (!isSocketValid()) {
		printErr(__func__, "Fail to get new socket");
		return false;
	}

	int reuseAddr = 1;
	if (COMM_STATUS_FAILED == 
			setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuseAddr, sizeof(reuseAddr))) {
		printErr(__func__, "Fail to setsockopt");
		return false;
	}

	return true;
}

bool Socket::bind(const int port) {
	if (!isSocketValid()) {
		printErr(__func__, "Invalid socket");
		return false;
	}

	_srv_addr.sin_family = AF_INET;
	_srv_addr.sin_addr.s_addr = INADDR_ANY;
	_srv_addr.sin_port = htons(port);

	int ret = ::bind(_sock, (struct sockaddr*) &_srv_addr, sizeof(_srv_addr));
	// necessary?
	if (COMM_STATUS_FAILED == ret) {
		printErr(__func__, "Fail to bind");
		return false;
	}

	return true;
}

bool Socket::listen() const {
	if (!isSocketValid()) {
		printErr(__func__, "Invalid socket");
		return false;
	}

	int ret = ::listen(_sock, g_max_backlog_size);
	if (COMM_STATUS_FAILED == ret) {
		printErr(__func__, "Fail to listen");
		return false;
	}

	return true;
}

bool Socket::accept(Socket& sock) const {
	int addr_len = sizeof(_srv_addr);
	sock._sock = ::accept(_sock, (sockaddr *)&_srv_addr, (socklen_t *)&addr_len);

	if (sock._sock <= 0) {
		printErr(__func__, "Fail to accept");
		return false;
	}

	return true;
}

bool Socket::connect(const std::string host, const int port) {
	if (!isSocketValid()) {
		printErr(__func__, "Invalid socket");
		return false;
	}

	_cli_addr.sin_family = AF_INET;
	_cli_addr.sin_port = htons(port);

	int status = inet_pton(AF_INET, host.c_str(), &_cli_addr.sin_addr);

	if (errno == EAFNOSUPPORT) {
		printErr(__func__, "Unavaliable addr");
		return false;
	}

	status = ::connect(_sock, (sockaddr *)&_cli_addr, sizeof(_cli_addr));

	if (status == 0) {
		return true;
	} else {
		printErr(__func__, "Fail to connect");
		return false;
	}
}



