#include "guerra_jotony_A10.h"

using namespace std;


//Default Constructor
myStack::myStack()
{
	head = NULL;
}

//Constructor with int parameter.
myStack::myStack(int size)
{
	node * temp;
	temp = new node;
	head = temp;
	temp->link = NULL;

	for(int i = 0; i < size- 1; i++)
	{
		temp -> link = new node;
		temp -> link = NULL;
		temp = temp-> link;
	}

	temp = NULL;
}

//DEEP COPY FUNCTION
myStack::myStack(const myStack& copy)
{
	head = new node;
	head-> item= copy.head-> item;
	head->link = NULL;
	node * x = copy.head;
	node * y = head;


	while(y->link != NULL)
	{
		x = x -> link;
		y->link = new node;
		y = y -> link;
		y-> item = x->item;
		y-> link = NULL;
	}

}

//Equal overlaod function.
const myStack& myStack::operator=(const myStack& rhs)
{
	if(this!= &rhs)// The following statment checks for self assignment
	{
		myStack(rhs);

		return *this;
		//from the book.
		//this.myStack(rhs);
	}
}

//Destructor
myStack::~myStack()
{
	//idk bout this.
	while(head != NULL)
	{
		node * x = head;
		head = head -> link;
		delete x;
	}

}

//return bool if empty.. nead to work on this
bool myStack::isEmpty() const
{
	if(head == NULL)
		return true;
	else
		return false;
}

//Push function. Accepts int as a parameter that is pushed into the top of the stack.

void myStack::push(int element)
{
	node * insert;
	insert = new node;
	insert -> item = element;

	insert -> link = head;
	head =  insert;
	//head -> link;
	insert = NULL;
}

//returns top of stack.
int myStack::top() const
{
	if(head != NULL)
		return head->item;

}

//need to finish the pop function
void myStack::pop()
{
	node * temp;
	if( !isEmpty() )
	{
		//node * temp
		temp = head;
		head = temp-> link;

		delete temp;
		
	}
}

