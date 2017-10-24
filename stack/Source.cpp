
// problem 1, using stack programme
#include <iostream>
using namespace std;

int const max_size(10); 

class f_stack
{
public:				
	char stack[max_size]; 	
	char top;
	//char c;
	int n;

	//void input_s_elements(char candy);
	void clear_stack(); // clear_stack function declarition
	bool empty_stack(); // empty_stack declration
	bool full_stack(); // full_stack function declarion
	void push(char candy); // puch function declaration
	void pop(char &candy); // pop function declartion
};  ;


int main()
{
	f_stack o1;
	f_stack o2;
	int i(0), count(0);
	char name;
	char candyName;
	int n(0);

	o1.clear_stack();
	o2.clear_stack();

	cout << "Enter the candies in your container: " << endl;
	cout << "and make sure, it should be initial of candy color! like, 'b' for 'black'" << endl;
	cin >> candyName;

	while(!(o1.full_stack()) && candyName != '#')
	{
		o1.push(candyName);
		i++;
		if (i < 10)
		{
			cin >> candyName;
		}
	}
	
	cout << "Num. of candies: " << i << endl; // top is the index number not an elemet

	cout << "Enter the candy you want to eat! use initial of candy color. " << endl;
	cin >> name;

	while(!(o1.empty_stack()))
	{
		o1.pop(candyName);

		if (candyName != name)
			o2.push(candyName);
	}
	
	cout << "Remaining candies are: " << endl;
	
	while (!(o2.empty_stack()))
	{
		if (o2.top != -1)
			o2.pop(candyName);
			cout << candyName << endl;
	}
	system("pause");
}


void f_stack::clear_stack() // clear_stack function signature
{
	top = -1; //if 0 stack clear
}

bool f_stack::empty_stack() // empty_stack function signature
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool f_stack::full_stack() // full_stack function signature 
{
	if (top == max_size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void f_stack::push(char candy) // push function signature
{
	top = top + 1;
	stack[top] = candy;
}

void f_stack::pop(char &candy) // pop fuction signature
{
	candy = stack[top];
	top = top - 1;
}



