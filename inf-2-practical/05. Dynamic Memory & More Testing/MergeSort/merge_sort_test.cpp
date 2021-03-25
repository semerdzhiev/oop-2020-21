#define CATCH_CONFIG_MAIN
#include "catch2/catch2.hpp"
#include "merge_sort.hpp"
#include <algorithm>

TEST_CASE("Sorting array with 1 element works")
{
    int arr[1] = {5};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}

TEST_CASE("Sorting array with positive elements works")
{
    int arr[] = {5, 10, 1, 8, 45, 7, 9, 20};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}

TEST_CASE("Sorting array with negative elements works")
{
    int arr[] = {-5, -10, -1, -8, -45, -7, -9, -20};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}

TEST_CASE("Sorting array with both negative and positive elements works")
{
    int arr[] = {5, 10, -1, 8, 45, 7, -9, 20};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}

TEST_CASE("Sorting sorted array keeps it sorted")
{
    int arr[] = {-10, -5, -1, 8, 14, 27, 39, 40};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}

TEST_CASE("Sorting array with equal elements keeps it sorted")
{
    int arr[] = {4, 4, 4, 4};
    merge_sort(std::begin(arr), std::end(arr));
    REQUIRE(std::is_sorted(std::begin(arr), std::end(arr)));
}
