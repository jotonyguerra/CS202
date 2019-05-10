#include <iostream>
#include "./myStack.h"

using namespace std;

// is the default constructor that sets stk to NULL and sets stkTop and capacity to 0
myStack::myStack()
{
	stk= NULL;
	stkTop=0;
	capacity=0;

}

// is the constructor that sets stkTop to 0, capacity to size and assigns a char array of length size to stk
myStack::myStack(int size)
{
	stkTop=0;
	capacity= size;
	stk= new char[size];


}

// perfroms a deep copy of copy object to the *this object
myStack::myStack(const myStack& copy)
{
	this->capacity= copy.capacity;

	stk= new char[capacity];

	for(int i=0; i< capacity; i++)
	{
		stk[i]= copy.stk[i];
	}

}

// is the assignment operator that performs a deep copy of the right hand side object to the *this object
const myStack& myStack::operator=(const myStack& rhs)
{
	if(this != &rhs)
	{
		if(stk != NULL)
		{
			delete [] stk;
		}
		 capacity= rhs.capacity;
		 stk= new char[capacity];

		 for(int i=0; i< capacity; i++)
		 {
		 	stk[i]= rhs.stk[i];
		 }
	}

	return *this;
}

// is the destructor that deallocates the dynamic array
myStack::~myStack()
{
	if(stk != NULL)
	{
		delete [] stk;
	}

}

// is a function that inserts item to position stkTop position of stk array and increments stkTop index
void myStack::push(char item)
{
	stk[stkTop]=item;
	stkTop++;

	if(stkTop== capacity)
	{
		capacity= capacity * 2;
	}

}

// returns the top item of the stack, the item at position stk[stkTop -1]
char myStack::top() const
{
	return stk[stkTop -1];
}

// removes the top item from the stack
void myStack::pop()
{
	if(stkTop!= 0)
	{
		stkTop--;
	}

	else
	{
		return;

	}

}

// returns true if the stack is empty and false if it is not empty
bool myStack::isEmpty() const
{
	bool check= false;

	if(stkTop== 0)
	{
		check = true;
	}

	return check;

}
