#ifndef structs
#define structs

const int MAX_NUMBER_OF_BOOKS = 1000;
const int MAX_STRING = 128;
const int ISBN_SIZE = 13;

struct Book
{
    char *title;
    char *author;
    char isbn[ISBN_SIZE];

    void read();
    void print();
    void clean();
};

struct Library
{
    Book books[MAX_NUMBER_OF_BOOKS];
    int count = 0;

    void addBookFromConsole();
    void removeBook();
    int numberOfBooks();
    void clean();
};

#endif