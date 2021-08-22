#include <iostream>

#include "ClientMain.h"

int main(int argc, char *argv[]) {
	std::string host = "localhost";
	int port = 29929;

	if (argc > 1) {
		port = atoi(argv[1]);
	} else if (argc > 2) {
		host.assign(argv[1], strlen(argv[1]));
		port = atoi(argv[2]);
	}

  if ((port > 65535) || (port < 1024)) {
    throw std::out_of_range("port out of range (1025 ~ 65535)");
  }

	printf("%s\n", argv[1]);
	std::cout << host << ":" << port << std::endl;

	ClientUtil client(host, port);

	std::string data;

	client.sendToServer("Test Message.");
	client.recvFromServer(data);
	
	std::cout << "Recv data : " << data << "\n";

	return 0;
}
