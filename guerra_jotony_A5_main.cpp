#include <iostream>
#include "guerra_jotony_A5_bigNum.cpp"

using namespace std;

int main ()
{

	bigNum n1 ( "000009999999999999999999999999" );
	bigNum n2 (116986);
	bigNum n3 ;
	bigNum n4 ;
	bigNum onlyUsedInAssign ; // you can rename this variable if you want


	cout << n2;
	
	cout << endl;
	cout << " Enter two big numbers : " ;
	cin >> n3 >> n4 ;

	cout << endl << " Contents of variables " << endl ;
	cout << " n1 = " << n1 << endl ;
	cout << " n2 = " << n2 << endl ;

	
	cout << " n3 = " << n3 << endl ;
	cout << " n4 = " << n4 << endl << endl ;
	cout << " Testing out operators " << endl ;
	
	onlyUsedInAssign = n1 + 1;
	
	cout << " n1 + 1 = " << onlyUsedInAssign << endl ;

	onlyUsedInAssign = n2 + 189765;

	cout << " n2 + 189765 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = n2 + n3 ;
	cout << " n2 + n3 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = 8765309 + n4 ;
	cout << " 8675309 + n4 = " << onlyUsedInAssign << endl ;

	onlyUsedInAssign = n4 - n3;
	cout << " n4 - n3 = " << onlyUsedInAssign << endl;

	if ( n3 == n4 )
		cout << " n3 equals n4 " << endl ;
	else
		cout << " n3 does NOT equal n4 " << endl ;

	if ( n3 == 32536)
		cout << " n3 eqauls 32536 " << endl ;
	else
		cout << " n3 does NOT equal 32536 " << endl ;
	if ( n3 < n4 )
		cout << " n3 is less than n4 " << endl ;
	else
		cout << " n3 is NOT less than n4 " << endl ;

	if ( n4 < 8976534)
		cout << " n4 is less than 8976534 " << endl ;
	else
		cout << " n4 is NOT less than 8976534 " << endl ;

	if (8976534 < n3 )
		cout << " 8976534 is less than n3 " << endl ;
	else
		cout << " 8976534 is NOT less than n3 " << endl ;

	if (32536 == n2 )
		cout << " 32536 is equal to n2 " << endl ;
	else
		cout << " 32536 is NOT equal to n2 " << endl ;

	return 0;
}