#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

class Set
{
	public:
		Set() = default;
		Set(const Set& other);
		Set& operator=(const Set& other);
		Set(Set&& other) noexcept;
		Set& operator=(Set&& other) noexcept;
		~Set();

		// s1 += 2
		// s1.operator+=(2)
		Set& operator+=(int element);

		// s1 += s2
		Set& operator+=(const Set& right);

		// s[2]
		int& operator[](size_t position);
		const int& operator[](size_t position) const;
		
		// s1(x) - > x is in the set
		bool operator()(int element) const;

	private:
		int* elements{ nullptr };
		size_t numberOfElements{ 0 };

	private:
		void copy(const Set& other);
		void clear();
};

// s1 + 2
Set operator+(const Set& left, int right);

// s1 - s2
// s1 * s2

// ==, !=, < , <=, >, >=
// >>, <<

#endif SET_H_INCLUDED