#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

const size_t nameMaxLength = 20;
const size_t positionMaxLength = 20;
const size_t maxWorkExperience = 40;

class Employee
{
	// what can we do with an instance of an Employeee?
	public:

		// default constructor, the data members will be initialized with the default values
		Employee() = default;

		// constructor
		// responsible for the initialization of all data members with VALID values
		// no return type, did you notice the name?
		// the same as the name of the class

		Employee(size_t id, const char* name, const char* position, unsigned int workExperience, double wage);

		// define public methods to access and modify the position
		void setID(size_t newID);
		// pay attention to the const at the end of the function declaration
		// the current object will not be changed when this function is used
		size_t getID() const;

		void setName(const char* newName);
		const char* getName() const;

		void setPosition(const char* newPosition);
		const char* getPosition() const;

		void setWorkExperience(size_t newWorkExperient);
		size_t getWorkExperience() const;

		void setWage(double newWage);
		double getWage() const;

		void showInfo() const;

	private:
		size_t id{ 0 };
		char name[nameMaxLength]{};
		char position[positionMaxLength]{};
		size_t workExperience{ 0 };
		double wage{ 0.0 };
};

#endif // !EMPLOYEE_H_INCLUDED
