#pragma once

class MyLinearQueue
{
private:
	int* arr;
	int rear;
	int front;
	int size;
	int length;
public:
	MyLinearQueue(int size = 10);
	bool IsEmpty();
	bool IsFull();
	int Front();
	void Enqueue(int value);
	void Dequeue();
	int Length();
	int Size();
	static void TestBehavior();
	~MyLinearQueue();
};

