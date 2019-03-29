#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "bankBranch.h"

using namespace std;

/**********************************************
DEFAULT CONSTRUCTOR
PARAMETERS: None
RETURN: None
DESCRIPTION: sets all the fields to 0
**********************************************/
bankBranch::bankBranch()
{

}
/*

/**********************************************
FUNCTION NAME: addAccount
PARAMETERS: STRING f, STRING l, DOUBLE amt, LONG acct, SHORT p
RETURN: None
DESCRIPTION: set all parameters to the private members of the bankBranch class
**********************************************/

void bankBranch::addAccount(string f, string l, double amt, long acct, short p) 
{
		first[amountOfAccounts] = f;
		last[amountOfAccounts] = l;
		amount[amountOfAccounts] = amt;
		acctNo[amountOfAccounts] = acct;
		pin[amountOfAccounts] = p;
		amountOfAccounts = amountOfAccounts + 1;
}

/**********************************************
FUNCTION NAME: searchAccounts
PARAMETERS: LONG acct
RETURN: int index
DESCRIPTION: searches the list of account for the inputed account number and return the index of that account
**********************************************/

int bankBranch::searchAccounts(long acct) const
{
	for (int i = 0; i < amountOfAccounts; i++)
	{
		if (acct == acctNo[i])
		{
			return i;
		}
	}
	return -1;
}


/**********************************************
FUNCTION NAME: verifyAccount
PARAMETERS: INT index, SHORT p
RETURN: bool
DESCRIPTION: Checks the inputed parameter p against the pin stored at index. 
If p matches pin at given index the function will return true and false elsewise.
**********************************************/

/*
this function takes in the index position of the account
you are trying to verify and a pin, this function returns true if pin[index] == p, and false otherwise
and you will also increment attempts[index] by 1; if the number of fails for any account is 3 you will
return false automatically regardless if the pin matches
*/
bool bankBranch::verifyAccount(int index, short p)
{

	if(attempts[index] == 3)
	{
		cout << "Too many attempts!\n";
		cout << "Account frozen or incorrect pin entered, exiting account" << endl;
		return false;
	}else
	{
		if (pin[index] == p)
		{
			return true;
		}
		else if(pin[index] != p)
		{
			attempts[index]++;
			cout << "Account frozen or incorrect pin entered, exiting account" << endl;
			return false;
		}else
		{
		return false;
		}
	}
	return false;
}
/*
this function updates the amount for a bank account
at the position given by the first argument (i.e. it will update amount[index] with amt), if the
account at the index given by the first argument is negative, the function returns false and does not
do anything else, otherwise it updates the account and returns true
*/

/**********************************************
FUNCTION NAME: updateAccount
PARAMETERS: INT index, DOUBLE amt
RETURN: bool
DESCRIPTION: Updates account amount at given index by the amt parameter and returns true as long as account is updated.
**********************************************/
bool bankBranch::updateAccount(int index, double amt)
{
	
	if (amount[index] < 0 && amt < 0)
		return false;

	if (amt > 0)
	{
		amount[index] += amt;
		return true;
	}
	else
	{
		amount[index] = amount[index] + amt;
		return true;
	}
}

/**********************************************
FUNCTION NAME: outputUserInfo
PARAMETERS: INT index
RETURN: None
DESCRIPTION: outputs the details of the account at index parameter. 
**********************************************/
void bankBranch::outputUserInfo(int index) const
{
	cout << setw(10) << left << "Name: " << setw(15) << right << first[index] << ", " << last[index] << endl; 
	cout << setw(10) << left << "AcctNo" << setw(26) << right << acctNo[index] << endl;
	cout << setw(10) << left << "Balance...$" << setw(25) << right << amount[index] << endl;
	cout << endl;
};