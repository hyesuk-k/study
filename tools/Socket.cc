#include <fcntl.h>

#include "Socket.h"

Socket::Socket() :
	_sock (-1)
{
	memset(&_addr, 0, sizeof(_addr));
}

Socket::~Socket() {
	if (isSocketValid())
		:: close(_sock);
}

bool Socket::create() {
	printf("create test\n");
	return true;
}
