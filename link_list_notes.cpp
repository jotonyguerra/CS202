struct 
{
	int item;

	node * link;
}						//head[] ----> [7|] [3|] [8|] [4|]



/* front removal methods.
//head = head -> link; //causes memory leaks // code moves head to next element of list.
//assume head was initialized earlier.

//incorrect
delete head;
head = head -> link;

*/

//create new node pointer
node * temp;
//temp pointer points at head.
temp = head;  //DO not do -> temp = new node;
head = head -> link;  //moves one down link list
delete tmp; //deallocates the node that temp points too.

//more rigid for traversing. 

//need seconadary pointer when doing fron removal. 

// Template type

template <class Type>

class bag
{
public:
	bag();
	bag(int);

	bag(const bag<Type>&); //copy constructor, to have dep copy of our objects
	~bag(); //Destructor, called when object out of scope, the purpose is to deallocate dynamic memory to avoid mem leak;
};

template <class Type>
bag<Type>::bag()
{
	1st = NULL;
	length = 0;
}

template <class Type>
int bag<Type>::getAt(int position) const
{
	if (1st == NULL)
		return 0;

	if (position >=0 and position < length)
		return (*this).1st[position];
	else
		return 0;

}

ABSTRACT DATA TYPES (ADT);

- a data type that is defined which is language dependent;
- we focus on the behavior of that data type;

ADT Stack;
-----------
push(x) --> insert x on top of the stack.
pop() -> removes the top element from the stack.
top() -> return the top element w/o removing it.
isEmpty() ->

stack<int> s;
s.push(7);
s.push(11);		
s.push(8);	
ciyt << s.top() << endl; //outputs 8;							[Top of stack]
										[8]
										[11]
										[7]
s.pop(); //removes 8 from stack.
cout << s.top() << endl; //returns 11
s.push(13); //13 is now at top of stack.

Dynamic array implementaion of a stack;

int * stk;
int stkTop;
int capacity;

void push(int item)
{
	stk[stkTop] = item;
	stkTop++;
}

//-resize if stack is full


Linked list implementaion of a stack;

	[3|]->[7|]->[6|]->[4|]
//head[]			//tail []

stack
---------
-last in first out;
-can be implemented using an array or linked list;

ADT QUEUE
------------;
-first in first out;
enqueue(x)-> insert x to the back of the queue;
dequeue()--> remove the from item from the queue;
front()--> return the front elment w/o removing it;
isEmpty() returns true if empty;
//////////
int * line;
int backPos;
int frontPos;
bool full;
bool empty;

.//			[A|]->[B|]->[C|]  
//q link points to C.

//TWO QUESTION ON EXAM //
*********************** EXAM QUESTIONS.
dequeue();
if (q -> link==q)
{
	delete q;
	q = NULL;
}
else
{
	circularQueueNode * tmp;
	tmp = q -> link; //tmp now points to [A|]
	q -> link = tmp->link; //q node nw pints to [B|]
	delete tmp; //deallocates first node of [A|].. q now contains the two nodes [B|]-> [C|]. and q points to right side of [C| ].
}


Recursion
----------
-Call a function within itself
-emulates a loop;
2 cases 
 *base case(stopping case)
 *general case(loop body)
*Define the problem/ data structure recursivley. 

//Power
2^4 => 16;  			//a^b => a * a^(b-1) // (General Case)
2* 2 * 2 * 2; 			//a^0 => 1; //(Base Case)
2^4 => 2 * 2^3;
2^3 => 2 * 2^2;
2^2 => 2 * 2^1;
2^1 => 2 * 2^0;
2^0 => 1;

//recursive power function
int power(int a, int b)
{
	if (b==0)
		return 1;
	else
		return a * power(a, b-1);
}

//calling the function in main.
int main()
{
	cout << power(2,4) << endl;
	return 0;
}
//output of above is

recursive factorial function.
//Factorial
4! = 4*3*2*1;
4! = 4 * 3!;
3! = 3 * 2!;
2! = 2 * 1!;
1! = 1 * 0!;
0! = 1;


