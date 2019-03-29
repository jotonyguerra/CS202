#include "bigNum.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/**********************
DEFAULT CONSTURCTOR
Param: None
returm: creates bigNum object with amtDigits = 0; and all chars set to '0'
**********************/
bigNum::bigNum()
{
	amtDigits = 0;
	for(int i = 0; i < MAX_DIGITS; i++)
	{
		number[i] = '0';
	}
	
}

//bigNum n1("0076583")
/***************************

Constructor to store string into the object character array. 

****************************/
bigNum::bigNum(const char strNum[])
{
	//set all chars to 0
	amtDigits = 0;
	for(int i = 0; i < MAX_DIGITS; i++)
	{
		number[i] = '0';
	}
	int pos = 0;
  	int count = 0;
  	//filter out leading zeros
  	while (strNum[pos] == '0')
  	  pos++;

 	int start = pos;
  	//count all the digits in the number w/o leading zeros
  	//All string literals end with a null character, i.e. '\0' character
  	while (strNum[pos] != '\0')
    {
      pos++;
      count++;
    }
   	amtDigits = count;

    //cout << "Amount of digits: " << amtDigits;
  	for(int i = 0; i < amtDigits; i++)
  		number[MAX_DIGITS - amtDigits + i] = strNum[start + i];
}

//suppose n = 38390
bigNum::bigNum(int n)
{
	//set all chars to 0;
	for(int i = 0; i < MAX_DIGITS; i++)
	{
		number[i] = '0';
	}
	//int temp;
	int length = 0;
	int num = n;

	while(n)
	{
		//loop gets the number of digits in the integer.
		n /= 10;
		length++; // number of digits
	}
	//sets the amount of digits
	amtDigits = length;
	//cout << "amount of digs: " << amtDigits << endl;
	// might be just i < length.
	int temp = num;
	for(int i = 1; i <= length; i++)
	{
		//if n = 321 then length = 3; so should loop three times. 
		//if n = 321 then temp = 1. should loop through.
		temp = num%10;
		num /= 10;
		number[MAX_DIGITS - i] = (temp + '0');
	}
	
}

//the number being passed into the function is a character array so must be converted to an integer
//then added with another big integer number then 
//correcty add and increment the index of a new bigNum then return that big num.
bigNum bigNum::operator+(const bigNum& rhs) const
{	
	bigNum tempObj;
	int indexNumber;
	int n = 0; 
	int carryOver = 0;
	//tempObj::amtDigits = 
	//bigNUM amtDigits is not being set. always 0. how to change.
	//cout << "rhs amtDigits: " << rhs.amtDigits << endl;
	//cout << rhs.amtDigits<< ": rhs amount of digits." << endl;
	//cout << "digit amt : " << amtDigits << endl;
	if(amtDigits > rhs.amtDigits)
	{
		for(int i = 1; i <= amtDigits; i++)
		{
			indexNumber = (number[MAX_DIGITS - i] - '0') + (rhs.number[MAX_DIGITS - i] - '0') + carryOver;
			//cout << "indexNumber: " << indexNumber << endl;
			//cout << "rhs number 2: " << rhs.number[MAX_DIGITS - 2] << endl;
			if(indexNumber == 10)
			{
				tempObj.number[MAX_DIGITS - i] = 0 + '0';
				carryOver = 1;
				n++;

				if(i == amtDigits)
				{
					tempObj.number[MAX_DIGITS - amtDigits + 1] = '1';
					n++;
				}
			}
			else if(indexNumber > 10)
			{
				tempObj.number[MAX_DIGITS - i] = (indexNumber%10) + '0' ;
				carryOver = 1;
				n++;
			}
			else if(indexNumber < 10)
			{
				tempObj.number[MAX_DIGITS - i] = (indexNumber) + '0' ;
				carryOver = 0;
				n++;
			}
			//cout << "tempObj: " << tempObj.number[MAX_DIGITS-i];
		}//end of for loop.
	}
	else
	{
		carryOver = 0;
		for(int i = 1; i <= rhs.amtDigits; i++)
		{
			indexNumber = ( number[MAX_DIGITS - i] - '0' ) + ( rhs.number[MAX_DIGITS - i] - '0' ) + carryOver;
			//cout << i << ". indexNumber : " << indexNumber << endl;

			if(indexNumber >= 10)
			{
				tempObj.number[MAX_DIGITS - i] = (indexNumber%10) + '0' ;
				carryOver = 1;
				n++;
			}
			if( indexNumber <= 9 )
			{
				tempObj.number[MAX_DIGITS - i] = indexNumber + '0' ;
				carryOver = 0;
				n++;
			}
		}//tempObj.amtDigits = count;
	}

	if (carryOver == 1)
	{
		tempObj.number[MAX_DIGITS - (amtDigits + 1) ] = 1 + '0';
		n++;
	}
	tempObj.amtDigits = n;
	//cout << tempObj.amtDigits;
	return tempObj; 
}

