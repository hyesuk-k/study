#include "ServerUtil.h"
#include <string>

int main(int argc, char **argv) {
	std::cout << "server running\n";

	ServerUtil server(30000);

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
