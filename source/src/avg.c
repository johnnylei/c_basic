#include <stdio.h>
#include <stdarg.h>

double avg(int num, ...) {
	va_list valist;
	double sum = 0;
	int i =0;

	va_start(valist, num);
	for (; i < num; i++) {
		sum += va_arg(valist, int);
	}
	va_end(valist);
	return sum / num;
}

int main () {
	printf("the avg of 1,2,3,4,5,6 is %f\n", avg(6, 1, 2, 3, 4, 5, 6));
	return 0;
}
