#include "Item.h"
#include "Order.h"

#include <iostream>

int main()
{
	Item* pApple = nullptr;
	Item* pBanana = nullptr;

	try
	{
		Item banana{ "12344", "banana", 3 };
		pBanana = &banana;

		pApple = new Item{ "12345", "apple", 2.50 };

		Item pear{ "12346", "pear", -3 };

		Item kiwi{ "12347", "kiwi", 3 };
		std::cout << "Kiwi!" << std::endl;
	}
	catch (const std::exception& ex)
	{
		delete pApple;
		pApple = nullptr;

		std::cerr << "Exception has been caught: " << ex.what() << std::endl;
	}

	delete pApple;

	std::cout << "After the try-catch block!" << std::endl;


	Item item;

	return 0;
}

