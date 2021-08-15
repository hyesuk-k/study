#include <iostream>

#include "sockUtils.h"

int main(int argc, char **argv) {
	Socket sc;

	if (argc > 1) {
		if (strcmp(argv[1], OPT_SERVER) == 0) {
				printf("run server\n");
		} else if (strcmp(argv[1], OPT_CLIENT) == 0) {
			printf("run client\n");
		} else {
			printf("not define args\n please server or client \n");
			exit(-1);
		}
	}

	printf("%s %d \n", argv[1], argc);
	sc.create();

	return 0;
}
