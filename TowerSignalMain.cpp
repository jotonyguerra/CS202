#include <iostream>
#include "TowerSignal.cpp"
#include <string>
#include <fstream>

using namespace std;


int main()
{

	ifstream infile;
	string filename;
	int numbers;
	int x;
	myStack Tower;
	myStack PlaceHolder;
	myStack Range;

	do
	{

		cout<< "Enter a filename: ";
		cin>> filename;

 		//filename.c_str() returns a C style string version
		infile.open(filename.c_str());

	}
	while(!infile.is_open());

	while(!infile.eof())
	{

		infile>> numbers;
		Tower.push(numbers);
	
	}

	while(Tower.isEmpty()!= true)
	{
		int RangeCounter=1;	
		x= Tower.top();
		Tower.pop();

		if(Tower.isEmpty()==true)
		{
			Range.push(RangeCounter);
			break;
		}

		while(x > Tower.top())
		{
			PlaceHolder.push(Tower.top());
			Tower.pop();
			RangeCounter++;
		}

		Range.push(RangeCounter);

		while(PlaceHolder.isEmpty() != true)
		{
			Tower.push(PlaceHolder.top());
			PlaceHolder.pop();
		}

	}

	cout<< "Here are the ranges for each tower"<< endl;

	while(Range.isEmpty()!= true)
	{
		cout<<Range.top()<<" ";
		Range.pop();
	}



	return 0;
}