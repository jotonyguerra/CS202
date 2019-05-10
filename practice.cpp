#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int * iptr;
	//double * dblPtr5;
	//char * cPtr;

	//int x = 5;
	//char x = 'z';

	iptr= new int[5];

	for(int i=0; i<5; i++)
	{
		iptr[i]= 1;
	}

	int *tmp;

	tmp= new int[10];

	for(int i=0; i<5 ;i++)
	{
		tmp[i]=iptr[i];
	}

	delete [] iptr;

	iptr=tmp;

	for(int i=5; i<10 ;i++)
	{
		iptr[i] = 2;
	}

	//dangling.
	delete [] tmp;
	//tmp=NULL;

	for( int i=0; i <10; i++)
	{
		cout << iptr[i] << " ";
	}


	//cPtr = &x; //will seg fault. points no where. all null pointers or point some random spot.

	//cPtr = new char; //key word new. new allocates 1 byte address to pointer cPtr.

	//*cPtr = 'Z'; //will no assign 'Z' to the location assigned by line above. 
	/*
	iPtr2 = new int(x); 

	dblPtr5 = new double;

	*iPtr = 17;
	*dblPtr5 = 2.73; 

	cout << *iPtr2;
	*/

}
