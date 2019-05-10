//exam question.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//need to resize array as you go

//subsequence. ex: 3 2 1 7 8 6 5 10.

//create array of capacity of 5 list[5] = [][][][][]
// read the numbers in so that index 0 = 3, index [1] = 2; index [2] = 1, index[3] = 7, index[4] = 8;
// so we get [3][2][1][7][8]
//need to resize.
//if array is filled, resize by 5;
// now list[10] = [3][2][1][7][8][6][5][10][][]

//create array with right size, being 8 in this example.
// montone[8] = [1][1][1][1][1][1][1][1] each index element is 1;
// start from left and find values that is higher than the previous. 
//search through the list. and when you reach 7 at index [3] you can add 1 to any of the previous of monotone.
// SO monotone[3] = 2. 
// next index value is 8. SO want to increment the largest value so that monotone[4] = 3 = (montone[3] +1 ) 
// as montontone[3] = 2.
// NEXT list[5] = 6 ... as list[4] and list [3] are greaten than list[5] we add 1 to index of 2 which is 1
//THUS monotone[5] = 2.
//SAME FOR list[6] as 5 is less than the previous. so monotone[6] = monotone[3] + 1 = 2;
//LAST INDEX list[7] = 10. CAN TACK ON TO ANY BUT WANT TO ADD TO LARGEST VALUE so 3 is max thus 
//MONOTONE[7] = 4// Answer.

//3 2 1 6 7 8 10;
// LIST AND MONOTONE ARE THE TWO DYNAMIC ARRAYS!
int main()
{
	//int size = 5;

	//pointer to first list of items
	int * listOfItems;
	listOfItems = new int[5];
	//resize pointer
	int * resize;
	resize = new int[10];
	
	ifstream inFile;
	string file;
	int num;
	int count;
	//get input file name;
	cout << "Enter input file: ";
	cin >> file;
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


	count = 0;

	//int startSize = 5;
	//int resizeSize = 5;
	//while in file. 
	//loop reads in data from file into listOfitems and resizes array when filled.
	while(!inFile.eof())
	{
		count++;
		//reads in number from file
		inFile >> num;

		//stores number into index of count-1;
		listOfItems[count - 1] = num;

		//if count > 5 then resize;
		if(count == 5)
		{
			for (int i = 0; i < 5; i ++)
			{
				resize[i] = listOfItems[i]; 			
				//copies the 5 elements of the arr array into the resize array.
				//need to deallocate.
			}
			delete [] listOfItems;
			listOfItems = resize; //pointer now points to resize
			resize = NULL;	//resize now points to null;
		}

		//if listOfItems[10] is filled then resize to 15.
		if (count == 10)
		{
			resize = new int[15];
			for(int i = 0; i < 10; i++)
			{
				resize[i] = listOfItems[i];
			}
			delete [] listOfItems;
			listOfItems = resize; //pointer now points to resize
			resize = NULL;
		}
		//count++;
		//dynamically resize array as reading from file. 
	}
	//cout << "COUNT: " << count << endl;
	int * monotoneLength;
	monotoneLength = new int[count];
	//int arraySize = count - 1;

	count = count - 1;
	int max = 1;
	//create array that has index of the the number of ints read in from file and fill with 1;
	for(int i = 0; i < count ; i++)
	{
		monotoneLength[i] = 1;
	}

	//cout << "array size: " << arraySize;
	//change value of monotoneLength.
	//int tempIndex;
	//int tempMax = 1;
	for(int i = 1; i < count; i++)
	{
		for(int j = 0; j < i; j++ )
		{
			if(listOfItems[i] > listOfItems[j] and monotoneLength[j] >= monotoneLength[i] )
				monotoneLength[i] = monotoneLength[j] + 1;
			
		}
		
		//perform search then do something.
	}

	for(int i = 0; i < count; i++)
	{
		cout << monotoneLength[i] << " ";
		if (monotoneLength[i] > max)
			max = monotoneLength[i];
	} 

	cout << "The length of the longest monotone subsequence is " << max << endl;

	delete [] listOfItems;
	delete [] resize;
	delete [] monotoneLength;



	inFile.close();
}