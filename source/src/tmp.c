#include <stdio.h>
#include <string.h>

void test(char * tmp) {
	strcat(tmp, "  ");
	// puts(tmp);
	printf("%send\n", tmp);
}

int main() {
	char *tmp= "|-";
	test(tmp);
	return 0;
}
