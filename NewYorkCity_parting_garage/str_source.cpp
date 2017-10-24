// parking garage with String input

#include <iostream>
#include <string>
#include "string_.h"
using namespace std;

void arrival(string num);
int depart(string num);
void getclose();
void printAll();
void input_validation(char choice);
char_garage g1;
char_garage g2;
char_garage street;
char_garage temp;
int sum;
int total;

int main()	// main function-------------
{
	char choice('#');
	//int num;

	g1.clear_q();
	g2.clear_q();
	temp.clear_q();
	street.clear_q();

	cout << "Enter 'A' to park... Enter 'D' for depart...else, enter 'X' to exit..." << endl;
	cin >> choice;
	input_validation(choice);

	system("pause");
}	// main fini-------------------------

void input_validation(char choice)
{
	string num;
	do
	{
		if (choice == 'x' || choice == 'X') {
			cout << endl;
			getclose();
			break;
		}
		else if (choice == 'a' || choice == 'A') {
			cout << "Tell me your vehicle number" << endl;
			cin >> num;
			arrival(num);
		}
		else if (choice == 'd' || choice == 'D') {
			cout << "Tell me your vehicle number" << endl;
			cin >> num;
			depart(num);
		}
		else
		{
			cout << "Invalid input, try again! " << endl;
		}

		cout << "_________________________________________________ " << endl;
		cout << "Enter 'A' to park... Enter 'D' for depart...else, enter 'X' to exit..." << endl;
		cin >> choice;

	} while (choice != 'X' || choice != 'x');
}

//-----------------arrival function-----------------------------
void arrival(string num)
{
	if (!(g1.full_q()))
	{
		g1.insert_q(num);
		cout << "Your vehicle num. '" << num << "' parked safly in 'knowkemdead'." << endl;
	}
	else if (!(g2.full_q()))
	{

		g2.insert_q(num);
		cout << "Your vehicle num. '" << num << "' parked safly in 'Bashemup'." << endl;
	}
	else if (!(street.full_q()))
	{
		street.insert_q(num);
		cout << "Your vehicle num. '" << num << "' parked safly on street." << endl;
	}
	else
	{
		cout << "Sorry! All the parking slots are packed, please drive to 'BOSTON AVENUE'. " << endl;
	}
}

//---------- depart function-------------------------------------------

int depart(string num)
{
	int i(0);
	int found(0);
	string numb;

	temp.clear_q();

	while (!(g1.empty_q()))
	{
		i++;
		g1.delete_q(numb);


		//if (!numb.compare(num))
		if (numb != num)
		{
			temp.insert_q(numb);
		}
		else
		{
			found = 1;
			if (i == 1)
			{
				cout << "Your car comes out from 'knowkemdead', you have to pay $ 10." << endl;
				sum += 10;
			}
			else if (i == 2)
			{
				cout << "Your car comes out from 'knowkemdead', you have to pay $ 20." << endl;
				sum += 20;
			}
			else
			{
				cout << "Your car comes out from 'knowkemdead', you have to pay $ 30." << endl;
				sum = sum + 30;
			}
		}
	}
	while (!(temp.empty_q()))
	{
		temp.delete_q(numb);
		g1.insert_q(numb);
	}

	if (!(g1.full_q()) && !(street.empty_q()))
	{
		street.delete_q(numb);
		g1.insert_q(numb);
		cout << "Congrats..! As there were spot available in 'knowkemdead', a car has been moved from 'street' to 'knowkemdead'." << endl;
	}

	temp.clear_q();

	//----------garage 2--------------------
	if (found == 0)
	{
		i = 0;
		while (!(g2.empty_q()))
		{
			i++;
			g2.delete_q(numb);

			//if (!numb.compare(num))
			if (numb != num)
			{
				temp.insert_q(numb);
			}
			else
			{
				found = 1;
				if (i == 1)
				{
					cout << "Your car comes out from 'Bashemup', you have to pay $ 10" << endl;
					sum += 10;
				}
				else if (i == 2)
				{
					cout << "Your car comes out from 'Bashemup', you have to pay $ 20" << endl;
					sum += 20;
				}
				else
				{
					cout << "Your car comes out from 'Bashemup', you have to pay $ 30" << endl;
					sum = sum + 30;
				}
			}
		}

		while (!(temp.empty_q()))
		{
			temp.delete_q(numb);
			g2.insert_q(numb);
		}

		if (!(g2.full_q()) && !(street.empty_q()))
		{
			street.delete_q(numb);
			g2.insert_q(numb);
			cout << "Congrats..! As there were spot available in 'Bashemup', a car has been moved from 'street' to 'Bashemup'." << endl;
		}

		temp.clear_q();

		//---------------street---------------------
		if (found == 0)
		{
			i = 0;
			while (!(street.empty_q()))
			{
				i++;
				street.delete_q(numb);

				//if (!numb.compare(num))
				if (numb != num)
				{
					temp.insert_q(numb);
				}
				else
				{
					found = 1;
					cout << "Your vehicle comes out from the 'street'. " << endl;
					cout << "Thank you for your kind passions !" << endl;
				}
			}
		}

		while (!(temp.empty_q()))
		{
			temp.delete_q(numb);
			street.insert_q(numb);
		}
	}

	temp.clear_q();
	if (found == 0)
	{
		cout << "Oh.! your car isn't parked here, you got a big 'APPLE'..!" << endl;
	}
	found = 0;
	return sum;
}

void getclose()
{
	int cars_in_knowk(0);
	int cars_in_bash(0);
	int cars_in_street(0);
	int total = sum;
	string numb;

	cout << "-------------------------------------------------------------------" << endl;
	if (!(g1.empty_q()))
		while (!(g1.empty_q()))
		{
			g1.delete_q(numb);
			temp.insert_q(numb);
			cars_in_knowk++;
			if (g1.empty_q())
			{
				g1.clear_q();
				cout << "There are still " << cars_in_knowk << " cars parked in knowkemdead " << endl;
			}
		}
	else
	{
		g1.clear_q();
		cout << "There are " << cars_in_knowk << " cars  parked in knowkemdead. " << endl;
	}

	if (!(g2.empty_q()))
		while (!(g2.empty_q()))
		{
			g2.delete_q(numb);
			temp.insert_q(numb);
			cars_in_bash++;
			if (g2.empty_q())
			{
				g2.clear_q();
				cout << "There are still " << cars_in_bash << " cars parked in bashemup. " << endl;
			}
		}
	else
	{
		g2.clear_q();
		cout << "There are " << cars_in_bash << " cars parked in bashemup. " << endl;
	}

	if (!(street.empty_q()))
		while (!(street.empty_q()))
		{
			street.delete_q(numb);
			temp.insert_q(numb);
			cars_in_street++;
			if (street.empty_q())
			{
				street.clear_q();
				cout << "There are still " << cars_in_street << " cars parked on the street. " << endl;
			}
		}
	else
	{
		street.clear_q();
		cout << "There are " << cars_in_street << " cars parked on the street " << endl << endl;
	}

	cout << "-> Total fees collection till now is: " << total << endl;
	cout << "-------------------------------------------------------------------" << endl;
}