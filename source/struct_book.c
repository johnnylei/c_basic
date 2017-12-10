#include <stdio.h>
#include <string.h>


struct Book {
	char  title[50];
	char  author[50];
	char  subject[50];
	int book_id;
};

void book_print(struct Book book, void (*target)(struct Book ));
void target(struct Book book);
void file_target(struct Book book);
void book_pointer_print(struct Book *book);

int main () {
	struct Book book1, book2;
	strcpy(book1.title, "book1");
	strcpy(book1.author, "johnny");
	strcpy(book1.subject, "it");
	book1.book_id = 1;
	strcpy(book2.title, "book2");
	strcpy(book2.author, "johnnyssss");
	strcpy(book2.subject, "dddddddt");
	book2.book_id = 2;
	book_print(book1, target);
	book_print(book2, target);
	book_print(book2, file_target);
	book_pointer_print(&book1);
	return 0;
}

void book_print(struct Book book, void (*target)(struct Book )) {
	target(book);
}

void target(struct Book book) {
	printf("book title is %s\n", book.title);
	printf("book author is %s\n", book.author);
	printf("book subject is %s\n", book.subject);
	printf("book id is %d\n", book.book_id);
}

void book_pointer_print(struct Book *book) {
	printf("book title is %s\n", book->title);
	printf("book author is %s\n", book->author);
	printf("book subject is %s\n", book->subject);
	printf("book id is %d\n", book->book_id);
}

void file_target(struct Book book) {
	FILE *fd;
	fd = fopen("tmp", "a+");
	//fprintf(fd, "book title is %s\nbook author is %s\nbook subject is %s\nbook id is %d\n", book.title, book.author, book.subject, book.book_id);
	char str[150];
	sprintf(str, "book title is %s\nbook author is %s\nbook subject is %s\nbook id is %d\n", book.title, book.author, book.subject, book.book_id);
	fputs(str, fd);
	fclose(fd);
}
