//
// Building our own Unit test framework exercise.
// Step 1: create a very simple mechanism to
//         automatically register and run test cases
//

#include "../SimpleApp/Library.h"
#include <iostream>
#include <algorithm>

// At this point we are using a global variable.
// This is NOT a good option and 
// we will fix this in a future version, but for
// now it lets us keep things simple.
int testAllOk = false;

// All test cases are of this type
using TestFunction = void(*)();

// Runs a single test case
bool runTest(TestFunction pfn, const char* name)
{
    testAllOk = true;
    pfn();
    
    std::cout
        << "   ["
        << (testAllOk ? "  OK  " : "Failed")
        << "] "
        << name
        << std::endl;

    return testAllOk;
}

// Entry point for the application.
int main()
{
}

#define TEST_CASE(name)                     \
void name();                                \
bool testvar_##name = runTest(name, #name); \
void name()

#define CHECK(condition) testAllOk = (condition)

//----------------------------------------------------------------

TEST_CASE(superSort_AlreadySortedArray)
{
    int arr[] = { 1, 2, 3, 4 };
    superSort(arr, 4);
    CHECK(std::is_sorted(arr, arr + 4));
}

TEST_CASE(superSort_ReverseSortedArray)
{
    int arr[] = { 4, 3, 2, 1 };
    superSort(arr, 4);
    CHECK(std::is_sorted(arr, arr + 4));
}


TEST_CASE(superSort_ArrayOfIdenticalElements)
{
    int arr[] = { 1, 1, 1, 1 };
    superSort(arr, 4);
    CHECK(std::is_sorted(arr, arr + 4));
}

// Arrange - Act - Assert
TEST_CASE(superSort_ArrayWithPositiveAndNegativeElements)
{
    int arr[] = { 1, -1, 5, -10, 13 };
    superSort(arr, 5);
    CHECK(std::is_sorted(arr, arr + 5));
}

TEST_CASE(superSort_NullPointer)
{
    superSort(nullptr, 0);
}

TEST_CASE(superSort_NullPointerAndNonZeroSize)
{
    superSort(nullptr, 10);
}

TEST_CASE(superSort_NonEmptyArrayAndZeroSize)
{
    int arr[] = { 1, 8, -3, 4 };
    superSort(arr, 0);
}
