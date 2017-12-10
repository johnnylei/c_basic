#include <stdio.h>
#include "sort.h"

void print_arr(int *arr, int size, void (*target)(int *, int));
void target(int *arr, int size);

int main() {
	int arr[] = {1, 2, 3, 100, 200, 50, 20, 10, 8, 9, 3, 5, 6, 7, 11, 22, 33};
	int size = sizeof(arr) / sizeof(int);
	print_arr(arr, size, target);
	//bubble(arr, size);
//	shell(arr, size);
//	quick(arr, 0, size - 1);
//	treble_quick(arr, 0, size - 1);
	heap(arr, size);
	print_arr(arr, size, target);
}

void print_arr(int *arr, int size, void (*target)(int *, int)) {
	target(arr, size);
}

void target(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
