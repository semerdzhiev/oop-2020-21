#define CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include "ArrayFunctions.h"

//TEST_CASE("Array: resize a not allocated array should allocate memory")
//{
//	Array array{};
//
//	bool successful = resize(array);
//	
//	REQUIRE(successful);
//	REQUIRE(array.data != nullptr);
//	REQUIRE(array.size == 0);
//	REQUIRE(array.capacity == 1);
//
//	freeMemory(array);
//}

//TEST_CASE("Array: resizing an array when the size is equal to the capacity should change the capacity")
//{
//	Array array{};
//	allocateMemory(array);
//
//	addElement(array, 1);
//
//	REQUIRE(array.size == 1);
//	REQUIRE(array.capacity >= 1);
//
//	bool successful = resize(array);
//
//	REQUIRE(successful);
//	REQUIRE(array.size == 1);
//	REQUIRE(array.capacity == 2);
//
//	freeMemory(array);
//}

//TEST_CASE("Array: resizing an array when the size is less than the capacity should not change the capacity")
//{
//	Array array{};
//	allocateMemory(array);
//
//	addElement(array, 1);
//	addElement(array, 2);
//	addElement(array, 3);
//
//	REQUIRE(array.size == 3);
//	REQUIRE(array.capacity >= 3);
//
//	size_t expectedSize = 3;
//	size_t expectedCapacity = 4;
//
//	bool successful = resize(array);
//
//	REQUIRE(successful);
//	REQUIRE(array.size == expectedSize);
//	REQUIRE(array.capacity == expectedCapacity);
//}

TEST_CASE("Array: resize")
{
	Array array{};
	allocateMemory(array);

	SECTION("Resizing an empty array does not change the array")
	{
		// the original array should not be changed
		Array expected = array;

		bool successful = resize(array);

		REQUIRE(successful);
		REQUIRE(array.data != nullptr);
		REQUIRE(array.size == expected.size);
		REQUIRE(array.capacity == expected.capacity);
	}

	SECTION("Resizing an array when the size is equal to the capacity changes the capacity")
	{
		addElement(array, 1);

		REQUIRE(array.size == 1);
		REQUIRE(array.capacity >= 1);

		size_t expectedSize = 1;
		size_t expectedCapacity = 2;

		bool successful = resize(array);

		REQUIRE(successful);
		REQUIRE(array.size == expectedSize);
		REQUIRE(array.capacity == expectedCapacity);
	}

	SECTION("Resizing an array when the size is less than the capacity does not change the capacity")
	{
		addElement(array, 1);
		addElement(array, 2);
		addElement(array, 3);

		REQUIRE(array.size == 3);
		REQUIRE(array.capacity >= 3);

		size_t expectedSize = 3;
		size_t expectedCapacity = 4;

		bool successful = resize(array);

		REQUIRE(successful);
		REQUIRE(array.size == expectedSize);
		REQUIRE(array.capacity == expectedCapacity);
	}

	freeMemory(array);
}

TEST_CASE("Array: addElement")
{
	Array array{};
	allocateMemory(array);

	REQUIRE(array.data != nullptr);
	REQUIRE(array.size == 0);
	REQUIRE(array.capacity >= 1);

	SECTION("Adding the first element")
	{
		addElement(array, 7);

		REQUIRE(array.size == 1);
		REQUIRE(array.capacity == 1);
		REQUIRE(array.data[0] == 7);
	}

	SECTION("Resize expected while adding an element")
	{
		addElement(array, 1);
		addElement(array, 2);
		addElement(array, 3);

		REQUIRE(array.size == 3);
		REQUIRE(array.capacity == 4);

		REQUIRE(array.data[0] == 1);
		REQUIRE(array.data[1] == 2);
		REQUIRE(array.data[2] == 3);
	}

	freeMemory(array);
}

TEST_CASE("Array: addElementAtPosition")
{
	Array array{};
	allocateMemory(array);

	REQUIRE(array.data != nullptr);

	addElement(array, 1);
	addElement(array, 2);
	addElement(array, 3);

	REQUIRE(array.size == 3);
	REQUIRE(array.capacity >= 3);

	SECTION("Adding element at valid position")
	{
		bool successful = addElement(array, 0, 0);

		REQUIRE(successful);

		REQUIRE(array.size == 4);
		REQUIRE(array.capacity == 4);

		REQUIRE(array.data[0] == 0);
		REQUIRE(array.data[1] == 1);
		REQUIRE(array.data[2] == 2);
		REQUIRE(array.data[3] == 3);
	}

	SECTION("Adding element at non-valid position")
	{
		bool successful = addElement(array, 0, 6);

		REQUIRE_FALSE(successful);

		REQUIRE(array.size == 3);
		REQUIRE(array.capacity == 4);

		REQUIRE(array.data[0] == 1);
		REQUIRE(array.data[1] == 2);
		REQUIRE(array.data[2] == 3);
	}

	freeMemory(array);
}

TEST_CASE("Array: remove")
{
	Array array{};

	SECTION("Removing an element from a not allocated array should fail")
	{
		bool successful = removeElement(array, 0);
		REQUIRE_FALSE(successful);
	}

	SECTION("Removing an element from an empty array should fail")
	{
		allocateMemory(array);

		bool successful = removeElement(array, 0);
		REQUIRE_FALSE(successful);
	}

	SECTION("Removing an element from a non-existing position should fail")
	{
		allocateMemory(array);

		addElement(array, 1);
		addElement(array, 2);
		addElement(array, 3);

		bool successful = removeElement(array, 3);

		CHECK_FALSE(successful);

		REQUIRE(array.size == 3);
		REQUIRE(array.capacity == 4);

		REQUIRE(array.data[0] == 1);
		REQUIRE(array.data[1] == 2);
		REQUIRE(array.data[2] == 3);
	}

	SECTION("Removing an element from an existing position")
	{
		allocateMemory(array);

		addElement(array, 1);
		addElement(array, 2);
		addElement(array, 3);

		bool successful = removeElement(array, 1);

		REQUIRE(successful);
		
		REQUIRE(array.size == 2);
		REQUIRE(array.data[0] == 1);
		REQUIRE(array.data[1] == 3);
	}

	freeMemory(array);
}

