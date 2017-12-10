#include <stdio.h>

typedef int FD;
typedef char BYTE;

int main() {
	BYTE c = 'c';
	FD fd = 1;
	printf("BYTE c is %c, and FD fd is %d\n", c, fd);
}
