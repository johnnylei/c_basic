#include <stdio.h>
#include <string.h>

union Data {
	int i;
	float f;
	char str[20];
};

int main () {
	union Data data;
	data.i = 10;
	printf("data.i:%d\n", data.i);
	data.f = 100.0;
	printf("data.f:%f\n", data.f);
	strcpy(data.str, "this is union data");
	printf("data.str:%s\n", data.str);

	printf("Memory size occupied by data:%ld\n", sizeof(data));
	return 0;
}
