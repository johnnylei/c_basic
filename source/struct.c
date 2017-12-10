#include <stdio.h>

struct Book {
	int data;
};

void change_book(struct Book book) {
	book.data = 100;
}

void modify_book(struct Book *book) {
	book->data = 100;
}


int main () {
	struct Book book;
	book.data = 1;
	change_book(book);
	printf("book data is %d\n", book.data);
	modify_book(&book);
	printf("book data is %d\n", book.data);
	
	return 0;
}
