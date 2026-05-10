#include "QueType.h"
#include <iostream>
using namespace std;

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
  items = new ItemType[maxQue];
  length = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (length == maxQue - 1);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
    length++;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
    length--;
  }
}

int QueType::GetLength() const
{
  return length;
}

void QueType::PrintQueue() const
{
    if (IsEmpty())
    {
      cout << "[empty]";
      return;
    }

    int i = (front + 1) % maxQue;
    int count = 0;

    while (count < length)
    {
      cout << items[i] << " ";
      i = (i + 1) % maxQue;
      count++;
    }
}