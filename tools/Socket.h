#ifndef __SOCKET_CLASS__
#define __SOCKET_CLASS__

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
// Internet address family
// in_port_t, in_addr_t 
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <iostream>

typedef enum _COMM_STATUS {
	COMM_STATUS_FAILED = -1,
	COMM_STATUS_SUCCESS = 0,
} COMM_STATUS;

#define DEBUG_FLAG 1

const int g_max_backlog_size = 3;

class Socket {
	public:
		Socket();
		virtual ~Socket();

		void printErr(std::string func, std::string msg) const;

		// Server
		bool createSock();  // add sock opt?
		bool bind(const int port);
		bool listen() const;  // not modify _sock and _addr in this func
		bool accept(Socket&) const;

		// Client
		bool connect(const std::string host, const int port);
		
		// Data Comm
		bool sendData(const std::string) const;
		int recvData(std::string&) const;

		void setNoneBlocking(const bool);
		bool isSocketValid() const { return _sock != -1; }

	private:
		int _sock;
		sockaddr_in _srv_addr, _cli_addr;
};

#endif  // __SOCKET_CLASS__
