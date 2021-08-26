#include <iostream>

#include "ClientMain.h"

int main(int argc, char *argv[]) {
	std::string host = "localhost";
	int port = 29929;

	if (argc == 2) {
		port = atoi(argv[1]);
	} else if (argc == 3) {
		host.assign(argv[1], strlen(argv[1]));
		port = atoi(argv[2]);
	}

  ClientUtil c;

  if (VALID_INFO != c.checkPort(port)) {
    throw std::invalid_argument{
      "port is out of range (1025 ~ 65535) : "};
  }

  if (VALID_INFO != c.checkIPv4(host)) {
    throw std::invalid_argument(
      "host is not [localhost] OR [IPv4] ");
  }

	std::cout << host << ":" << port << std::endl;

	ClientUtil client(host, port);

	std::string data;

	client.sendToServer("Test Message.");
	client.recvFromServer(data);
	
	std::cout << "Recv data : " << data << "\n";

	return 0;
}
