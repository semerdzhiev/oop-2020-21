// convert
// c++ casts
// files


#include <iostream>

struct Wrapper {
	int value;
	Wrapper(int v): value(v) {}

	int getValue() {
		return value;
	}
};

void print(const Wrapper &w) {
	Wrapper &ref = const_cast<Wrapper &>(w);
	ref.value = 17;
	// Wrapper &ref = (Wrapper &)w; // c-style cast
	std::cout << ref.getValue();
}

void print(const int &p) {
	int &ref = const_cast<int&>(p);
	ref = 7;
}

struct Widget {
	int i1;
	short s;
	int i2;
};


int main() {

	int a = 3.14;
	int b = (int)3.14; // c-style cast
	// static_cast
	// const_cast
	// reinterpret_cast
	// dynamic_cast
	double pi = 3.14;
	int c = static_cast<int>(pi);
	int r = int(pi); // c-style cast 
	Wrapper p = Wrapper(3); // looks like c-style cast


	std::cout << a << ' ' << b << ' ' << c;

	//print(w);

	const double x = 20;

	//float &refF = (float &)f; // 1 - int -> float, remove const
	//int &xRef = const_cast<int &>(x);

	//int f1 = (int)f;
	//f1 = 13;
	//std::cout << f;

	const int f = 3;
	print(f);
	int &f2 = const_cast<int&>(f);
	f2 = 7;
	std::cout << "f=" << f << " f2=" << f2 << std::endl;

	int value = 3;
	std::cout << "before value=" << value << std::endl;
	print(value);
	std::cout << "after value=" << value << std::endl;

	
	const Wrapper w(3);
	Wrapper &ref = const_cast<Wrapper&>(w);
	ref.value = 7;
	std::cout << "w=" << w.value << " ref=" << ref.value << std::endl;

	const Wrapper w2(10);
	// error C2440: 'const_cast': cannot convert from 'const Wrapper' to 'Wrapper *'
	// Wrapper *ptr = (Wrapper*)w2;
	Wrapper *ptr = const_cast<Wrapper*>(&w2);
	//                                  ^^^ const Wrapper *
	ptr->value = 22;
	std::cout << "w=" << w2.value << " ref=" << ptr->value << std::endl;

	const char * str = "aaaabbbb";
	const char charArr[] = {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b'}; // no \0

	{
		char a = 'a';
		//std::cout << int(a);
		for (int c = 0; c < 8; c++) {
			// c = 0
			std::cout << ((a >> 8 - c - 1) & 1);
		}
		int x = ('a' << 24) | ('a' << 16) | ('a' << 8) | 'a';
		std::cout << x << std::endl;;
		
		std::cout << "str=" << str << std::endl;
		const int *intArr = reinterpret_cast<const int *>(str);
		std::cout << "intArr[0]=" << intArr[0] << std::endl;
		std::cout << "intArr[1]=" << intArr[1] << std::endl;

		float value = 3.14f;
		std::cout << "float " << value << std::endl;
		int &iValue = reinterpret_cast<int&>(value);
		std::cout << "iValue " << iValue << std::endl;

		int &iValue2 = (int&)value;
		std::cout << "iValue2 " << iValue2 << std::endl;

		int i2 = static_cast<int>(value);
		std::cout << "i2 " << i2 << std::endl;	
	}
	
	{
		Widget w{7, 8, 9};
		short *arr = reinterpret_cast<short*>(&w);
		for (int c = 0; c < 6; c++) {
			std::cout << arr[c] << ' ';
		}
		arr[3] = 13; // the padding
		arr[0] = 33;
		std::cout << std::endl;

		std::cout << w.i1 << " " << w.s << " " << w.i2 << std::endl;
		for (int c = 0; c < 6; c++) {
			std::cout << arr[c] << ' ';
		}
	}
	
	
	return 0;
}
