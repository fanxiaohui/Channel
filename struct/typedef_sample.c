#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Books {
    char title[50];
    char author[50];
    char *subject;
    int book_id;
} Book;

int main(int argc, char const *argv[])
{
    Book book;

    strcpy(book.title,"Some king of title");
    strcpy(book.author,"some author");
    book.subject="this is awesome";
    book.book_id = 130;


    printf("book name is %s \n",book.title);
    printf("book author is %s \n",book.author);
    printf("book subject is %s \n",book.subject);
    printf("book id is %d\n",book.book_id);


    return 0;
}

