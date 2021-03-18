#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "DynArray.h"

DynArray createTestDynArray(size_t capacity) {
    return create(capacity);
}

TEST_CASE("DynArray - create") {

    size_t capacity = 4;
    DynArray dynArr = createTestDynArray(capacity);

    CHECK(dynArr.capacity == capacity);
    CHECK(dynArr.size == 0);
    CHECK_NOTHROW(dynArr.arr);
}

TEST_CASE("DynArray - push_back for first time") {

    size_t capacity = 2;
    int element = 7;
    DynArray dynArr = createTestDynArray(capacity);
    push_back(dynArr, element);

    SECTION("push_back for first time") {
        CHECK(dynArr.capacity == capacity);
        CHECK(dynArr.size == 1);
        CHECK(dynArr.arr[0] == 7);
    }

    SECTION("push_back with resize") {
        push_back(dynArr, 12);
        push_back(dynArr, 13);

        CHECK(dynArr.capacity == capacity*2);
        CHECK(dynArr.size == 3);
        CHECK(dynArr.arr[1] == 12);
        CHECK(dynArr.arr[2] == 13);

    }
}


TEST_CASE("DynArray - pop_back") {

    size_t capacity = 4;
    int element = 7;
    DynArray dynArr = createTestDynArray(capacity);

    SECTION("pop_back with 2 elements") {
        push_back(dynArr, element);
        push_back(dynArr, element);
        pop_back(dynArr);

        CHECK(dynArr.capacity == capacity);
        CHECK(dynArr.size == 1);
    }

    SECTION("pop_back with 0 elements") {
        pop_back(dynArr);

        CHECK(dynArr.capacity == capacity);
        CHECK(dynArr.size == 0);
    }
    
}

TEST_CASE("DynArray - resize") {

    size_t capacity = 4;
    DynArray dynArr = createTestDynArray(capacity);
    push_back(dynArr, 10);
    push_back(dynArr, 9);
    resize(dynArr);

    CHECK(dynArr.capacity == capacity*2);
    CHECK(dynArr.arr[0] == 10);
    CHECK(dynArr.arr[1] == 9);
}

TEST_CASE("DynArray - remove") {

    size_t capacity = 4;
    DynArray dynArr = createTestDynArray(capacity);

    SECTION("remove with valid index") {
        push_back(dynArr, 10);
        push_back(dynArr, 9);
        remove(dynArr, 0);

        CHECK(dynArr.size == 1);
        CHECK(dynArr.arr[0] == 9);
    }


    SECTION("remove with not valid index") {
        push_back(dynArr, 10);
        push_back(dynArr, 9);
        remove(dynArr, 5);

        CHECK(dynArr.size == 2);
        CHECK(dynArr.arr[0] == 10);
        CHECK(dynArr.arr[1] == 9);
    } 
}

TEST_CASE("DynArray - get") {

    size_t capacity = 4;
    DynArray dynArr = createTestDynArray(capacity);

    SECTION("get with valid index") {
        push_back(dynArr, 10);
        push_back(dynArr, 9);

        CHECK(get(dynArr, 0) == 10);
        CHECK(get(dynArr, 1) == 9);
    }


    SECTION("get with not valid index") {
        push_back(dynArr, 10);
        push_back(dynArr, 9);

        CHECK(get(dynArr, 5) == -1);
    }
}