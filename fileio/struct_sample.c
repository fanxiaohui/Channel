#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Books {
    char *title;
    char *author;
    char *subject;
    int book_id;
};

void printBook(struct Books *book);


int main()
{
    struct Books book1;
    struct Books book2;

    book1.title = malloc(50);
    book1.author = malloc(50);
    book1.subject = malloc(100);
    strcpy(book1.title,"some awesome title");
    strcpy(book1.author,"some author name");
    strcpy(book1.subject,"some subject name");
    puts("that name is : ");
    puts(book1.title);
    puts(book1.author);
    puts(book1.subject);

    printBook(&book1);


    return 0;
}

void printBook(struct Books *book){
    printf("the name of the book is %s\n",book->title);
    printf("the title of the book is %s\n",book->title);
}