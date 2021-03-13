#pragma once
class Stack {
private:
	int* arr;
	int size; // current count of the elements in arr
	int maxSize; // size of the arr
	void deleteObj();
	void createObj(const Stack& stack1);
public:
	Stack();
	Stack(const Stack& stack1);
	Stack& operator=(const Stack& stack1);
	~Stack();
	Stack(int maxSize);
	bool push(int el);
	bool pop();
	int top() const;
	int getSize();
};