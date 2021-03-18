/**
 * \brief Structures for working library and books
 * \author D. Zhekov
 */
#ifndef structs
#define structs

const int MAX_NUMBER_OF_BOOKS = 1000;
const int MAX_STRING = 128;
const int ISBN_SIZE = 13;

//! Defines book
struct Book
{
    char *title; //!< stores book title
    char *author; //!< stores book author
    char isbn[ISBN_SIZE]; //!< stores book isbn

    //! Function for reading from console
    void read();
    //! Function for printing
    void print();
    //! Function for cleaning
    void clean();
};

//! Defines library
struct Library
{
    Book books[MAX_NUMBER_OF_BOOKS]; //!< stores books
    int count = 0; //!< stores book count

    //! Function for reading book from console
    void addBookFromConsole();
    //! Function for removing book from the library
    void removeBook();
    //! Function returning number of books.
    int numberOfBooks();
    //! Function for cleaning
    void clean();
};

#endif