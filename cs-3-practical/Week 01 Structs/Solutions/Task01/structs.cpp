#include <iostream>
#include "structs.h"
#include "helpers.cpp"

using std::cin;
using std::cout;
using std::endl;

void Book::read()
{
    char tmp[MAX_STRING];

    cout << "Book title: " << endl;
    cin.ignore();
    cin.getline(tmp, MAX_STRING);
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
    title = new (std::nothrow) char[strlen(tmp)];
    strcpy(title, tmp);

    cout << "Book author:" << endl;
    cin.getline(tmp, MAX_STRING);
    author = new (std::nothrow) char[strlen(tmp)];
    strcpy(author, tmp);

    cout << "Book ISBN:" << endl;
    cin >> isbn;
}

void Book::print()
{
    cout << "Book title: " << title << endl;
    cout << "Book author: " << author << endl;
    cout << "Book ISBN: " << isbn << endl;
}

void Book::clean() 
{
    delete[] title;
    delete[] author;
}

void Library::addBookFromConsole()
{
    if (count < MAX_NUMBER_OF_BOOKS)
    {
        Book newBook;
        newBook.read();
        books[count++] = newBook;
    }
    else
    {
        cout << "NO MORE CAPACITY" << endl;
    }
}

void Library::removeBook()
{
    char isbn[ISBN_SIZE];
    cout << "ISBN of Book for deletion: ";
    cin >> isbn;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            cout << "Deleted book: " << endl;
            books[i].print();
            books[i] = books[--count];
            break;
        }
    }
}

int Library::numberOfBooks()
{
    return count;
}

void Library::clean() 
{
    for (int i = 0; i < count; i++) {
        books[i].clean();
    }
}
