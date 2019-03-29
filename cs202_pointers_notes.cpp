/*
Pointers:
A variable that contains an address.

Example: <dataType> * <identifier>;
*/


int main()
{
	int x;
	double dblVar;
	int * iPtr;
	double	 * dblPtr;

	x = 19; //will look up where x resides in memory;

	dblVar = x + 2.2; // stores 21.2

	iPtr = &x; // & = reference operator
	//gets address of x and stores it in iPtr;

	dblPtr = & dblVar; // stores location/address of dblVar; base16 address.

	//if you want to access location of pointer variable 

	*iPtr = 15;
	//* = dereference operator. 
		//- dereference a pointer, go to the location that the pointer points to. 
		//will rewrite the varaible x to x = 15.
	*dblPtr = 3.14;
	// will rewrite the variable dblVar to dblVar = 3.14;

	//will not compile
	iPtr = &dblVar;

	dblPtr = &x;
	//will not compile.

	//must point to location of same data type.

}
// notes
int main()
{
	int * p1, * p2, *p3; // need star before each varaible name for 3 pointer variables. 
	double *dblptr4;
	int a,b;

	double c;

	p1 = &a;
	p2 = &b;

	a = 13; //will modify both the pointer and a;
	p3 = p1; // will assign the location of p1.

	*p3 = 10; //will reassign 10 to the location of a, p1 and p3. 

	*p2 = 10;

	*p1 == *p3; // true

	*p2 == *p1; //true

	p1 == p3; // true because p1 address matches p3 address
	p2 == p1; //false. p2 address does not match p1; 

}

int main()
{
	int * iPtr2;
	double * dblPtr5;
	char * cPtr;

	*cPtr = 'Z'; //will seg fault. points no where. all null pointers or point some random spot.

	cPtr = new char; //key word new. new allocates 1 byte address to pointer cPtr.

	*cPtr = 'Z'; //will no assign 'Z' to the location assigned by line above. 

	iPtr2 = new int; 

	dblPtr5 = new double;

	*iPtr = 17;
	*dblPtr5 = 2.73; 


}

// NOTES MARCH 12

void foo(int*);
void foo2(int *);

int main()
{
	int *p5;
	p5 = new int;

	*p5 = 33;

	foo(p5);
	cout << *p5 << endl; //Output is 24. because of foo function.

	foo2(p5);
	cout << *p5 << endl; // 24. Passed in p5 as ponter so *t is destoryed and.

}

void foo(int * p)
{
	*p = 24;
}

void foo2(int * t)
{
	t = new int;
	*t = 50; 

	//Function will cause memory leak. as the new int location is not destroyed. 
	//to solve next line is needed. "delete t" 
	delete t;
}

//////// NOTES MARCH 14. POINTERS

int * arr;


arr = new int[5]; // points to first index of array of 5 elements
*arr = 13; // will update location of arr to 13 so first index of arr will be 13.
arr = arr + 1; //bad way of pointer to new location. // will move over to next element. 

* arr = 8; // will place 8 in the arrays next position.  
arr = arr -1; //moves the pointer to the previous position on array.

*(arr + 2) = 3; //will move to the 3rd index of array. o,1,2*,3,4; and Store a 3. 

for (int i = 0; i < 5; i ++)
{
	*(arr + i) = rand() % 20;
}

for(int i =0; i < 5 ; i++)
{
	arr[i] = rand() %20;         /// same as above for loop.
}

for (int i = 0; i < 5; i++)			/// want to resize array to 10 elements
{
	arr[i] = rand % 20;				
}

int * resize;
resize = new int[10];	// first element of 10 int array will be assigned to resize. 
for (int i = 0; i < 5; i ++)
{
	resize[i] = arr[i]; 			//copies the 5 elements of the arr array into the resize array.
									//need to deallocate.

}

delete [] arr;				// deletes the 5 element array. arr is a dangling pointer now.
arr = resize;				//arr is now pointing to a 10 element array.
resize = null;			// resize now points to nothing.

// delete [] resize will delete all the above work as both arr and resize point to the 10 element array/
/************************************************
CREATING A DYNAMIC TWO DIMENSIONAL ARRAY.
*/
int ** twoD; //dynamic two dimensional array.
twoD = new int*[3];						// twoD points to a an 3 element array.

for (int i = 0; i < 3; i++)				
{								 //twoD	  0 1 2
									//0[] [][][]
									//1[] [][][]
									//2[] [][][]
	twoD[i]= new int[3];		//assign 3 element array to each element of the original array. 
								//creating a 3x3 two dimensional array.
}
*(*(twoD+1)+1) = 17;			//assigns 17 to twoD[1][1] same as twoD[1][1] = 17;

twoD[0][1] = 9;					// first row second column = 9;
twoD[2][2] = 10;				//3rd row and 3rd column is 10;

//Another way of writing twoD is
*(*(twoD + 0) + 1) = 9;
*(*(twoD + 2) + 2) = 10;//

delete [] twoD;

for (int i = 0; i < 3; i++)
	delete [] twoD[i];			// deletes each array. // NO BEUNO METHOD because of line 194 or delete [] twoD. 
/////////////////////

//better way of dealloacting array.
for(int i = 0; i < 3; i++) //deletes rows
	delete [] twoD[i];

delete [] twoD; //deletes the first column

/*****************
//March 26, 2019
/////////////////////
****************/
int ** resize; 
resize = new int*[4]; //4 pointers in array. //0[]
											 //1[]
for(int i =0; i < 4; i++)					 //2[]
{											 //3[]
	resize[i] = new int[4]; 		// creates array of size 4 to each index of resize.
}					 						//0[]-> [][][][]
											//1[]-> [][][][]
											//2[]-> [][][][]
											//3[]-> [][][][]
for(int i = 0; i<3; i++)
{
	for(int j = 0; j < 3; j++)
		resize[i][j] = twoD[i][j] // transfers twoD to resize array.
}

//deallocate array.
for(int i; i<3; i++)
	delete[] twoD[i]; // delete each row.

//deallocate the first column.
delete[] twoD;

twoD = resize;
resize = NULL; // do not use delete resize; wipes out address that resize points too. 


class sixteen
{
	//working class.
};

int main()
{
	sixteen * p; // create sixteen class object pointer p.

	p = new sixteen(); // calls constructor. creates unanmed object whose address is assigned to p;

	//does not work.
	p.moveLeft(); // test to see if can call class functions. // wont compile. // p is not a class object. contains address.

	//wont work
	*p.moveLeft(); // dot operator has priority before star.  // WONT work.

	//works
	(*p).moveLeft(); //will work. 

	p->moveLeft(); //equivilent to above. Will work.

	//deallocate.
	delete p; // deallocates pointer p.

}

