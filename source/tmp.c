#include <stdio.h>
#include <string.h>

void test(char * tmp) {
	strcat(tmp, "  ");
	// puts(tmp);
	printf("%send\n", tmp);
}

int main() {
	char tmp[1024] = "|-";
	test(tmp);
	return 0;
}
