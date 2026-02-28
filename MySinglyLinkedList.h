#pragma once

class SinglyNode
{
private:
	int value;
	SinglyNode* next;
public:
	SinglyNode(int value);
	int GetValue();
	void SetNext(SinglyNode* SinglyNode);
	SinglyNode* GetNext();
	~SinglyNode();
};

class MySinglyLinkedList
{
private:
	int length;
	SinglyNode* header;
public:
	MySinglyLinkedList();
	void InsertAtTheBeginning(int value);
	void InsertAtEnd(int value);
	void InsertAtIndex(int index,int value);
	void DeleteFromBeginning();
	void DeleteFirstMatchedValue(int value);
	void DeleteLastMatchedValue(int value);
	void DeleteByIndex(int index);
	int Search(int value); // return index
	int GetByIndex(int index); // return value
	void Display(); // print list

	static void TestBehavior();
	~MySinglyLinkedList();
};

