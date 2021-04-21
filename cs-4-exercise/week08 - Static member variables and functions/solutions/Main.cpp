#include <iostream>

class B {
private:
	static int s_idGenerator;

public:
	static int getId();
};

int B::s_idGenerator = 1000;

int B::getId() {
	return s_idGenerator++;
}

class A {
private:
	static int s_idGenerator;
	int m_id;

public:
	A() {
		m_id = B::getId();
	}

	int getId() const {
		return m_id;
	}

};

int A::s_idGenerator = 1;


int main() {

	A a1;
	A a2;
	A a3;

	std::cout << a1.getId() << std::endl;
	std::cout << a2.getId() << std::endl;
	std::cout << a3.getId() << std::endl;


	return 0;
}