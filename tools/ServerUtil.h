#ifndef __SERVER_UTIL__
#define __SERVER_UTIL__

#include "Socket.h"

class ServerUtil : private Socket {
	public:
		ServerUtil(int port);
		ServerUtil() {};
		virtual ~ServerUtil();

		int sendToClient(const std::string&) const;
		int recvToClient(std::string&) const;

		void accept(ServerUtil &);
};


#endif  // __SERVER_UTIL__
