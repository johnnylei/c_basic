#include <stdio.h>
#define LENGTH 10
#define WIDTH 20
#define NEW_LINE '\n'

int main() {
	int area;
	area = LENGTH * WIDTH;
	printf("area is %d", area);
	printf("%c", NEW_LINE);
	return 0;
}
