#include <stdio.h>

static int count = 10;
void func(void) {
	static int thingy = 5;
	thingy++;
	printf("thingy is %d, count is %d\n", thingy, count);
}

int main() {
	while(count--) {
		func();
	}
	return 0;
}

