#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getSeconds(unsigned long *par);
double getAverage(int *arr, int size);
int * getRandom();
void _log(void (*target)(char *, int));
void target(char *str, int size);

int max(int x, int y) {
	return x > y ? x : y;
}

// invalid example
int first() {
	int *p ;
	char *p1;
	*p = 1;
	*p1 = 'c';
 	printf("p is %d and address is %p\n", *p, p);
	printf("p1 is %c and address is %p\n", *p1, p1);
	
	return 0;
}

int basic() {
	int var = 20;
	int *p;
	p = &var;
	printf("address of var variable : %p\n", &var);
	printf("address stored in p variable:%p\n", p);
	printf("value of *p vaiable:%d\n", *p);
	return 0;
}

int arr() {
	int arr[] = {1,2,3,4};
	int *p = arr;
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		printf("pointer is %d\n", *(p + i));
	}
	return 0;
}

int arr2() {
	int arr[] = {1, 2, 3, 4};
	int *p, len = sizeof(arr)/sizeof(int);
	p = &arr[len];
	for (int i = 1; i <= len; i++) {
		printf("pointer is %d\n", *(p - i));
	}
	return 0;
}

// int *p[] 数组里面每个元素都是指针
#define MAX  3
int pointer_arr() {
	int a[] = {1, 2, 3};
	int *p[MAX];
	for(int i = 0; i < MAX; i++) {
		p[i] = &a[i];
	}

	for (int i = 0; i < MAX; i++) {
		printf("pointer value is %d, and pointer is %p\n", *p[i], p[i]);
	}

	return 0;
}


int str_arr() {
	char *names[] = {
		"johnny",
		"nicoals",
		"wesley"
	};

	for(int i = 0; i < 3; i++) {
		printf("hello %s\n", names[i]);
	}
	return 0;
}

int secondary_point() {
	int var = 1;
	int *p, **secondary_pointer;
	p = &var;
	secondary_pointer = &p;
	printf("p value is %d and address is %p\n", *p, p);
	printf("secondary pointer value is %d and address is %p and value is %p\n", **secondary_pointer, *secondary_pointer, secondary_pointer);
}

int main() {
	basic();
	arr();
	arr2();
	pointer_arr();
	str_arr();
	secondary_point();
	unsigned long sec;
	getSeconds(&sec);
	printf("Number of seconds:%ld\n", sec);

	int arr[] = {1, 2, 3, 4, 5};
	printf("arr average value is %f\n", getAverage(arr, sizeof(arr)/sizeof(int)));
	int *p;
	p = getRandom();
	for (int i = 0; i < 10; i++) {
		printf("(p + %d) : %d\n", i, *(p + i));
	}

	int (*m)(int, int);
	m = &max;
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);
	d = m(m(a, b), c);
	printf("the max is %d\n", d);
	_log(target);
	return 0;
}

void getSeconds(unsigned long *par) {
	*par = time(NULL);
}

double getAverage(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return (double) sum / size;
}

int * getRandom() {
	static int r[10];
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++) {
		r[i] = rand();
	}

	return r;
}

void target(char *str, int size) {
	for(int i = 0; i < size; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

void _log (void (*target)(char *, int)) {
	char str[] = "hello johnny, i am wesley, nice to see you";
	target(str, sizeof(str)/sizeof(char));
}
