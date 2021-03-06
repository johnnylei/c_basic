#include <stdio.h>
#define LENGTH 10
#define WIDTH 20
#define NEW_LINE '\n'
#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a) 

int test() {
	int area;
	area = LENGTH * WIDTH;
	printf("area is %d", area);
	printf("%c", NEW_LINE);
	printf("g:a##b=%s\n", g(f(hello, johnny)));
	printf("h:a##b=%s\n", h(f(hello, johnny)));
	printf("f:a##b=%d\n", f(123, 456));
	return 0;
}

#define PRINT1(a, b) { \
	printf("print a\n"); \
	printf("print b\n"); \
}

#define PRINT2(a, b) do { \
	printf("print a\n"); \
	printf("print b\n"); \
} while(0)

#define PRINT(a) do { \
	printf("%s:%d\n", #a, a); \
	printf("%d:%d\n", a, a); \
} while(0)

#define TYPE1(type, name) type name_##type##_type
#define TYPE2(type, name) type name##_##type##_type
#define ERROR_LOG(module) fprintf(stderr, "error:"#module"\n");

int main() {
	int a = 20;
	int b = 19;
	TYPE1(int, c);
	ERROR_LOG(add);
	name_int_type = a;
	TYPE2(int, d);
	d_int_type = a;

	PRINT(a);
	if (a > b) {
		PRINT1(a, b);
	} else {
		PRINT2(a, b);
	}
	PRINT(d_int_type);
	PRINT(name_int_type);
	test();
	return 0;
}
