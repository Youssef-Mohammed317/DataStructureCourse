#include "MyLinearQueue.h"
#include <stdexcept>
#include <iostream>
#include <exception>

MyLinearQueue::MyLinearQueue(int size) {
	arr = new int[size];
	rear = -1;
	front = 0;
	length = 0;
	this->size = size;
}
bool MyLinearQueue::IsEmpty() {
	return length == 0;
}
bool  MyLinearQueue::IsFull() {
	return rear == size - 1;
}
int  MyLinearQueue::Front() {
	if (IsEmpty())
		throw std::out_of_range("The queue is empty");
	return arr[front];
}
void MyLinearQueue::Enqueue(int value)
{
	if (IsFull())
		throw std::out_of_range("The queue is full");

	arr[++rear] = value;
	length++;
}
void MyLinearQueue::Dequeue()
{
	if (IsEmpty())
		throw std::out_of_range("The queue is empty");

	front++;
	length--;
}
int MyLinearQueue::Length() {
	return length;
}
int MyLinearQueue::Size() {
	return size;
}
MyLinearQueue::~MyLinearQueue() {
	delete[] arr;
}


void MyLinearQueue::TestBehavior()
{
    std::cout << "===== Testing MyLinearQueue =====\n" << std::endl;

    MyLinearQueue q(5);

    try
    {
        std::cout << "-> Try Dequeue on empty queue\n";
        q.Dequeue();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n\n";
    }

    std::cout << "-> Enqueue 1,2,3,4,5\n";
    for (int i = 1; i <= 5; i++)
        q.Enqueue(i);

    std::cout << "Length: " << q.Length() << "\n";
    std::cout << "Front: " << q.Front() << "\n";

    try
    {
        std::cout << "\n-> Try Enqueue when full\n";
        q.Enqueue(6);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n-> Dequeue two elements\n";
    q.Dequeue();
    q.Dequeue();

    std::cout << "Length after 2 dequeues: " << q.Length() << "\n";
    std::cout << "Front now: " << q.Front() << "\n";

    std::cout << "\n-> Try Enqueue again (Linear behavior test)\n";
    try
    {
        q.Enqueue(6);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception (expected in linear queue): "
            << e.what() << "\n";
    }

    std::cout << "\n-> Dequeue remaining elements\n";
    while (!q.IsEmpty())
    {
        std::cout << "Front: " << q.Front() << "\n";
        q.Dequeue();
    }

    try
    {
        std::cout << "\n-> Try Front on empty queue\n";
        q.Front();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n===== Linear Queue Test Finished Successfully =====\n";
}