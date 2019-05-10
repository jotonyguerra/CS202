/*
TEST NOTES.

The three basic concepts of OOP/Object Oriented Programming. LIST THREE.
-Encapsulation: public / private.

-Inheritance: 

-Polymorphism:

Chapter 11 (Inheritence)

	- Inheritance "is-a" and Composition "has-a"
	- public, private, and protected Inheritance. KNOW THEM AND THE TABLE; TF PROTECTED MEMBER DIFFERENCE FROM PRIVATE
	-How to call base class functions from derived class // SHAPES NOTES ON MOODLE!!!!
	-Function Overriding. //OVERLOAD FUNCTION IN DERIVED CLASS. 
	-How are base class constructors invoked in derived class

	-Trace and/or write code on inhertiance and composition. 

	Operator Overloading (check the fraction class)

	-write code on overloading an operator
	-determine which operator from the class is called when called in main (or anywhere else)

What are friend functions? p 898 - 903
	-declared within class
	-technically not a member function (not called through object)
	-although not a member function, it can access private members of the objects.

Pointers p.818 - 847

	-Declare a pointer
	-assign an address to a pointer (legal assignment of pointers)
	-How do we dereference a pointer and what does it mean to dereference a pointer.!!!
	it means to reference new location it points too.
	-Understand what actions new and delete perform. !!!!!!!!! Define and know what they DO. 
		NEW= ALLOCATES::::::: DELETE: DEALLOCATES
	
	-Understand memory leak and what are the issues !!!!!!!!!
		::KNOW DEFINITION::::::
		//a failure in a program to release discarded memory, causing impaired performance or failure.

	-understand dangling pointers and what the issues.
	// dangling pointers. memoray locatio is out your control.
	-understand the difference between deep copy and shallow copy !!!!!
			:: SHALLOW COPY : copies locations. TWO POINTERS POINT TO SAME MEM LOCATION
			:: TWO VALUES = deep copy.

	-Resize a 1D and 2D array.


FORMAT

True FAlkse

reading writing code on inhertiacne , overloading and pointers.  

BASES ON ASSIGNMENT 7 AND 8!
*/

//BASE CLASS CONSTRUCTOR 
class square
{
public:
	square(double len)
	{
		l = len;
	}
	double area() const {return l*l}
	double perimter() const {return 4*l}

private:
	double l;
};

//example 
class cube : square //cube inherits public member functions of square.
{
public:
	cube(double len, double height):square(len)  ///// access base class constructor of square 
	{
		h = height
	}
	double area() const 
	{
		return 6 * square::area() //calls inherited area function
	}
	double volume() const {return square::area() * h}
private:
	double h;

};

///OPERATOR OVERLOADING
class foo
{
public:
	foo();
	foo(int);

	foo operator+(const foo&) const;
	foo operator+ (int) const;
	foo operator*(int) const;
	friend foo operator*(int, const foo&);

private:
	int x;
};

int main()
{
	foo f1, f2, f3;

	f1 = f2 + f3; //calls function on line 99; foo operator+(foo&) const;
	f2 = f3 + 14; // calls function on line 100; foo operator+(foo&) const;

	f3 = f2 + "Hello"; //DNE

	f2 = 3 * f1; //friend function on line 102;

	f1 = 4 + f2; //friend function // DNE for addition
}

//pointers

char ch;
int x;
char * cPtr = new char;
int * iPtr = new int;

*iPtr = x; // valid assignment; assigns x in to the location that iPtr is pointing to.
iPtr = x; // not allowed XXXXX
*cPtr = *iPtr; // will type cast what is stored in iPtr to cPtr;

cPtr = iPtr; //DOES NOT WORK. 

int * list1 = new int [5];		//list1[] --> [][][][][]
int * list2 = new int[5];		//list2[]--> [][][][][]

for(int i = 0; i < 5; i++)
{
	list1[i] = i + 1;
	//same as saying *(list1+i) = i + 1;

}

list2 = list1; //will cause memory leak;

list1 = new int[7];   //list1[] --> [][][][][][][]
//does not cause memory leaks because of 145. list2 preserves address to previous array.

//DEEP COPY

for(int i = 0; i < 5; i++)
{
	list1[i] = list2[i]; //copies all elements in list2 to list1. 
}

for (int i = 5; i < 7; i ++)
	list1[i] = i * 2;

delete[] list1; // dangling pointer causing mem leak
delete[]list2; // mem leak;

cout << list1[0] << endl; //random output cuz dangling pointer.
//references a dangling pointer.

