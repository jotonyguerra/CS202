#include "guerra_jotony_A10.cpp"
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	ifstream inFile;
	string file;
	int num;
	int count = 0;
	int ranges = 1;
	int placeHolder = 0;
	//get input file name;
	cout << "Enter input file: ";
	cin >> file;
	//stacks
	myStack towerStack;
	myStack rangeStack;
	myStack placeHolderStack;
	//open file. need file name
	inFile.open(file.c_str());

	//if file is not open. get new file name.
	while(!inFile.is_open())
	{
		cin.clear();
		cout << "Please enter input file: ";
		cin >> file;
		inFile.open(file.c_str());
	}

	//read in data from file.
	while(!inFile.eof())
	{
		//if(inFile.peek() == '\0')
		//	break;
		inFile >> num;
		if(inFile.eof())
			break;
		//cout << num << endl;
		count++;
		towerStack.push(num);
	}
	

	//loop through stacks to find the range of each tower.
	while(towerStack.isEmpty() != true)
	{
		//integer that stores first top of stack
		int topOfTower = towerStack.top();
		//remove top element of stack.
		towerStack.pop();
		
		while(topOfTower > towerStack.top())
		{
			placeHolderStack.push(towerStack.top());
			towerStack.pop();
			ranges++;
		}

		rangeStack.push(ranges);
		ranges = 1;

		while(placeHolderStack.isEmpty() != true)
		{
			towerStack.push(placeHolderStack.top());
			placeHolderStack.pop();
		}

		//compare topOfTower to top of stack and increase range if it is greater.
	}

	//pushes the integer into the Range Stack. 
	//Should be in loop?
	cout << "Here are the ranges of each tower: ";
	while(!rangeStack.isEmpty())
	{
		cout << rangeStack.top() << " " ;
		rangeStack.pop();
	}
	cout << endl;
	//close file.
	inFile.close();


	return 0;

}