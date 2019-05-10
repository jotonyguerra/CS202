#include <iostream>
#include "TowerSignal.h"

using namespace std;

////is the default constructor that sets head to NULL
myStack::myStack()
{
	head= NULL;

}

//is the constructor that allocates size number of nodes to the linked list
myStack::myStack(int size)
{
	node * tmp;
	tmp= new node;
	head=tmp;
	tmp->link= NULL;

	for( int i=0; i< size-1; i++)
	{
		tmp->link= new node;
		tmp->link= NULL;
		tmp= tmp->link;
	}

	tmp=NULL;

}

/*is the copy constructor that performs a deep copy of copy
object to the object being created with this constructor*/
myStack::myStack(const myStack& copy)
{
	head->item=copy.head->item;
	head->link= NULL;
	node* i= copy.head;
	node* j= head;

	while(j->link!=NULL)
	{
		i= i->link;
		j->link= new node;
		j= j->link;
		j->item= i->item;
		j->link= NULL;
	} 


}

/* is the assignment operator that will
perform a deep copy of the right hand side object to the left hand side object*/
const myStack& myStack::operator=(const myStack& rhs)
{
	if(this!= &rhs)// The following statment checks for self assignment
	{
		myStack(rhs);

		return *this;

		//this.myStack(rhs);
	}

}

//is the destructor that deallocates the linked list that starts at head
myStack::~myStack()
{
	while(head!=NULL)
	{
		node* d= head;
		head= head->link;
		delete d;
	}

}

/* allocates a new node and sets this new node’s item field to
element and inserts it to the front of the linked list*/
void myStack::push(int element)
{	
	node * insert;
	insert= new node;
	insert-> item= element;
	insert-> link= head;
	head= insert;
	insert= NULL;


}

//returns head->item
int myStack::top() const
{
	return head->item;

}

// removes the front element of the linked list if the linked list is not empty
void myStack::pop()
{
	if(head->link!=NULL)
	{
		node * tmp;
		tmp=head;
		head= head-> link;
		delete tmp;
		tmp= NULL;
	}
	else
	{
		delete head;
		head= NULL;
	}

}

//returns true if the stack is empty and false if it is not empty
bool myStack::isEmpty() const
{
	bool check= false;

	if(head== NULL)
	{
		check= true;
	}

	return check;


}