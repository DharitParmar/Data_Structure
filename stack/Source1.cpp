
// palindrome using Stack
#include <iostream>
#include <string>
using namespace std;

int const max_size(50);

class palin
{
public:
	char str[max_size]; 
	int top = 0;
	int n;

	//void input_s_elements(char candy);
	void clear_stack(); // clear_stack function declarition
	bool empty_stack(); // empty_stack declration
	bool full_stack(); // full_stack function declarion
	void push(char ltr); // puch function declaration
	void pop(char &ltr); // pop function declartion
}; 

// Palindrome logic 1 using Stack and array(type char)
int main()
{
	char word[50], ltr('m');
	string str;
	palin ob1;
	int i(0);
	int length(0);
	char response;
	int n(0);
	
		cout << "Enter a string or word: " << endl;
		getline(cin,str);
		length = str.length();
		
		for (int i = 0; i < length; i++)
		{
			if (str[i] != ' ')
			{
				word[n] = str[i];
				n++;
			}
		}

		while (!(ob1.full_stack()) && (i < n))
		{
			ob1.push(word[i]);
			i++;
		}
		cout << endl;

		for (i = 0; i < n; i++)
		{
			ob1.pop(ltr);
			if (ltr != word[i])
			{
				cout << "it's not a palindrome! " << endl << endl;
				cout << "but, by adding the following words, it can be one." << endl;
				for (i = 0; i < n-1; i++)
				{
					ob1.pop(ltr);
					cout << ltr ;
				}
				cout << endl;
				break;
			}
			else {
				n--;

				if ((i == n - 1) || (i - 1 == n - 1))
				{
					cout << "it's a palindrome" << endl;
				}
			}
		}
	system("pause");
}	

void palin::clear_stack() // clear_stack function signature
{
	top = 0; //if 0 stack clear
}

bool palin::empty_stack() // empty_stack function signature
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

bool palin::full_stack() // full_stack function signature 
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

void palin::push(char ltr) // push function signature
{
	top = top + 1;
	str[top] = ltr;
}

void palin::pop(char &ltr) // pop fuction signature
{
	ltr = str[top];
	top = top - 1;
}
