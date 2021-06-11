/*
class 				A: print() = 0
			      /   \
	print = 0    B     C: print() = 0
			       \  /
			        D print() {}
    
    Problem 1: same methods - Which implementation should we use?
    D::print() {
    	B::print();
    	C::print();
    }
    Problem 2: same state - Which memory should we use?


Inheritance - why do we use it?
	- code reusability
		= we prefer Composition over Inheritance
	- common state
		= we prefer Composition over Inheritance


	- expresses the relation between two classes (is-a)
	- polymorphism

interface = чисто абстрактен клас, който няма и член данни.
*/

/*
				Person
					name
					phone
					email

		Student			Teacher
			fn				department
				\         /
			TechnicalAssistant
*/


#include <iostream>
using namespace std;

class Person {
public:
	Person(string name, string phone, string email) {
 		this->name = name;
		this->phone = phone;
		this->email = email;
	}

	string getName() const {
		return this->name;
	}

	string getPhone() const {
		return this->phone;
	}

	string getEmail() const {
		return this->email;
	}

	virtual void print() {
		cout << "Person: {"
			 << " name: " << this->name
		 	 << " phone: " << this->phone 
		 	 << " email: " << this->email 
		     << " }" << endl;
	}

	virtual ~Person() {
		cout << "deleting ";
		print();
	}

private:
	string name;
	string phone;
	string email;
};

class Student : public Person {
public:
	Student(string name, string phone, string email, string fn) : Person(name, phone, email) {
		this->fn = fn;
	}

	virtual ~Student() {
		cout << "deleting ";
		print();
	}

	string getFN() const {
		return fn;
	}

	virtual void print() {
		cout << "Student: {"
			 << " name: " << this->getName()
		 	 << " phone: " << this->getPhone()
		 	 << " email: " << this->getEmail()
		 	 << " fn: " << this->getFN()
		     << " }" << endl;
	}
private:
	string fn;	
};

class Teacher : public Person {
public:
	Teacher(string name, string phone, string email, string department) : Person(name, phone, email) {
		this->department = department;
	}

	virtual ~Teacher() {
		cout << "deleting ";
		print();
	}

	string getDepartment() const {
		return department;
	}

	virtual void print() {
		cout << "Teacher: {"
			 << " name: " << this->getName()
		 	 << " phone: " << this->getPhone()
		 	 << " email: " << this->getEmail()
		 	 << " department: " << this->getDepartment()
		     << " }" << endl;
	}
private:
	string department;	
};

class TechnicalAssistant : public Student, public Teacher {
public:
	TechnicalAssistant(string name, string phone, string email, string fn, string department):
		Student(name, phone, email, fn), 
		Teacher(name, phone, email, department) {
	}

	virtual ~TechnicalAssistant() {
		cout << "deleting ";
		print();
	}

	virtual void print() {
		cout << "TechnicalAssistant: {"
			 << " name: " << Student::getName()
		 	 << " phone: " << Student::getPhone()
		 	 << " email: " << Student::getEmail()
		 	 << " fn: " << Student::getFN()
		 	 << " department: " << Teacher::getDepartment()
		     << " }" << endl;
	}
};

int main() {
	Person* people[] = {
		new Person("Pesho", "1234", "pesho@abv.bg"),
		new Student("Ivan", "12345", "ivan@abv.bg","fn007"),
		new Teacher("Dimitar", "123456", "dimitar@abv.bg", "cs"),
		(Student*) new TechnicalAssistant("Maria", "12345678", "maria@abv.bg", "fn008", "cs")
	};

	for (int i = 0; i < 4; i++) {
		people[i]->print();
	}

	for (int i = 0; i < 4; i++) {
		delete people[i];
	}

	return 0;
}