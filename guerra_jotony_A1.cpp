/*Jotony Guerra
  CS202 TTh
  Assignment 1
*/
#include <cmath>
#include <iostream>

using namespace std;

int main(){

	//count for experipemt
	int count = 0;
	//answer array for experiment.
	int answers[10];

	cout << "Program to find 5 digit numbers where the sum of each digit raised to the fifth power is equal to the 5 digit number\n";
	cout << "----------------------------------------------------------------------------------\n";

	//can be written as a function but whats the point? only the one function for the whole program.
	//loop to iterate through all 5 digit numbers.
	for(int i = 10000; i <= 99999; i++)
	{
		//declare variables
		int ones, tens, hundreds, thousands, ten_thousands;
		int fifth_power;
		int temp;

		//get ones place digit from a 5 digit integers
		ones = i % 10;
		temp = i/10;

		//get tens place digit from 5 digit integer
		tens = temp %10;
		temp = temp/10;

		//get hundreds place digits from 5 digit integer
		hundreds = temp % 10;
		temp = temp/10;

		//get thousands place digit
		thousands = temp %10;
		temp = temp/10;

		//get thousands place digit
		ten_thousands = temp%10;

		// raise each digit to fifth power and add it together.
		fifth_power = pow(ones,5) + pow(tens,5) + pow(hundreds,5) + pow(thousands,5) + pow(ten_thousands,5);

		//display the number and exit loop
		if (i == fifth_power){

			//array to store all answers
			answers[count] = i;

			//increment count
			count++;

			//output
			cout << "Answer: " << i << endl;
			continue;
		}

	}

	//loop to view stored answers. not necessary.
	/*
	for (int i = 0; i < count; i++)
		cout << answers[i] << endl;
	*/

	return 0;
}