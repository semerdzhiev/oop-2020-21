#include <iostream>

class Test
{
		int x;
		int id;
		
		static int countLivingObject;
		static int nextID;

	public:
		Test(int x) : x(x), id(getNextID())
		{ 
			++countLivingObject; 
		}

		Test(const Test& other) : x(other.x), id(getNextID())
		{ 
			++countLivingObject; 
		}

		~Test() { --countLivingObject; }

		int getX() const { return this->x; }
		int getID() const { return this->id; }

		// статичната функция не може да бъде константна
		static int getCountLivingObjects() 
		{
			return countLivingObject;
		}

		static int getNextID()
		{
			return nextID++;
		}
};

int Test::countLivingObject = 0;
int Test::nextID = 1;

int main()
{
	{
		Test t{ 2 };
		std::cout << t.getID() << std::endl;

		Test copy{ t };
		std::cout << Test::getCountLivingObjects() << std::endl;
		std::cout << copy.getID() << std::endl;
	}
	
	Test t1{ 3 };
	std::cout << Test::getCountLivingObjects() << std::endl;
	std::cout << t1.getID() << std::endl;

	return 0;
}