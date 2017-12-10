#include <stdio.h>

void hanno(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c => %c\n", a, c);
		return ;
	}

	hanno(n - 1, a, c, b);
	printf("%c => %c\n", a, c);
	hanno(n-1, b, a, c);
}

int main() {
	hanno(10, 'a', 'b', 'c');
	return 0;
}
