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

const int MAX_HOST_NAME = 200;
const int MAX_CONNET_NUMS = 5;
const int MAX_RECV = 10;

class Socket {
	public:
		Socket();
		virtual ~Socket();

		// Server
		bool create();  // create and setsocket
		bool bind(const int port);
		bool listen() const;
		bool accept (Socket&) const;

		// Client
		bool connect(const std::string host, const int port);
		
		// Data Comm
		bool sendData(const std::string) const;
		int recv(std::string&) const;

		void setNoneBlocking(const bool);
		bool isSocketValid() const { return _sock != -1; }

	private:
		int _sock;
		socktaddr_in _addr;
};

#endif  // __SOCKET_CLASS__