/*
bigNum operator+(int rhs) const is the operator function when we are adding a bigNum object
with an int in that order and a bigNum object is returned which will be the sum, you can reuse
constructors and another operator function here
*/
bigNum bigNum::operator+(int rhs) const
{
	//creates bigNum object out of the integer
	bigNum tempObject(rhs);
	bigNum answer;
	int length = 0;
	int n = 0;
	int indexNumber;

	while(rhs)
	{//loop gets the number of digits in the integer.
		rhs /= 10;
		length++;
	}
	answer.amtDigits = amtDigits;
	//set amount of digits to larger object amount of digits.
	if (amtDigits < tempObject.amtDigits)
		answer.amtDigits = tempObject.amtDigits;

	int carryOver = 0;
	if (amtDigits > tempObject.amtDigits)
	{
		//int carryOver = 0;
		for(int i = 1; i <= amtDigits; i++)
		{

			indexNumber = (number[MAX_DIGITS - i] - '0') + (tempObject.number[MAX_DIGITS - i] - '0') + carryOver;
			//cout << "indexNumber: " << indexNumber << endl;
			if(indexNumber == 10)
			{
				answer.number[MAX_DIGITS - i] = 0 + '0';
				carryOver = 1;
			
			}
			else if(indexNumber > 10)
			{
				answer.number[MAX_DIGITS - i] = (indexNumber%10) + '0' ;
				carryOver = 1;
			}
			else if(indexNumber < 10)
			{
				answer.number[MAX_DIGITS - i] = (indexNumber) + '0' ;
				carryOver = 0;
			}			
		}
	}
	else
	{
		carryOver = 0;
		for(int i = 1; i <= tempObject.amtDigits; i++)
		{
			indexNumber = ( number[MAX_DIGITS - i] - '0' ) + ( tempObject.number[MAX_DIGITS - i] - '0' ) + carryOver;
			//cout << i << ". indexNumber : " << indexNumber << endl;

			if(indexNumber >= 10)
			{
				answer.number[MAX_DIGITS - i] = (indexNumber%10) + '0' ;
				carryOver = 1;
				//n++;
			}
			if( indexNumber <= 9 )
			{
				answer.number[MAX_DIGITS - i] = indexNumber + '0' ;
				carryOver = 0;
			}
		}
		//if (carryOver == 1)
		//	answer.number[MAX_DIGITS - tempObject.amtDigits - 1 ] = 1 + '0';
		//n++;		
	}
	
	if (carryOver == 1)
	{
		answer.number[MAX_DIGITS - amtDigits - 1 ] = 1 + '0';
		answer.amtDigits++;
	}
	return answer;

}
/******************************
bool operator<(const bigNum& rhs) const is the operator function that compares a bigNum with
another bigNum object, this function returns true if the object on the left side represents a smaller
number than the object on the right and false otherwise (not cstring libraries can be used here, for
example you cannot use strcmp)
*******************************/
bool bigNum::operator<(const bigNum& rhs) const
{
	bool bigNah = false;

	//if the amount of digits are equal
	if(amtDigits == rhs.amtDigits)
	{
		for(int i = 0; i < amtDigits; i++)
		{
			if( (number[MAX_DIGITS - amtDigits + i] - '0') < (rhs.number[rhs.MAX_DIGITS - rhs.amtDigits + i] - '0'))
				return true;
			else
				return false;
			
		}
	}

	if( amtDigits > rhs.amtDigits)
		return bigNah = false;
	else if(amtDigits < rhs.amtDigits)
		bigNah = true;
	else if (amtDigits == rhs.amtDigits)
	{
		if( (number[MAX_DIGITS - amtDigits] - '0') > (rhs.number[rhs.MAX_DIGITS - rhs.amtDigits] - '0'))
			bigNah = false;
		else
			bigNah = true;
	}
	return bigNah;
}
/*
bool operator<(int rhs) const is the operator function that compares a bigNum with an int, this
function returns true if the object on the left side represents a smaller number than the integer on the
right and false otherwise, once again you might want to use some other functions and constructors
here to make things easier for you
*/
bool bigNum::operator<(int rhs) const
{
	bool bigInts;
	bigNum temp(rhs);
	//cout << "Digits in the int: " << temp.amtDigits << endl;
	int rhDigits = temp.amtDigits;

	if (amtDigits < rhDigits)
		bigInts = true;
	else if( amtDigits > rhDigits)
		bigInts = false;
	else if ( amtDigits == rhDigits)
	{
		if( (number[MAX_DIGITS - amtDigits] - '0') < (temp.number[temp.MAX_DIGITS - temp.amtDigits] - '0') )
			bigInts = true;
		else
			bigInts = false;
	}

	return bigInts;
}

