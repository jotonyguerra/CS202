#include "guerra_jotony_A9.cpp"

using namespace std;

int main()
{
	//call constructor for myStack
	//myStack stack(5);

	string input;
	myStack stack(1);
	//myStack stack2();
	int count = 0;
	char ch;

	cout << "Enter the arithmetic expression: ";
	getline(cin,input);

	while(input[count] != '\0')
	{
		if (input[count] == '{' or input[count] == '[' or input[count] == '(')
		{
			//cout << input[count] << endl;
			stack.push(input[count]);
		}

		if(stack.top() == '{' and input[count] == '}') //or input[count] == ']' or input[count] == ')')
			stack.pop();
		
		if(stack.top() == '(' and input[count] == ')')
			stack.pop();

		if(stack.top() == '[' and input[count] == ']')
			stack.pop();
		count++;

		if(stack.isEmpty() && input[count] == '}')
		{
			cout << "Oops , looks like something went wrong" << endl;
			return 0;
		}

		if(stack.isEmpty() && input[count] == ')')
		{
			cout << "Oops , looks like something went wrong" << endl;
			return 0;
		}

		if(stack.isEmpty() && input[count] == ']')
		{
			cout << "Oops , looks like something went wrong" << endl;
			return 0;
		}

	}


	//cout << stack.top() << endl;
	/*
	for(int i = 0; i <= count; i++)
	{
		if(input[i] == '}'or input[i] == ']' or input[i] == ')' )
		{
			if(stack.top() == '{' and input[i] == '}') //or input[count] == ']' or input[count] == ')')
				stack.pop();
		
			if(stack.top() == '(' and input[i] == ')')
				stack.pop();

			if(stack.top() == '[' and input[i] == ']')
				stack.pop();
		}
	}
	*/

	if(stack.isEmpty() == true)
		cout << "All brackets / parenthesis are matched correctly" << endl;
	else
		cout << "Oops , looks like something went wrong" << endl;




	//destructor
	

	return 0;

}