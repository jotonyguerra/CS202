#include <iostream>
#include <cstdlib>
#include "guerra_jotony_A9.h"
using namespace std;

//default constructor
myStack::myStack()
{
  stk = NULL;
  stkTop = 0;
  capacity = 0;
}

//Constructor that takes int paramater
myStack::myStack(int size)
{
  stk = new char[size];
  capacity = size;
  stkTop = 0;
}

//myStack::myStack(const myStack& copy)

//The copy constructor just creates a deep copy of the object passed into the constructor, so basically it just
//enqueues new items into the queue one at a time until the queue has been copied.
myStack::myStack(const myStack& copy)
{
  stk = NULL;
  this->capacity = copy.capacity;

  stk = new char[capacity];

  for (int i = 0; i < capacity; i++)
    stk[i] = copy.stk[i];
}

//operator = overload.
const myStack& myStack::operator=(const myStack& rhs)
{
  
  if (this != &rhs) //check for self assignment
    {
      if (stk != NULL)
        delete [] stk;
    }

  stk = NULL;
  capacity = 0;
  stkTop = 0;

  if(rhs.stk != NULL)
  {

      capacity = rhs.capacity;
      stk = new char[capacity];

      for (int i = 0; i < capacity; i++)
        stk[i] = rhs.stk[i];
  }
  return *this;  //b1 = b2 = b3 = b4;
}


//a function that inserts item to position stkTop position of stk
//array and the increments stkTop index, you will need to resize if the stack is full, resize the stack by
//doubling its capacity
void myStack::push(char item) 
{
  stk[stkTop] = item;
  stkTop++;

  if(stkTop == capacity)
    capacity = capacity * 2;

}

char myStack::top() const 
{
  return stk[stkTop - 1];
}
 //returns the top item of the stack, the item at position stk[stkTop - 1]

void myStack::pop()
{
  if (stkTop == 0)
    return;
  else
    stkTop--; //idk yo.
} //removes the top item from the stack

//is a function that inserts item to position stkTop position of stk
//array and the increments stkTop index, you will need to resize if the stack is full, resize the stack by
//doubling its capacity

bool myStack::isEmpty() const
{
  if(stkTop == 0)
    return true;
  else
    return false;

}

//Destructor
myStack::~myStack() 
{
  if (stk != NULL)
    delete [] stk;

}

