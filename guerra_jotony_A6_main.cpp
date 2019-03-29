#include "guerra_jotony_A6_organism.cpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

//using namespace std; 

int main()
{
	//create plant array of 2000
	plant plants[2000];
	//create animal/herbivore array of 200
	herbivore fish[200];

	//decalre variables for input and number of weeks to simulate
	double plantSize, fishSize;
	double plantRate, fishRate;
	int numWeeks;

	//read values from user
	//get number of weeks to simulate
	cout << "How many weeks would you like to simulate? ";
	cin >> numWeeks;
	
	//get plant size and rate
	cout << "Enter initial plant size and rate: ";
	cin >> plantSize >> plantRate;
	//get fish size and rate
	cout << "Enter initial fish size and rate: ";
	cin >> fishSize >> fishRate;
	cout << endl;

	//call constructors using the input
	//temp herbivore object
	herbivore tmpFish(fishSize, fishRate, fishSize * 0.1);
	//temp plant object
	plant tmpPlant(plantSize, plantRate);

	//assign all temp objects to each index of plants
	for (int i=0; i < 2000; i++)
	{
		plants[i] = tmpPlant;
	}

	//assign all temp fish objects to each index of the fish array.
	for(int i = 0; i < 200; i++)
	{
		fish[i] = tmpFish;
	}

	//////// scoping issue or functions for simulate week/ death is not working. number of fish is not changing
	// and mass of plants is larger than expected. idk wtf is going on tho.
	//maybe should use different loop? cant think right now
	// each for loop is being run for each iteration of numWeeks.... so should be right.. why numFish is not updated?
	//need global variable?

	//Loop 	//loop that runs number of weeks.
	for (int i = 1; i <= numWeeks; i++)
	{
			//variables for amount of fish and plant mass.
			int amountOfFish = 0;
			double plantMass = 0.0;

			//Loop (a)
			for(int x=0; x < 2000; x++)
			{	
				int fishIndex = rand() % 200;
				int plantIndex = rand() % 2000;
				fish[fishIndex].nibble(plants[plantIndex]);
			}
			//loop (b)
			//calls each fish and plants simulateWeek function.
			for(int k = 0; k < 2000; k++)
			{
				plants[k].simulateWeek();
			}

			//loop (c)
			//simulate week for fish
			for(int j = 0; j < 200; j++ )
			{
				//fish[i].simulateWeek();
				fish[j].simulateWeek();
			}

			//loop (d)
			//plant mass is off by 2000....? why tho.
			for(int m = 0; m < 2000; m++)
			{
				if (plants[m].isAlive() == false)
					plants[m].death();
				else if (plants[m].isAlive() == true)
				{
					//cout << "plant " << m << " is alive" << endl;
					plantMass += plants[m].getSize();
				}
			}

			//loop (e)
			//increment amount of fish 
			for(int v = 0; v < 200; v++)
			{
				if(fish[v].isAlive() == true)
					amountOfFish++;
				else
					fish[v].death();
			}
			
			//output
			cout << fixed << setprecision(2);
			cout << left << setw(5) << "Week "<< setw(3) << i << setw(25) << right << " Amount of fish......." << setw(4)<< left << amountOfFish << setw(4) 
			<< setw(20) << right << "    Mass of plants........" << plantMass - 2000 << endl;
		}//end loop

		return 0;
}//main closing bracket