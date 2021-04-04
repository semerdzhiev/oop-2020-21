#ifndef DEMPLOYEE_H_INCLUDED
#define DEMPLOYEE_H_INCLUDED

class DEmployee
{
	public:
		DEmployee(const char* newName, const char* newPosition, double salary);
		DEmployee(const DEmployee& other);
		DEmployee& operator=(const DEmployee& other);
		~DEmployee();

		const char* getName() const;
		const char* getPosition() const;
		double getSalary() const;

		void setName(const char* newName);
		void setPosition(const char* newPosition);
		// the salary is valid when it is in the interval [610; 10000]
		void setSalary(double newSalary);

		void print() const;

	private:
		char* name;
		char* position;
		double salary;
};

#endif // !DEMPLOYEE_H_INCLUDED
