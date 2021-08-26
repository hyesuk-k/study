#ifndef __CLIENT_UTIL__
#define __CLIENT_UTIL__

#include "Socket.h"

enum CLIENT_FUNC_CHECK {
  VALID_INFO,
  INVALID_PORT,
  INVALID_ADDR,
};

class ClientUtil : private Socket {
	public:
		ClientUtil(std::string host, int port);
		ClientUtil() {};
		virtual ~ClientUtil() {};
		
		int sendToServer(const std::string &) const;
		int recvFromServer(std::string&) const;
		int checkPort(const int) const;
		int checkIPv4(const std::string &) const;
};

#endif  // __CLIENT_UTIL__
