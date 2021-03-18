#include <iostream>
#include "structs.h"

using std::cin;
using std::cout;
using std::endl;

void printMenu()
{
    cout << "Choose option:\n";
    cout << "1 - Add Book to Library\n";
    cout << "2 - Remove Book from Library\n";
    cout << "3 - Get size of Library\n";
    cout << "0 - Exit\n";
}

int main()
{
    int option;
    Library myLibrary;

    do
    {
        printMenu();

        cin >> option;

        switch (option)
        {
            case 1:
                myLibrary.addBookFromConsole();
                break;
            case 2:
                myLibrary.removeBook();
                break;
            case 3:
                cout << "Books: " << myLibrary.numberOfBooks() << endl;
                break;
        }
    } while (option);

    myLibrary.clean();

    return 0;
}