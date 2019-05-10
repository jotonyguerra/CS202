#include <iostream>

using namespace std;

class myStack
{
public:
	myStack();//is the default constructor that sets head to NULL
	myStack(int);//is the constructor that allocates size number of nodes to the linked list
	myStack(const myStack&);/*is the copy constructor that performs a deep copy of copy
	object to the object being created with this constructor*/
	const myStack& operator=(const myStack&);/* is the assignment operator that will
	perform a deep copy of the right hand side object to the left hand side object*/
	~myStack();//is the destructor that deallocates the linked list that starts at head
	void push(int);/* allocates a new node and sets this new node’s item field to
	element and inserts it to the front of the linked list*/
	int top() const;//returns head->item
	void pop();// removes the front element of the linked list if the linked list is not empty
	bool isEmpty() const;//returns true if the stack is empty and false if it is not empty
private:
	struct node//is the type of each element in the linked list
	{
		int item;
		node * link;
		
	};
	node * head;//a pointer that points to the front of the linked list, i.e. the top of the stack

};
