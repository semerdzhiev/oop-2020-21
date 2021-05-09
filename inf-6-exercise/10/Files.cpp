#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <limits>

int readNumbersFromTextFile()
{
	std::ifstream in("Numbers.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cerr << "Input file cannot be opened!" << std::endl;
		return -1;
	}

	while (in)
	{
		int number = 0;
		
		in >> number;
		if (in)
		{
			std::cout << number << " ";
		}
		else if (in.eof())
		{
			std::cout << "EOF reached!" << std::endl;
		}
		else if (in.fail())
		{
			std::cout << "Wrong data format!" << std::endl;

			// последната операция е неуспешна
			in.clear();

			while (in && in.get() != ' ');

			//in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
		}
	}

	in.close();

	return 0;
}

struct Order
{
	char product[40];
	double price;
	int quantity;
};

// read an order from a text file
// each record is on a new line
// format: <product name> <tab> <quantity> <tab> <price>
bool readOrder(Order& order, std::ifstream& in)
{
	if (!in)
	{
		in.clear();
		// ще се опитаме да прочетем един запис
	}

	char product[40];
	in.getline(product, 40, '\t');

	int quantity = 0;
	in >> quantity;

	if (in.fail())
	{
		in.clear();
		// премахваме информацията за грешния запис
		while (in && in.get() != '\n');

		return false;
	}

	double price = 0;
	in >> price;
	
	if (in.fail())
	{
		in.clear();
		while (in && in.get() != '\n');

		return false;
	}

	if (in)
	{
		// ignore the new line at the end of the current record
		in.ignore();

		strcpy(order.product, product);
		order.quantity = quantity;
		order.price = price;

		return true;
	}

	return false;
}

// store the order in a binary file
void serialize(const Order& order, std::ofstream& out)
{
	if (!out)
		return;

	out.write(reinterpret_cast<const char*>(&order), sizeof(order));
}

// read an order from a binary file
bool deserialize(Order& order, std::ifstream& in)
{
	if (!in)
		return false;

	in.read(reinterpret_cast<char*>(&order), sizeof(order));

	return (in && in.gcount() == sizeof(order));
}

void filterTextFileOrders()
{
	std::ifstream in("Orders.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cerr << "Input file cannot be opened!" << std::endl;
		return;
	}

	// Filter records by price
	std::ofstream out("Filter.txt", std::ios::out);
	if(!out.is_open())
	{
		std::cerr << "The output file cannot be opened!" << std::endl;
		return;
	}

	while (in)
	{
		Order currentOrder{};
		if (readOrder(currentOrder, in))
		{
			if (currentOrder.price > 20.00)
			{
				// use the same format as in the readOrder function...
				out << currentOrder.product << '\t' << currentOrder.quantity << '\t' << currentOrder.price << '\n';
			}
		}
	}

	in.close();
	out.close();
}

void convertTextFileOrdersIntoBinary()
{
	std::ifstream in("Filter.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cerr << "Input file cannot be opened!" << std::endl;
		return;
	}

	// Filter records by price
	std::ofstream out("Filter.dat", std::ios::out | std::ios::binary);
	if (!out.is_open())
	{
		std::cerr << "The output file cannot be opened!" << std::endl;
		return;
	}

	while (in)
	{
		Order currentOrder{};
		if (readOrder(currentOrder, in))
		{
			serialize(currentOrder, out);
		}
	}

	in.close();
	out.close();
}

void showBinaryFileOrders()
{
	std::ifstream in("Filter.dat", std::ios::in | std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "Input file cannot be opened!" << std::endl;
		return;
	}

	while (in)
	{
		Order currentOrder{};
		if (deserialize(currentOrder, in))
		{
			std::cout << currentOrder.product << '\t' << currentOrder.quantity << '\t' << currentOrder.price << '\n';
		}
	}

	in.close();
}

int main()
{
	//readNumbersFromTextFile();
	
	//filterTextFileOrders();

	convertTextFileOrdersIntoBinary();
	showBinaryFileOrders();
}