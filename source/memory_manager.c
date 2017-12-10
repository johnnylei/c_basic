#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dynamic_malloc_memory() {
	char *p;
	p = malloc(100 * sizeof(char));
	if (p == NULL) {
		printf("mallo failed!!\n");
		exit(1);
	}
	strcpy(p, "hello , this is johnny");
	printf("pointer value is %s\n", p);
	free(p);
}

int main() {
	dynamic_malloc_memory();
}
