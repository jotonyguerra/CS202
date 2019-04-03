#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	string fileName;
	char ch;
	//pointer to array
	bool ** twoD; //dynamic two dimensional array.
	int testCases;
	int size;

	bool symmetry = true;
	bool ySymmetry = true;

	//Get user input
	cout << "Please enter input file: ";
	cin >> fileName;
	//open file. need file name
	inFile.open(fileName.c_str());

	//loop to make sure file is open.
	while(!inFile.is_open())
	{
		cin.clear();
		cout << "Please enter input file: ";
		cin >> fileName;
		//open file. need file name
		inFile.open(fileName.c_str());
	}

	//how to parse the data in file. By newline. first piece of data from file is number of cases = 5;
	// next number would be size of array
	// next lines = which array elements are occupied;
	// next line would be new size of array

	//first character of file.
	inFile >> ch;
	//convert char to int.
	testCases = ch - '0'; // 5

	//for 5 cases
	for(int i = 0; i < testCases; i++)
	{
		inFile >> size;
		//size = ch - '0';

		///SIZE IS MESSED UP AFTER FIRST TEST CASE WHY.
		//cout << "SIZE: " << size << endl;
		//shoud brake out and increase i after each test case. 
		twoD = new bool*[size];
			for(int m = 0; m < size; m++)
			{
				 //twoD points to the location of array of size;
				twoD[m] = new bool[size]; // creates size * size array.
			}
			//assigns data from file to array.
			
			for(int x = 0; x < size; x++)
			{
				for(int y = 0; y < size; y++)
				{
					inFile >> ch;
					twoD[x][y] = (ch == '0') ? false : true; // assigns file data to array/matrix.
				}
			}
			
			//for loop for x axis symmetry
			symmetry = true;
			for(int x = 0; x < size; x++)
			{
				for(int y = 0; y < size; y++)
				{
					if( twoD[x][y] != twoD[x][ (size-1) - y ])
					{
						symmetry = false;
						break;
					}
					else
						symmetry = true;
				}
				if(symmetry == false)
					break;
			}

				//TEST FOR SYMMETRY OVER Y AXIS.
				ySymmetry = true;

			for(int x = 0; x < size; x++)
			{
				for(int y = 0; y < size; y++)
				{
					if(twoD[x][y] != twoD[(size-1) - x][(size - 1) - y])
					{
						ySymmetry = false;
						break;
					}
					else
					{
						ySymmetry = true;
					}
				}
				if(ySymmetry == false)
					break;
			}
				//size is still in scope.
			for(int z = 0; z < size; z++) //deletes rows
				delete [] twoD[z];

		//cout << "Symmetry = " << symmetry << " and ySym = " << ySymmetry << endl;
			if(symmetry == true and ySymmetry == true)
				cout << "Test case " << i + 1 << ": " << " YES" << endl;
			else
			{	
				if(i == 0)
					cout << "Test case " << i + 1 << ": " << " YES" << endl;
				else
					cout << "Test case " << i + 1 << ": " << " NO" << endl;
			}

		delete [] twoD; // deletes first array pointer.
	
	}//END TESTCASE FOR LOOP
	//delete [] twoD;
	

	inFile.close();

	return 0;
}