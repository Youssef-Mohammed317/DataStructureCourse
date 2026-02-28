#include "MySinglyLinkedList.h"
#include<iostream>
#include<stdexcept>
#include <exception>

SinglyNode::SinglyNode(int value)
{
	this->value = value;
	this->next = nullptr;
}
int SinglyNode::GetValue() {
	return value;
}
SinglyNode* SinglyNode::GetNext()
{
	return next;
}
void SinglyNode::SetNext(SinglyNode* SinglyNode)
{
	next = SinglyNode;
}
SinglyNode::~SinglyNode()
{
}

MySinglyLinkedList::MySinglyLinkedList()
{
	this->length = 0;
	this->header = nullptr;
}
void MySinglyLinkedList::InsertAtTheBeginning(int value)
{
	if (header == nullptr)
	{
		header = new SinglyNode(value); 
		length++;
		return;
	}
	SinglyNode* newNode = new SinglyNode(value);
	newNode->SetNext(header);
	header = newNode;
	length++;
}
void MySinglyLinkedList::InsertAtEnd(int value) {
	
	if (header == nullptr)
	{
		header = new SinglyNode(value); 
		length++;
		return;
	}

	SinglyNode* current = header;
	while (current->GetNext() != nullptr)
	{
		current = current->GetNext();
	}
	current->SetNext(new SinglyNode(value)); 
	length++;
}
void MySinglyLinkedList::InsertAtIndex(int index, int value) {
	
	if (index < 0 || index > length)
		throw std::out_of_range("Index out of range");


	if (index == 0)
	{
		InsertAtTheBeginning(value);
		return;
	}

	SinglyNode* current = header;

	for (int i = 0; i < index - 1; i++)
	{
		if(current->GetNext() != nullptr)
			current = current->GetNext();
	}
	SinglyNode* newNode = new SinglyNode(value);
	newNode->SetNext(current->GetNext());
	current->SetNext(newNode);
	length++;
}
void MySinglyLinkedList::DeleteFromBeginning()
{
	if (header == nullptr)
		throw std::out_of_range("The list is empty");
	SinglyNode* temp = header;
	header = header->GetNext();
	length--;
	delete temp;
}
void MySinglyLinkedList::DeleteFirstMatchedValue(int value)
{
	if (header == nullptr)
		throw std::out_of_range("The list is empty");

	SinglyNode* current = header;
	SinglyNode* prev = nullptr;
	SinglyNode* firstMatched = nullptr;
	SinglyNode* firstMatchedPrev = nullptr;
	while (current != nullptr)
	{
		if (current->GetValue() == value)
		{
			firstMatched = current;
			firstMatchedPrev = prev;
			break;
		}
		prev = current;
		current = current->GetNext();
	}

	if (firstMatched == nullptr)
	{
		throw std::out_of_range("This value not found");
	}

	if (firstMatchedPrev == nullptr) // first SinglyNode matched
	{
		SinglyNode* temp = header;
		header = header->GetNext();
		length--;
		delete temp;
		return;
	}
	firstMatchedPrev->SetNext(firstMatched->GetNext());
	length--;
	delete firstMatched;
}


void MySinglyLinkedList::DeleteLastMatchedValue(int value)
{
	if (header == nullptr)
		throw std::out_of_range("The list is empty");

	SinglyNode* current = header;
	SinglyNode* prev = nullptr;
	SinglyNode* lastMatched = nullptr;
	SinglyNode* lastMatchedPrev = nullptr;
	while (current != nullptr)
	{
		if (current->GetValue() == value)
		{
			lastMatched = current;
			lastMatchedPrev = prev;
		}
		prev = current;
		current = current->GetNext();
	}

	if (lastMatched == nullptr)
		throw std::out_of_range("Value not found");

	if (lastMatchedPrev == nullptr) // only first SinglyNode matched
	{
		SinglyNode* temp = header;
		header = header->GetNext();
		length--;
		delete temp;
		return;
	}

	lastMatchedPrev->SetNext(lastMatched->GetNext());
	length--;
	delete lastMatched;
}

