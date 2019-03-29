#include <iostream>
using namespace std;

int main()
{
	int * ptr = new int;

	delete ptr;

	ptr = new int;


	*ptr = 14;

	cout << *ptr << endl

	delete ptr;
	
	return 0;

}