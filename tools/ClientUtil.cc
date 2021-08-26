#include "ClientUtil.h"

ClientUtil::ClientUtil(std::string host, int port) {
	int sock = Socket::createSock();
	if ((sock == DEFAULT_SOCK_VALUE)
			|| (Socket::setSock(sock) != true)) {
		Socket::printErr(__func__, "Fail to create client sock");
	}

	if (!Socket::connect(host, port)) {
		Socket::printErr(__func__, "Fail to bind port");
	}
}

int ClientUtil::sendToServer(const std::string &data) const {
	int send_data_len = Socket::sendData(data);

	if (send_data_len == COMM_STATUS_FAILED) {
		Socket::printErr(__func__, "Send Data failed to server");
	}

	return send_data_len;
}

int ClientUtil::recvFromServer(std::string &data) const {
	int recv_data_len = Socket::recvData(data);

	switch(recv_data_len) {
		case COMM_STATUS_FAILED:
		case COMM_STATUS_NO_SND_RCV_DATA:
			printErr(__func__, "No data recv from server");
			break;
		default:
			break;
	}

	return recv_data_len;
}

int ClientUtil::checkPort(const int port) const {
  if ((port > 65535) || (port < 1024)) {
    return INVALID_PORT;
  }

  return VALID_INFO;  
}

int ClientUtil::checkIPv4(const std::string &host) const {
  std::string local = "localhost"; 
  in_addr addr;

  if ((host != local)
      && (0 == inet_pton(AF_INET, host.c_str(), &addr.s_addr))) {
    return INVALID_ADDR;
  }

  return VALID_INFO;
}
