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
	int amountOfAccounts;
	string first [20];
	string last [20];
	double amount [20];
	long acctNo [20];
	short pin [20];
	short attempts [20];
};
