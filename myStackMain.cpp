#include <iostream>
#include <string>
#include "./myStack.cpp"

using namespace std;



int main()
{
	string str;
	//myStack list;

	//while(cin>> str)

	cout<< "Enter the arithmetic expression: ";

	getline(cin, str);
	//cout<< str<< endl;

	int j=0;
	int k=0;

	while(str[k] != '\0')
	{
		if(str[k] == '[' or str[k] == '(' or str[k] == '{')
		{
			j++;
		}

		k++;
	}

	myStack list(j);

	cout<< " Number read in: " << j << endl;

	int i=0;

	while(str[i]!= '\0')
	{
		if(str[i] == '[' or str[i] == '(' or str[i] == '{')
		{
			cout<< str[i]<< endl;
			list.push(str[i]);
		}

		if(list.top() == '[' and str[i] == ']')
		{
			list.pop();
		}

		if(list.top() == '{' and str[i] == '}')
		{
			list.pop();
		}

		if(list.top() == '(' and str[i] == ')')
		{
			list.pop();
		}

		i++;
	}

	if(list.isEmpty() == true)
	{
		cout<< "Done" << endl;
	}
	else
	{
		cout<< " dont match " << endl;
	}

	cout<< list.top() << endl;


	return 0;
}