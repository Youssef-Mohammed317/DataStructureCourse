#pragma once
#include <stdexcept>
class MyStack
{
private:
	int* arr;
	int top;
	int size;
public:
	MyStack(int size = 10);

	void Push(int value);
	int Top();
	void Pop();
	bool IsFull();
	bool IsEmpty();
	int Length();
	int Size();	
	void Show();
	static void TestBehavior();
	~MyStack();
};

