#include iomanip
#include fstream
#include cstdlab

using namespace std;



class bankBranch
{
public :
	bankBranch ();
	void addAccount (string , string , double , long , short );
	int searchAccounts ( long ) const ;
	bool verifyAccount (int , short );
	bool updateAccount (int , double );
	void outputUserInfo (int ) const ;
private :
	int amountOfAccounts ;
	string first [20];
	string last [20];
	double amount [20];
	long acctNo [20];
	short pin [20];
	short attempts [20];
};


int main()
{


	return 0;
}

bankBranch::bankBranch()
{

};
/*
adds a new bank
account, the first argument will be a first name, the second argument will be a last name, the third
argument will be an initial balance, the fourth argument will be a bank account number, and the
fifth argument will be a pin, you need to insert each element into the appropriate arrays at position
amountOfAccounts and then increment amountOfAccounts by 1
*/
bankBranch::void addAccount(string f, string l, double amt, long acct, short p) 
{

};