/********************
bool operator==(const bigNum& rhs) const is the operator function that compares a bigNum with
another bigNum object, this function returns true if the object on the left side represents number that
equals the number represented by object on the right and false otherwise 
*********************/

bool bigNum::operator==(const bigNum& rhs) const
{
	bool truths;

	if(amtDigits == rhs.amtDigits)
	{
		for(int i = 1; i <= amtDigits; i++)
		{
			if ((number[MAX_DIGITS - amtDigits + i] - '0' ) != (rhs.number[rhs.MAX_DIGITS - amtDigits + i] - '0') )
				return false;
			truths = true;
		}
	}
	else
		truths = false;
	return truths;
}

/******************
OPERATOR OVERLOAD ==
*******************/
bool bigNum::operator==(int rhs) const
{
	bool truthy;
	bigNum temp(rhs);
	//cout << "amtDigits = " << amtDigits << endl;
	//cout << "temp.amtDigits = " << temp.amtDigits << endl;
	if(amtDigits == temp.amtDigits)
	{	
		int i = 1;
		while(i <= amtDigits)
		{
			if ((number[MAX_DIGITS - amtDigits + i] - '0' ) == (temp.number[MAX_DIGITS - amtDigits + i] - '0') )
			{
				 i++;
				 continue;
			}
			else
			{
				truthy = false;
				break;	
			}
			truthy = true;
		}
	}
	else
		truthy = false;

	return truthy;
}

/*
+ Operator Overload

*/
bigNum operator+(int lhs, const bigNum& rhs)
{
	bigNum temp(lhs);

	bigNum answer(temp + rhs);

	return answer;
}
/*

*/

bool operator<(int lhs, const bigNum& rhs)
{
	bigNum temp(lhs);
	bool answer;

	if(temp == rhs)
		return false;

	if( temp < rhs == true)
		return answer = true;
	else
		return answer = false; 
}

/******
Friend bool operator overload ==

Param: (int lhs, const bigNum& rhs)

return  bool answer
**********/
bool operator==(int lhs, const bigNum& rhs)
{
	bigNum temp(lhs);
	bool answer; 

	if (temp == rhs)
		return true;
	else
		return false;
}
/****************
Operator << overload
ostream variable extraction operator is overloaded to display bigNum object when called.
iostream.
***************/
ostream& operator<<(ostream& oFile, const bigNum& rhs)
{
	for(int i = rhs.MAX_DIGITS - rhs.amtDigits ; i < rhs.MAX_DIGITS; i++)
	{
		oFile << rhs.number[i] ;
	}
	return oFile;
}

