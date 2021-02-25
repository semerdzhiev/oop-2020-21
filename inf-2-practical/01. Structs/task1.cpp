#include <cstring>
#include <iostream>

struct Book
{
    char title[256]{};
    char author[256]{};
    char isbn[13]{};
};

void print_books(Book *first, Book *last)
{
    for (Book *book{first}; book != last; ++book)
    {
        std::cout << book->title << " " << book->author << " " << book->isbn << std::endl;
    }
}

Book *remove_book(Book *first, Book *last, const char *isbn)
{
    Book *last_book = (last - 1);
    for (Book *book{first}; book != last; ++book)
    {
        if (!std::strcmp(book->isbn, isbn))
        {
            *book = *last_book;
            return last_book;
        }
    }
    return last;
}

Book *add_book(Book *last, Book book)
{
    *last = book;
    return ++last;
}

int main()
{
    Book book1;
    std::strcpy(book1.title, "1984");
    std::strcpy(book1.author, "George Orwell");
    std::strcpy(book1.isbn, "11111111111");

    Book book2{"1984", "George Orwell", "11111111113"};
    Book book3{"1984", "George Orwell", "11111111114"};

    std::cout << book2.title << std::endl;

    Book books[3] = {book1, book2, book3};

    print_books(books, books + 3);

    std::cout << std::endl;
    Book *new_end = remove_book(books, books + 3, "11111111113");

    print_books(books, new_end);

    Book book4{"1984", "George Orwell", "11111111115"};
    new_end = add_book(new_end, book4);
    print_books(books, new_end);
}