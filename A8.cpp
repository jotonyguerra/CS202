//exam question.
#include <iostream>
#include <fstream>
#include <cstdlib>

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

// LIST AND MONOTONE ARE THE TWO DYNAMIC ARRAYS!
int main()
{
	int listOfItems[5];

	istream inFile;
	ostream oFile;

	//open file. need file name
	inFile.open();

	while(!inFile.eof())
	{
		//dynamically resize array as reading from file. 
	}


}