#include <stdio.h>

#define SWAP(x, y) x=x^y;y=x^y;x=x^y;

void bubble(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] < arr[j + 1]) {
				continue;
			}
			SWAP(arr[j], arr[j + 1]);
		}
	}
}

void shell(int *arr, int size) {
	int gap = size / 2;
	while(gap > 0) {
		for (int i = 0; i < size - gap; i++) {
			for (int j = i; j < size - gap; j += gap) {
				if(arr[j] < arr[j + gap]) {
					continue;
				}
				SWAP(arr[j], arr[j + gap]);
			}
		}
		gap = gap / 2;
	}
}

void quick(int *arr, int start, int end) {
	int left = start, right = end;
	int data = arr[start];
	while (left < right) {
		if (arr[left] > arr[right]) {
			SWAP(arr[left], arr[right]);
		}
		
		data == arr[left] ? right-- : left++;	
	}
	
	if (start < right - 1) {
		quick(arr, start, right - 1);	
	}
	
	if (right + 1 < end) {
		quick(arr, right + 1, end);	
	}
	
}

// 3路切分快速排序呢
void treble_quick(int *arr, int start, int end) {
	if (start >= end) {
		return ;
	}

	if (arr[start] > arr[end]) {
		SWAP(arr[start], arr[end]);
	}

	int left = start, right = end;
	for (int i = start; i < end; i++) {
		if (arr[i] > arr[i + 1]) {
			SWAP(arr[i], arr[i + 1]);
			i++;
			left = i;
		}
	}

	for (int j = right; j > end - left; j--) {
		if (arr[j] < arr[j - 1]) {
			SWAP(arr[j], arr[j - 1]);
			j--;
			right = j;
		}
	}

	treble_quick(arr, start, left - 1);
	treble_quick(arr, left + 1, right - 1);
	treble_quick(arr, right + 1, end);
}

void adjust_heap(int *arr, int i, int size) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && arr[i] < arr[left]) {
		SWAP(arr[i], arr[left]);
	}

	if (right < size && arr[i] < arr[right]) {
		SWAP(arr[i], arr[right]);
	}
}

void build_heap(int *arr, int size) {
	if (size <= 1) {
		return ;
	}

	for (int i = size / 2; i >= 0; i--) {
		adjust_heap(arr, i, size);
	}
}

void heap(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		build_heap(arr, size - i);
		SWAP(arr[0], arr[size - i - 1]);
	}
}

