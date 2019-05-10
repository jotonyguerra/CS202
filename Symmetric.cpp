#include <iostream>
#include <fstream>


using namespace std;



int main()
{
	ifstream infile;
	string filename;
	int TestCases;// number of cases for symmetry test
	bool **Matrix;// 2D pointer  of bool type
	char input;// a character input from the file
	int SizeofMatrix;// it represents the size of the matrix read in from the file

	//the following  is a do while loop that keep prompting user to enter a valid file
	do
	{
		cout<< "Please enter input file: ";
		cin>>filename;

		infile.open(filename.c_str());
	}
	while(!infile.is_open());

	infile>> TestCases;
	
	int CaseNumber= 0;

	//the follwoing loop check each case and output yes if its symmetry or output no if its not
	while( CaseNumber < TestCases)
	{
		infile>>SizeofMatrix;

		Matrix= new bool* [SizeofMatrix];// array of pointer, this will represent the number of rows with the size that it read in from the file

		// assign a column amount to each row with the size that it read in from the file
		for(int i=0; i< SizeofMatrix; i++)
		{
			Matrix[i]= new bool[SizeofMatrix];
		}

		/*The following two for loops read in the matrix from the file into a char and assign it to the 2D array of pointer
		 as true for 1 and false for 2*/
		for(int i= 0; i< SizeofMatrix; i++)
		{
			for(int j=0; j< SizeofMatrix; j++)
			{
				infile>> input;

				if( input== '1')
				{
					Matrix[i][j]= true;
				}
				else
				{
					Matrix[i][j]= false;
				}

			}
		}

		bool ycheck= true;// checks the symmetry over the y-axis
		bool xcheck= true;//checks the symmetry over the x-axis

		/*The following two for loops breaks the array in half and compare the left
		hand side with the right hand side, if they are not the same it sets ycheck to false*/
		for( int i=0; i< SizeofMatrix; i++)
		{
			for( int j=0; j< SizeofMatrix; j++)
			{
				if( Matrix[i][j] != Matrix[i][SizeofMatrix-j-1])
				{
					ycheck= false;

				}
			}
		}



		/*The following two for loops breaks the array in half and compare the top
		half with the bottom half, if they are not the same it sets xcheck to false*/
		for( int i=0; i< SizeofMatrix; i++)
		{
			for( int j=0; j< SizeofMatrix; j++)
			{
				if( Matrix[j][i] != Matrix[SizeofMatrix-j-1][i])
				{
					xcheck= false;

				}
			}
		}

		//if the matrix is symmetrical over y-axis and x-axis, it output the test case number and Yes for symmetry
		if( xcheck== true and ycheck == true)
		{
			cout<< "Test case "<< CaseNumber+1 << ": "<< "Yes"<< endl;
		}

		//if the matrix is not symmetrical, then it output the test case number and No for symmetry
		else
		{
			cout<< "Test case "<< CaseNumber+1 << ": "<< "No"<< endl;
		}


		//the following loop deallocates each row
		for(int i=0; i<SizeofMatrix; i++)
		{
			delete [] Matrix[i];
		}

		delete [] Matrix;

		//Matrix=NULL;


		CaseNumber++;

	}


	infile.close();



	return 0;
}