void MySinglyLinkedList::DeleteByIndex(int index)
{
	if (index < 0 || index >= length)
		throw std::out_of_range("Index out of range");

	
	if (index == 0)
	{
		SinglyNode* temp = header;
		header = header->GetNext();
		delete temp;
		length--;
		return;
	}

	SinglyNode* current = header;

	for (int i = 0; i < index - 1; i++)
		current = current->GetNext();


	SinglyNode* temp = current->GetNext();
	current->SetNext(temp->GetNext());
	delete temp;
	length--;
}
int MySinglyLinkedList::Search(int value) // return index
{	
	int index = 0;
	SinglyNode* current = header;

	while (current != nullptr)
	{
		if (current->GetValue() == value)

		{
			return index;
		}

		index++;
		current = current->GetNext();
	}
	return -1;
}
int MySinglyLinkedList::GetByIndex(int index) // return value
{
	if (header == nullptr)
		throw std::out_of_range("The list is empty");

	if (index < 0 || index >= length) {
		throw std::out_of_range("Index out of range");
	}
	SinglyNode* current = header;

	for (int i = 0; i < index; i++)
	{
		current = current->GetNext();
	}

	if (current == nullptr)
		throw std::out_of_range("Index out of range");
	
	return current->GetValue();
}
void MySinglyLinkedList::Display() // print list
{
	if (header == nullptr)
	{
		std::cout << "The list is empty" << std::endl;
		return;
	};

	std::cout << "The list is:" << std::endl;
	SinglyNode* current = header;
	int index = 0;

	while (current != nullptr)
	{
		std::cout << "at index {" << index++ << "} => value {" << current->GetValue() << "}" << std::endl;
		current = current->GetNext();

	}
}


MySinglyLinkedList::~MySinglyLinkedList()
{
	while (header != nullptr)
	{
		SinglyNode* temp = header;
		header = header->GetNext();
		delete temp;
	}
	
}


void MySinglyLinkedList::TestBehavior()
{
	std::cout << "===== Testing MySinglyLinkedList =====\n" << std::endl;

	MySinglyLinkedList list;

	try
	{
		std::cout << "-> Trying DeleteFromBeginning on empty list\n";
		list.DeleteFromBeginning();
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n\n";
	}

	std::cout << "-> InsertAtEnd\n";
	list.InsertAtEnd(10);
	list.InsertAtEnd(20);
	list.InsertAtEnd(30);
	list.InsertAtEnd(20);
	list.Display();

	std::cout << "\n-> InsertAtTheBeginning\n";
	list.InsertAtTheBeginning(5);
	list.Display();

	std::cout << "\n-> InsertAtIndex (2, 99)\n";
	list.InsertAtIndex(2, 99);
	list.Display();

	try
	{
		std::cout << "\n-> InsertAtIndex with wrong index (100)\n";
		list.InsertAtIndex(100, 50);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n-> Search(30)\n";
	int index = list.Search(30);
	if (index != -1)
		std::cout << "30 found at index: " << index << std::endl;
	else
		std::cout << "30 not found\n";

	std::cout << "\n-> Search(999) (not existing)\n";
	int wrongSearch = list.Search(999);
	if (wrongSearch == -1)
		std::cout << "999 not found (correct behavior)\n";

	try
	{
		std::cout << "\n-> GetByIndex(1)\n";
		std::cout << "Value: " << list.GetByIndex(1) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n-> GetByIndex with wrong index (50)\n";
		list.GetByIndex(50);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n-> DeleteFirstMatchedValue(20)\n";
	list.DeleteFirstMatchedValue(20);
	list.Display();

	try
	{
		std::cout << "\n-> DeleteFirstMatchedValue(999)\n";
		list.DeleteFirstMatchedValue(999);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n-> DeleteLastMatchedValue(20)\n";
	list.DeleteLastMatchedValue(20);
	list.Display();

	try
	{
		std::cout << "\n-> DeleteByIndex(2)\n";
		list.DeleteByIndex(2);
		list.Display();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n-> DeleteByIndex with wrong index (100)\n";
		list.DeleteByIndex(100);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n===== Final State =====" << std::endl;
	list.Display();

	std::cout << "\n===== Test Finished Successfully =====" << std::endl;
}
