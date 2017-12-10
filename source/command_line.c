#include <stdio.h>

int main(int argc, char * argv[]) {
	printf("the number of args is %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("the %d params is %s\n", i, argv[i]);
	}
}