/****************
Opertor >> overload.
Istream variable insertion operator is overloaded to take in a number and create a bigNum object.
returns istream variable inFile.
*****************/
istream& operator>>(istream& inFile, bigNum& rhs)
{
	char input[rhs.MAX_DIGITS];
	inFile >> input;
	bigNum temp(input);
	rhs = temp;
	return inFile;
}

/*
SUBTRACTION BONUS FUNCTION

subtraction operator overload when the right hand side is a bigNum object.

should return a bigNum object that contains a the answer to the subtraction.
*/


bigNum bigNum::operator-(const bigNum & rhs) const 
{
	int carryOver = 0;
	bool borrow = false;
	bigNum answer;
	int indexNumber;
	int subtract;
	if (amtDigits > rhs.amtDigits)
	{
		for(int i = 1; i < amtDigits; i++)
		{
			if(number[MAX_DIGITS - i] > rhs.number[MAX_DIGITS-i])
				indexNumber = (number[MAX_DIGITS - i] - '0') - (rhs.number[MAX_DIGITS - i] - '0') + carryOver;
			else (number[MAX_DIGITS - i] < rhs.number[MAX_DIGITS - i])
			{	
				borrow = true;
				if(borrow)
					//number[MAX_DIGITS - i] - '0' == 0 and number[MAX_DIGITS - (i + 1)] - '0' != 0)
					carryOver = 10;
				else if(number[MAX_DIGITS - i] - '0' == 0 and number[MAX_DIGITS - (i + 1)] - '0' == 0)
					carryOver = 9;

				indexNumber = (number[MAX_DIGITS - i] - '0') + carryOver - (rhs.number[MAX_DIGITS - i] - '0');
			}

			answer.number[MAX_DIGITS - i] = indexNumber + '0';

			//if(number[MAX_DIGITS - i] > rhs.number[MAX_DIGITS-i])
			//	answer.number[MAX_DIGITS - i] = (number[MAX_DIGITS - i] - '0') - (rhs.number[MAX_DIGITS-i] - '0');
		}
	}
	else
	{
		for(int i = 1; i < amtDigits; i++)
		{
			if(number[MAX_DIGITS - i] > rhs.number[MAX_DIGITS-i])
			{
				indexNumber = (number[MAX_DIGITS - i] - '0') - (rhs.number[MAX_DIGITS - i] - '0') + carryOver;
				carryOver = 0;
			}
			else if(number[MAX_DIGITS - i] < rhs.number[MAX_DIGITS - i])
			{
				subtract = 1;
				//int storage = (number[MAX_DIGITS - (i + 1)] - '0') - 1;
				//number[MAX_DIGITS - (i + 1)] = ((number[MAX_DIGITS - (i + 1)] - '0') - 1) + '0';
				if (carryOver > 0)
					indexNumber = (( number[MAX_DIGITS - i] - 1) - '0') + carryOver - (rhs.number[MAX_DIGITS - i] - '0');


				carryOver = 10;

				if(number[MAX_DIGITS - i] - '0' == 0 and number[MAX_DIGITS - (i + 1)] - '0' != 0)
				{
					carryOver = 10;
					indexNumber = (number[MAX_DIGITS - i] - '0') + carryOver - (rhs.number[MAX_DIGITS - i] - '0');
				}
				else if(number[MAX_DIGITS - i] - '0' == 0 and number[MAX_DIGITS - (i + 1)] - '0' == 0)
				{
					carryOver = 9;
					indexNumber = (number[MAX_DIGITS - i] - '0') + carryOver - (rhs.number[MAX_DIGITS - i] - '0');
				}

				//indexNumber = (number[MAX_DIGITS - i] - '0') + carryOver - (rhs.number[MAX_DIGITS - i] - '0');
			}
			answer.number[MAX_DIGITS - i] = indexNumber + '0';
		}
			//answer.number[MAX_DIGITS - i] = indexNumber + '0';
	}
	if (carryOver == 10)
		answer.amtDigits = amtDigits - 1;
	else
		answer.amtDigits = amtDigits;

	return answer;

}

/*
bigNum bigNum::operator-(int n) const 
{

}
	
bigNum operator-(int n, const bigNum& rhs)
{

}
*/

