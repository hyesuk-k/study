#include "ServerUtil.h"
#include <string>

int main(int argc, char **argv) {
  int port = 29929;

	if (argc == 2) {
		port = atoi(argv[1]);
	} else if (argc > 2) {
    throw std::invalid_argument {
      "server arguments is invalid (arg count is 1 or 2) : " + std::to_string(argc)};
  }

	ServerUtil server(port);
	std::cout << "server running\n";

	while (true) {
		ServerUtil new_server;
		server.accept(new_server);

		while(true) {
			std::string data;
			int len = 0;
			len = new_server.recvToClient(data);
			new_server.sendToClient(data);
			if (len > 1) return 0;
		}
	}

	printf("%d %s", argc, argv[1]);
	return 0;
}
