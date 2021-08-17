#ifndef __CLIENT_UTIL__
#define __CLIENT_UTIL__

#include "Socket.h"

class ClientUtil : private Socket {
	public:
		ClientUtil(std::string host, int port);
		virtual ~ClientUtil() {};
		
		int sendToServer(const std::string &) const;
		int recvFromServer(std::string&) const;
};

#endif  // __CLIENT_UTIL__
