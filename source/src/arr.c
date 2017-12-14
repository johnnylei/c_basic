#include <stdio.h>

int test(double arr[]) {
	arr[0] = 122;
}

int main() {
	double balance[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double *p = balance;
	test(p);
	for(int i = 0; i < 5; i++) {
		printf("item is %f and index is %d \n", *(p + i), i);
	}
	return 0;
}
