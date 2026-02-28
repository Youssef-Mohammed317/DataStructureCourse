#pragma once
class MyCircularQueue
{
private:
	int* arr;
	int size;
	int length;
	int rear;
	int front;
public:
	MyCircularQueue(int size = 10);
	bool IsEmpty();
	bool IsFull();
	int Front();
	void Enqueue(int value);
	void Dequeue();
	int Length();
	int Size();
	static void TestBehavior();
	~MyCircularQueue();
};

