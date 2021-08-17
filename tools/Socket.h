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
	COMM_STATUS_NO_SND_RCV_DATA = 0,
	COMM_STATUS_SUCCESS_CONNECT = 0,
	COMM_STATUS_SUCCESS = 1,
} COMM_STATUS;

#define DEBUG_FLAG_ON 1
#define DEBUF_FLAG_OFF 0

#define DEFAULT_SOCK_VALUE -1
#define MAX_RECV_BUFF_LEN 2048

const int g_debug_flag = DEBUG_FLAG_ON;

class Socket {
	public:
		Socket();
		virtual ~Socket();

		void printErr(std::string func, std::string msg) const;

		int createSock();  // add sock opt?
		bool setSock(const int sock);

		// Server
		bool bind(const int port);
		bool listen() const;  // not modify _sock and _addr in this func
		bool accept(Socket&) const;

		// Client
		bool connect(const std::string host, const int port);
		
		// Data Comm
		int sendData(const std::string) const;
		int recvData(std::string&) const;

		void setNoneBlocking(const bool);
		bool isSocketValid() const { return _sock != -1; }

	private:
		int _sock;
		sockaddr_in _srv_addr, _cli_addr;
    const int g_max_backlog_size;
};

#endif  // __SOCKET_CLASS__
