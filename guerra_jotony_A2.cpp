#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

//bank account struct
struct bankAcct
{
	string first, last;
	double amount;
	long acctNo;
	short pin;
	long searchAcct;

};

//function headers
int storeInfo(bankAcct[], ifstream&);
void sort(bankAcct [], int);
int search(bankAcct [], int, long);
void outputAndHandleRequest(bankAcct&);

//main
int main(){

	//declare variables
	ifstream inFile;
	string name;
	bool openFile = false;
	bankAcct y[20];
	bool flag =false;
	long acctSearch;
	char contin;
	short acctPin;

	//output to get user input for file
	cout << "Enter filename: ";
	cin >> name;
	inFile.open(name.c_str());

	//error check file name input
	if(inFile.is_open())
		openFile = true;

	//loop to repeat request for file name
	// really should make this a function as i repeatedly use this to check for proper input
	while(!openFile)
	{
		cin.clear();
		cout << "Enter filename: " << endl;
		cin >> name;
		inFile.open(name.c_str());

		if(inFile.is_open()){
			openFile = true;
		}
	}
	//call to storeInfo function
	int size = storeInfo(y, inFile);
	//call sort functino
	sort(y, size);

	//bool for loop condition
	bool keep_looping = true;
	flag = false;

	//loop for account continuation. can be optimized but working.
	do{
		cout << "Enter Account number: ";
		cin >> acctSearch;
	
		if (search(y,size,acctSearch) < 0)
		{
			do
			{
				cin.clear();
				cout << "Do you wish to continue? (Y/N):";
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

		//output to get pin from user.
		cout << "Enter pin: ";
		cin >> acctPin;

		//if inputed pin is correct call function to handle request
		if (acctPin == y[search(y,size,acctSearch)].pin)
		{
			outputAndHandleRequest(y[search(y,size,acctSearch)]);

			flag = false;
			while(flag == false)
			{
				cin.clear();
				cout << "Do you wish to continue? (Y/N):";
				cin >> contin;
				cout << endl;

				if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
					flag = true;
				else
					flag = false;
			}

			if (contin == 'y' || contin == 'Y')
				continue;
			else{
				cout << "Have a great day! :)" << endl;
				keep_looping = false;
				break;
			}
		}else
		{
			cout << "Wrong pin! Exiting account." << endl;

			flag = false;
			while(!flag)
			{
				cin.clear();
				cout << "Do you wish to continue? (Y/N):";
				cin >> contin;
				cout << endl;

				if(contin == 'n' || contin == 'N' || contin == 'y' || contin == 'Y')
					flag = true;
				else 
					flag = false;
			}

			if (contin == 'y' || contin == 'Y')
				continue;
			else{
				cout << "Have a great day! :)" << endl;
				keep_looping = false;
				break;
			}
		}
		
		if (contin == 'y' || contin == 'Y')
		{
			continue;
		}
		else if (contin == 'n' || contin == 'N')
		{
			cout << "Have a great day! :)" << endl;
			keep_looping = false;
			break;
		}
	}while(keep_looping);

	//close file
	inFile.close();
	return 0;
}

//function to return number of accounts and to fill in data from text file to struct.
int storeInfo(bankAcct y[], ifstream& x){

	int count = 0;

	//for loop to initialize the struc with the data from file.
	for(int i = 0; i < 20; i++)
	{
		//exit loop when eof is reached.
		if(x.eof())
			break;

		count++;
		x >> y[i].first;  
		x >> y[i].last;
		x >> y[i].acctNo;
		x >> y[i].pin;
		x >> y[i].amount;
	}
	//returns count
	return count - 1;
};

//sort function to bubble sort bankaccount using the number returned by storeInfo function.
void sort(bankAcct y[], int length)
{
	bankAcct temp_struc;
	
	//bubble sort for loops
	for (int iteration = 1; iteration < length; iteration++)
	{
		for (int index = 0; index < length - iteration; index++)
			if(y[index].acctNo > y[index + 1].acctNo)
			{
				temp_struc = y[index];
				y[index] = y[index+1];
				y[index +1] = temp_struc;
			}
	}
};

//function performs binary search of bankaccount number
int search(bankAcct list[], int index, long searchItem)
{
	int first = 0; 
	int last = index - 1; 
	int mid;
	bool found = false;

	while(first <= last && !found)
	{
		mid = (first + last) / 2;

		if (list[mid].acctNo == searchItem) 
			found = true;
		else if (list[mid].acctNo > searchItem) 
			last = mid - 1;
		else
			first = mid + 1;
	}

	if(found) 
		return mid;
	else 
	{
		cout << "Account not found! :(" << endl;
		return -1;
	}
}

//function to handle request of user to withdraw/deposit to account
void outputAndHandleRequest(bankAcct &list)
{
	short acctPin;
	char wd;
	bool loop;
	double withdrawal;
	double deposit;
	bool test = false;

	//Display account data
	cout << fixed << setprecision(2);
	cout << setw(10) << left << "Name: " << setw(10) << right << list.last << ", " << setw(9) << right << list.first << endl;
	cout << setw(11) << left << "Acctno " << setw(20) << right << list.acctNo << endl;
	cout << setw(10) << "Balance...$" << setw(20) << right << list.amount << endl;
	cout << endl;

	//output to ask for user input to withdraw or deposit
	do
	{
		cin.clear();
		cout << "Would you like to make a withdrawal or deposit? (W/D): ";
		cin >> wd;
		cout << endl;

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


	if(wd == 'w' || wd == 'W')
	{
		while(test == false)
		{
			cout << "Enter an amount you would like to withdraw: ";
			cin >> withdrawal;
			cout << endl;

			if (cin.fail())
			{
				cout << "Incorrect amount! ";
				cin.clear();
				cin.ignore(32767, '\n');
				test = false;
			}
			else if (withdrawal < 0)
			{
				cout << "Incorrect amount! ";
				test = false;
			}
			else
				test = true;
		}
		//if amount less than 0
		if (list.amount < 0)
			cout << "cannot process transaction O.o" << endl;
		else
			list.amount = list.amount - withdrawal;
	}	

	//if deposit was chosen
	if(wd == 'd' || wd == 'D')
	{
		test = false;
		while(test == false)
		{
			cout << "Enter an amount you would like to deposit: ";
			cin >> deposit;
			cout << endl;

			if (cin.fail())
			{
				cout << "Incorrect amount! ";
				cin.clear();
				cin.ignore(32767, '\n');
				test = false;
			}
			else if (deposit < 0)
			{
				cout << "Incorrect amount! ";
				test = false;
			}
			else
				test = true;
		}
	}
	//increment bank account balance by deposit
	list.amount += deposit;
		
};