n! = n * (n-1)! (general case)
0! = base case;

//recursive factorial function
int factorial(int n)
{
	if (n==0)
		return 1;
	else
		return (n * factorial(n-1));
}

//calling the function
int main()
{
	cout << factorial(4) << endl;
	return 0;
}
//Fib(n)
1, 1 , 2, 3, 5 , 8
Fib(1) => 1 base 
Fib(2) => 1 case

Fib(n) => Fib(n-1) + Fib(n-2) //General Case

int fib(int n)
{
	if (n == 1 or n == 2)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}
//
linked list. 
-----------------------

//- an empty linked list. (base case);
//- a node that points to a linked list  
//head[]-> [1| ] [2| ] [3| ] [4|\]. NULL ;; each nodes is the head of its own linked list.

void traverseLinkedList (node * r)
{
	if (r == NULL)
		return;
	cout << r->item<<endl;
	traverseLinkedList(r->link);
	return;//
}

Recursive defn of a linked list
- empty linked list (base case)		//head ptr ->	//[3|][4|][2|][1|]
- a node that points to another linked list 

void traverseLL(node * r)
{
	if (r == NULL)
		return;		//tail recursion.
	cout << r ->item << endl;

	traverseLL(r-link);
	return;
}

int main()
{
	node * head;
	//code that creates a linked list

	traverseLL(head);

	return 0;
}
//head [] -> [3|]	[4|]	[2|]	[1|/]
		//r->  //r->	r->		 r->		r-> NULL

//output
//3
//4
//2
//1
//

void printLLReverse(node * r)
{
	if (r==NULL)
		return;		//head recursion

	printLLReverse(r->link);
	cout << r->item << endl;
	return;
}

int main()
{
	node * head;

	//code that creates a linked list

	printLLReverse(head);

	return0;
}
//output
//1
//2
//4
//3

search or find function

bool find(node * r, int search)
{
	if (r == NULL)
		return false;

	if (r-> item == search)
		return true;

	return find(r-> link, search);
}

int main()
{
	node * head;
	// code that creates a linked list

	if (find(head,2))
		cout << "Found" << endl;

	if (!find(head, 20))
		cout << "not found" << endl

	return 0;
}

head [] -> [3|]-> [4|]-> [2|]-> [1|/] 
main()   



//TREE NODE NOTES 4/30/19
struct binTreeNode
{
	int item;
	binTreeNode * left;
	binTreeNode * right;
}

//traverse a binary tree
void postorder(binTreeNode * r)
{
	if(r== NULL)
		return;
	postorder(r -> left);
	postorder(r-> right);
	cout << r->item << endl;
	return;

}

//calling the function in main.
int main()
{
	binTreeNode * root;

	//create a binary tree;

	postorder(root);

	return 0;
}
/////////////////////////////////
//Deep copy of binary tree.
(1) copy yourself;
(2) copy the left sub tree;
(3)copy the right sub tree;		//PreOrder Traversal.

///
//Deallocate a binary tree
1-Deallocate the left subtree;
2-Deallocate the right subtree;
3-Deallocate your self (current node youre pointing at); //Postorder traversal

int countSingleParent(binTreeNode * r)
{
	if (r==NULL)
		return 0;
	if (r -> left != NULL and r -> right == NULL)
		cout << 1 + countSingleParent(r->left);
		//returns a count of all single Parent nodes at r's left subtree.
	if(r->left == NULL and r->right != NULL)
		return 1 + countSingleParent(r-> right);

	if(r->left == NULL and r -> right == NULL)
		return 0;

	if (r->left != NULL and r -> right != NULL)
		return countSingleParent(r-> left) +countSingleParent(r->right);

}



///ALGORITHMSSS


//Step by step process to compute a result.

//for all input, the correct solution is computed in finite time. 


Efficiency is measured in time hours/minutes/seconds.
-amount of steps needed to finish running. 
