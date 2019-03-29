#include "organism.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>

//using namespace std; not needed as included organism.h file.

// Organism Class functions.
//************************************************
/**********************
*/

//PORTION will be set to 0.5 
//static const double PORTION = 0.5;
//static const double MAX_FRACTION = 0.1;


/***********************************
Organism Constructor
Param: initialSize and initialRate
Return: creates an organism object with size and rate that was passed in the param.
*************************************/
organism::organism(double initSize, double initRate) 
{
	size = initSize;
	growthRate = initRate;
}

/**********************
SimulateWeek
Param: None
return: increments size by growthRate;
**********************/
void organism::simulateWeek()
{
	size += growthRate;
}

/**********************
assignRate()
Param: double newRate
return: assigns new rate to growthRate;
**********************/
void organism::assignRate(double newRate)
{
	growthRate = newRate; 
}

/**********************
alterSize
Param: double amount
return: increments size by amount;
**********************/
void organism::alterSize(double amount)
{
	size = size + amount;
}

/**********************
death()
Param: none
return: set growthRate and size to 0
**********************/
void organism::death()
{
	growthRate = 0;
	size = 0;
}


/**********************
getSize()
Param: none
return: returns size of organism object
**********************/
double organism::getSize() const
{
	return size;
}

/**********************
getRate()
Param: none
return: returns growthRate of organism
**********************/
double organism::getRate() const
{
	return growthRate;
}

/**********************
isAlive()
Param: none
return: bool
**********************/
bool organism::isAlive() const 
{
	if ( size > 0)
		return true;
	else 
		return false;
}

//****************************************
//Plant Class Functions
/*****************************************
Plant Constructor
Param: initialSize and initialRate
Return: creates an plant object with size and rate that was passed in the param.
********************************************/
plant::plant(double initSize, double initRate)
{
	alterSize(initSize);
	assignRate(initRate);
}

//alter size of plant by amount.
void plant::nibbledOn(double amount)
{
	alterSize(-amount);
}

//****************************************
//Animal Class Functions
/*****************************************/

/***********************************
Animal Constructor
Param: initialSize, initialRate, initNeed
Return: creates an animal object with size,rate, and need that was passed in the param.
*************************************/
animal::animal(double initSize, double initRate, double initNeed)
{
	alterSize(initSize);
	assignRate(initRate);
	needThisWeek = initNeed;
	eatenThisWeek = 0;
}

/***********************************
assignNeed
Param: double newNeed
Return: assigns th passed in param to the needThisWeek.
*************************************/
void animal::assignNeed(double newNeed)
{
	needThisWeek = newNeed;
}

/***********************************
eat
Param: double amount
Return: assigns th passed in param to eatenThisWeek.
*************************************/
void animal::eat(double amount)
{
	eatenThisWeek += amount;
}

/***********************************
simulateWeek()
Param: none
Return: simulates a week and alters size and sets eatenThisWeek to 0 if eatenThisWeek is greater than or 
equal to needThisWeek. Otherwise size, rate and eatenThisWeek is set to 0 aka death.
*************************************/
void animal::simulateWeek()
{
	if(eatenThisWeek >= needThisWeek)
	{
		alterSize(getRate()); // might need to multiply size by growthrate?
		eatenThisWeek = 0;
	}
	else
	{
		//self.death()
		alterSize(-getSize());
		assignRate(0);
		eatenThisWeek = 0;
	}
}

/***********************************
stillNeed
Param: none
Return: returns the difference of needThisWeek and eatenThisWeek if eatenThisWeek is greater/equal 
to need this week. otherwise zero is returned.
*************************************/
double animal::stillNeed() const
{
	if (eatenThisWeek >= needThisWeek)
		return 0;
	else
		return (needThisWeek - eatenThisWeek);
}

/***********************************
totalNeed
Param: none
Return: returns double value of needThisWeek;
*************************************/
double animal::totalNeed() const
{
	return needThisWeek;
}

//****************************************
//Herbivore Class Functions
/*****************************************/

//setting static const PORTION
const double herbivore::PORTION = 0.5;
//setting static const MAX_FRACTION
const double herbivore::MAX_FRACTION = 0.1;

/***********************************
Herbivore Constructor
Param: initialSize, initialRate, initalNeed
Return: creates an herbivore object with size, rate, and inital need that was passed in the param.
*************************************/
herbivore::herbivore(double initSize, double initRate, double initNeed)
{
	alterSize(initSize);
	assignRate(initRate);
	assignNeed(initNeed);
	eat(0); //eats 0; so should increment 0 by 0.
}

/***********************************
nibble()
Param: reference: plant& meal
Return: 
*************************************/
void herbivore::nibble(plant& meal)
{
	double amount;
	amount = meal.getSize() * PORTION;
	//double num = MAX_FRACTION * needThisWeek;
	if (amount > (MAX_FRACTION * totalNeed()) )
		amount = MAX_FRACTION * totalNeed();
	//idk what stillNeed is returning, a double but what does that indicate.
	if( amount > stillNeed())
		amount = stillNeed();
	
	eat(amount);
	meal.nibbledOn(amount);
}
