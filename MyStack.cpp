#include "MyStack.h"
#include <stdexcept>
#include <iostream>
#include <exception>

MyStack::MyStack(int size){
	arr = new int[size];
	top = -1;
	this->size = size;
}

bool MyStack::IsFull(){
	return top == size - 1;
}
bool MyStack::IsEmpty()
{
	return top == -1;
}
void MyStack::Push(int value)
{
	if (IsFull())
		throw std::out_of_range("Stack is full");
	
	arr[++top] = value;
}
int MyStack::Top()
{
	if (IsEmpty())
		throw std::out_of_range("Stack is empty");

	return arr[top];
}
int MyStack::Length() {
	return top + 1;
}
int MyStack::Size() {
	return size;
}
void MyStack::Pop()
{
	if (IsEmpty())
		throw std::out_of_range("Stack is empty");
	top--;
}
MyStack::~MyStack()
{
	delete[] arr;
}


void MyStack::TestBehavior()
{
    std::cout << "===== Testing MyStack =====\n" << std::endl;

    MyStack s(5);

    try
    {
        std::cout << "-> Try Pop on empty stack\n";
        s.Pop();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n\n";
    }

    std::cout << "-> Push 1,2,3,4,5\n";
    for (int i = 1; i <= 5; i++)
        s.Push(i);

    std::cout << "Length: " << s.Length() << "\n";
    std::cout << "Top: " << s.Top() << "\n";

    try
    {
        std::cout << "\n-> Try Push when full\n";
        s.Push(6);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n-> Pop two elements\n";
    s.Pop();
    s.Pop();

    std::cout << "Top after two pops: " << s.Top() << "\n";
    std::cout << "Length now: " << s.Length() << "\n";

    std::cout << "\n-> Pop remaining elements\n";
    while (!s.IsEmpty())
    {
        std::cout << "Top: " << s.Top() << "\n";
        s.Pop();
    }

    try
    {
        std::cout << "\n-> Try Top on empty stack\n";
        s.Top();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n===== Stack Test Finished Successfully =====\n";
}