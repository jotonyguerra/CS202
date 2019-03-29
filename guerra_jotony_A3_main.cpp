#include "guerra_jotony_A3_bankBranch.cpp"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	//variables;
	bankBranch bank;
	string firstName, lastName, name;
	short pin;
	long account;
	double amount;
	ifstream inFile;
	string fileName;
	bool openFile = false;
	long searchAcct;
	short searchPin;
	double withdrawal;
	double deposit;
	bool loop = false;
	bool keep_looping;
	bool flag;
	bool test;
	char wd;
	char contin;


	cout << "Enter filename: ";
	cin >> fileName;
	inFile.open(fileName.c_str());

	//error check file name input
	if(inFile.is_open())
		openFile = true;

	//loop to repeat request for file name
	// really should make this a function as i repeatedly use this to check for proper input
	while(!openFile)
	{
		cin.clear();
		cout << "Ahem...let's try this again: ";
		cin >> name;
		inFile.open(name.c_str());

		if(inFile.is_open())
			openFile = true;
	}

	//while file is not at end put info into variables then call addAccount() t0 add accounts to bank class;
	while(!inFile.eof())
	{
		inFile >> firstName >> lastName >> account >> pin >> amount;
		bank.addAccount(firstName,lastName,amount,account,pin); //should increment amountofAccounts
	}

	//close file
	inFile.close();

	do
	{
		keep_looping = true;
		cout << "Enter account number: ";
		cin >> searchAcct;

		//assign the return of searchAccounts to index; call SearchAccounts;
		int index = bank.searchAccounts(searchAcct);

		//if account is not found
		if (index == -1)
		{
			cout << "Account not found! :(" << endl;

			//loop for continueing
			do
			{
				cin.clear();
				cout << "Do you wish to continue? (Y/N): ";
				cin >> contin;
				cout << endl;

				if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
					flag = true;
				else
					flag = false;

			}while(!flag);

			if (contin == 'y' || contin == 'Y')
				continue;
			else{
				cout << "Have a great day! :)" << endl;
				keep_looping = false;
				break;
			}
		}
		else
		{
			bool keep_looping2 = true;

			//loop for verifying pin input and updating account data.
			do
			{
				//ask for user account pin.
				cin.clear();
				cout << "Enter pin: ";
				cin >> searchPin;
				//assign bool value to correctPin.
				//bool correctPin = bank.verifyAccount(index,searchPin);

				//if pin matches
				if( bank.verifyAccount(index,searchPin))
				{
					cout << endl << endl;
					//call outputUserInfo to display account info.
					bank.outputUserInfo(index);

					//loop to ask for user withdrawal or deposit to account. with input checking
					do
					{
						cin.clear();
						cout << "Would you like to make a withdrawal or deposit? (W/D): ";
						cin >> wd;
						cout << endl;

						//filtering input
						if(wd == 'w' || wd == 'W')
							break;
						else if (wd == 'd' || wd == 'D')
							break;
						else if(wd != 'w' || wd != 'W' || wd != 'd' || wd != 'D')
						{
							cout << "Invalid option! " << endl;
							loop = false;
						}
						else
							loop = true;
					}while(!loop);

					//if user wishes to deposit
					if (wd == 'd' || wd == 'D')
					{
						cin.clear();
						//get amount to deposit.
						cout << "Enter an amount you would like to deposit: ";
						cin >> deposit;

						//call updateAccount function
						bank.updateAccount(index, deposit);
						do
						{
							cin.clear();
							cout << "Do you wish to continue? (Y/N): ";
							cin >> contin;
							cout << endl;

							if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
								flag = true;
							else
								flag = false;
						}while(!flag);

						if (contin == 'y' || contin == 'Y')
						{
							keep_looping = true;
							break;
						}
						else
						{
							cout << "Have a great day! :)" << endl;
							return 0;
						}				
					}

					//if user chose to withdraw
					if (wd == 'w' || wd == 'W')
					{
						//get withdrawal amount
						cin.clear();
						cout << "Enter an amount you would like to withdraw: ";
						cin >> withdrawal;

						//if bank balance is below 0
						if ( bank.updateAccount(index, -withdrawal) == false)
						{
							cout << "Cannot process transaction...O.o" << endl;
							//continue loop
							do
							{
								cin.clear();
								cout << "Do you wish to continue? (Y/N): ";
								cin >> contin;
								cout << endl;

								if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
									flag = true;
								else
									flag = false;
	
							}while(!flag);

							if (contin == 'y' || contin == 'Y')
							{
								keep_looping = true;
								break;
							}
							else
							{
								cout << "Have a great day! :)" << endl;
								return 0;
							}				
						}
						else  
						{	
							//account does not update without this cout.. idk why.
							cout << bank.updateAccount(index, withdrawal);
							bank.updateAccount(index, -withdrawal);
							keep_looping = false;
							
							//continue loop
							do
							{
								cin.clear();
								cout << "Do you wish to continue? (Y/N): ";
								cin >> contin;
								cout << endl;

								if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
									flag = true;
								else
									flag = false;
	
							}while(!flag);

							if (contin == 'y' || contin == 'Y')
							{
								keep_looping = true;
								break;
							}
							else
							{
								cout << "Have a great day! :)" << endl;
								return 0;
							}						
						}
							//continue loop might be unnecessary
							do
							{
								cin.clear();
								cout << "Do you wish to continue? (Y/N): ";
								cin >> contin;
								cout << endl;

								if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
									flag = true;
								else
									flag = false;
	
							}while(!flag);

							if (contin == 'y' || contin == 'Y')
							{
								keep_looping = true;
								break;
							}
							else
							{
								cout << "Have a great day! :)" << endl;
								return 0;
							}						
						}	
				}
				//if pin is incorrect
				else 
				{
					//continue loop
					do
					{
						cin.clear();
						cout << "Do you wish to continue? (Y/N): ";
						cin >> contin;
						cout << endl;

						if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
							flag = true;
						else
							flag = false;
	
					}while(!flag);

					if (contin == 'y' || contin == 'Y')
					{
						keep_looping = true;
						break;
					}
					else
					{
						cout << "Have a great day! :)" << endl;
						return 0;
					}
				}
			}while(keep_looping2);		
		}
	}while(keep_looping);

	return 0;
}


