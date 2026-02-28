#include "MyCircularQueue.h"
#include<stdexcept>
#include <iostream>
#include <exception>

MyCircularQueue::MyCircularQueue(int size)
{
	arr = new int[size];
	this->size = size;
	length = 0;
	front = 0;
	rear = -1;
}
bool MyCircularQueue::IsEmpty()
{
	return length == 0;
}
bool MyCircularQueue::IsFull()
{
	return length == size;	// can replace this by use this full condition: front == (rear + 1) % size
}
int MyCircularQueue::Front()
{
	if (IsEmpty())
		throw std::out_of_range("The queue is empty");
	return arr[front];
}
void MyCircularQueue::Enqueue(int value)
{
	if(IsFull())
		throw std::out_of_range("The queue is full");

	//if (rear == size - 1)
	//	rear = -1;

	//arr[++rear] = value;

	rear = (rear + 1) % size;
	arr[rear] = value;
	length++;
}
void MyCircularQueue::Dequeue()
{
	if(IsEmpty())
		throw std::out_of_range("The queue is empty");

	//if (++front == size)
	//	front = 0;

	front = (front + 1) % size;
	length--;
}
int MyCircularQueue::Length()
{

	return length;
}
int MyCircularQueue::Size()
{
	return size;
}

MyCircularQueue::~MyCircularQueue()
{
	delete[]arr;
}


void MyCircularQueue::TestBehavior()
{
    std::cout << "===== Testing MyCircularQueue =====\n" << std::endl;

    MyCircularQueue q(5);

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

    try
    {
        std::cout << "\n-> Try Enqueue when full\n";
        q.Enqueue(6);
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n-> Front element: " << q.Front() << std::endl;

    std::cout << "\n-> Dequeue two elements\n";
    q.Dequeue();
    q.Dequeue();

    std::cout << "Front after two dequeues: " << q.Front() << std::endl;

    std::cout << "\n-> Enqueue 6 and 7 (wrap around test)\n";
    q.Enqueue(6);
    q.Enqueue(7);

    std::cout << "Front now: " << q.Front() << std::endl;

    std::cout << "\n-> Dequeue all elements\n";
    while (!q.IsEmpty())
    {
        std::cout << "Front: " << q.Front() << std::endl;
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

    std::cout << "\n===== Queue Test Finished Successfully =====" << std::endl;
}