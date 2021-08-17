#include <fcntl.h>

#include "Socket.h"

Socket::Socket() :
	g_max_backlog_size (3)
{
	_sock = DEFAULT_SOCK_VALUE;
	memset(&_srv_addr, 0, sizeof(_srv_addr));
	memset(&_cli_addr, 0, sizeof(_cli_addr));
}

Socket::~Socket() {
	if (isSocketValid())
		:: close(_sock);
}

void Socket::printErr(std::string func, std::string msg) const {
	if (g_debug_flag == DEBUG_FLAG_ON) {
		fprintf(stderr, "[%s] %s\n", func.c_str(), msg.c_str());
	} 
}

int Socket::createSock() {
	int sock = DEFAULT_SOCK_VALUE;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == DEFAULT_SOCK_VALUE) {
		printErr(__func__, "Fail to get new socket");
		return COMM_STATUS_FAILED;
	}

	int reuseAddr = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuseAddr, sizeof(reuseAddr))
			== COMM_STATUS_FAILED) {
		printErr(__func__, "Fail to setsockopt");
		return COMM_STATUS_FAILED;
	}

	return sock;
}

bool Socket::setSock(const int sock) {
	_sock = sock;
	if (!isSocketValid()) {
		printErr(__func__, "Invalid socket");
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
	if (ret == COMM_STATUS_FAILED) {
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
	if (ret == COMM_STATUS_FAILED) {
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

	if (status == COMM_STATUS_SUCCESS_CONNECT) {
		return true;
	} else {
		printErr(__func__, "Fail to connect");
		return false;
	}
}

int Socket::sendData(const std::string data) const {
	int send_data_len = ::send(_sock, data.c_str(), data.size(), MSG_NOSIGNAL);
	if (send_data_len == COMM_STATUS_FAILED) {
		return COMM_STATUS_FAILED;
	} else {
		return send_data_len;
	}
}

int Socket::recvData(std::string &data) const {
	char buf[MAX_RECV_BUFF_LEN + 1];
	memset(buf, 0, MAX_RECV_BUFF_LEN + 1);
	data = "";

	int recv_data_len = ::recv(_sock, buf, MAX_RECV_BUFF_LEN, 0);
	if (recv_data_len == COMM_STATUS_FAILED) {
		return COMM_STATUS_FAILED;
	} else if (recv_data_len == COMM_STATUS_NO_SND_RCV_DATA) {
		return COMM_STATUS_NO_SND_RCV_DATA;
	} else {
		data = buf;
		return recv_data_len;
	}
}

// void setNoneBlocking(const bool flag)

