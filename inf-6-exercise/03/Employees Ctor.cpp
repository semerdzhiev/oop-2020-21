#include <iostream>
#include <iomanip>

const size_t nameMaxLength = 20;
const size_t positionMaxLength = 20;
const size_t maxWorkExperience = 40;

struct Employee
{
	// the data members are hidden, 
	// how can we assign new value to a particular data member or check the current value?
	private:
		// default values for each of the data members
		size_t id{ 0 };
		char name[nameMaxLength]{};
		char position[positionMaxLength]{};
		unsigned int workExperience{ 0 };
		double wage{ 0.0 };

	// what can we do with an instance of an Employeee?
	public:
		
		// constructor
		// responsible for the initialization of all data members with VALID values
		// no return type, did you notice the name?
		// the same as the name of the structure

		Employee(size_t id, const char* name, const char* position, unsigned int workExperience, double wage);

		// define public methods to access and modify the position
		void setPosition(const char* newPosition);
		const char* getPosition();

		// what about the rest of the data members?

		// use the standard input to assign values to the data members
		void read();
		void print();
};

// this is a constant pointer to the very employee to which the method is applied
Employee::Employee(size_t id, const char* name, const char* position, unsigned int workExperience, double wage)
{
	// validate the values of the input arguments 
	// valid values should be assigned to all data members

	this->id = id;

	if (name)
	{
		// this->name = name;
		strcpy_s(this->name, nameMaxLength, name);
	}

	if (position)
	{
		strcpy_s(this->position, positionMaxLength, position);
	}

	if (workExperience >= 0 && workExperience <= 40)
	{
		this->workExperience = workExperience;
	}

	if (wage > 0)
	{
		this->wage = wage;
	}
}

void Employee::read()
{
	std::cout << "ID: ";
	std::cin >> this->id;

	// why do we need this?
	std::cin.ignore();

	std::cout << "Name: ";
	std::cin.getline(this->name, nameMaxLength);

	std::cout << "Position: ";
	std::cin.getline(this->position, positionMaxLength);

	// Lets suppose that the experience is in the range [0; 40]
	std::cout << "Work experience [1; " << maxWorkExperience << "]: ";
	do
	{
		std::cin >> this->workExperience; // asd123 2345

		if (!std::cin)
		{
			std::cin.clear();
		}

		// ignore what is left in the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (this->workExperience < 1 || this->workExperience > maxWorkExperience);

	// some validation of the input is necessary here
	std::cout << "Wage: ";
	std::cin >> this->wage;
}

void Employee::print()
{
	std::cout << std::setw(5) << this->id
		<< std::setw(20) << this->name
		<< std::setw(20) << this->position
		<< std::setw(10) << this->workExperience
		<< std::setw(10) << std::setiosflags(std::ios::fixed) << std::setprecision(2) << this->wage << std::endl;
}

void Employee::setPosition(const char* newPosition)
{
	if (newPosition)
	{
		strcpy_s(this->position, positionMaxLength, newPosition);
	}
}

const char* Employee::getPosition()
{
	return this->position;
}

int main()
{
	// Employee e[2];
	Employee e[2]{ {1, "Me", "Teacher", 15, 50}, {2, "You", "Programmer", 5, 150} };

	// this is connected to e[0] when createEmployee function is being executed 
	std::cout << "e[0]: ";
	e[0].print();

	// here, this will point to e[1]
	std::cout << "e[1]: ";
	e[1].print();

	std::cout << "---  e[0] has changed poisitons... " << std::endl;
	e[0].setPosition("Accountant");
	e[0].print();
	//std::cout << e[0].getPosition();

	return 0;
}
