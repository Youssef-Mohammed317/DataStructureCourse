#include <iostream>
#include "MySinglyLinkedList.h"
#include "MyCircularQueue.h"
#include "MyLinearQueue.h"
#include "MyStack.h"

int main()
{
    MyStack::TestBehavior();
    MyLinearQueue::TestBehavior();
    MyCircularQueue::TestBehavior();
    MySinglyLinkedList::TestBehavior();   
    return 0;
}