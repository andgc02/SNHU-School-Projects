/*
 * Calculator.cpp
 *
 *  Date: 03/12/2022
 *  Author: Andre Cabrera
 */

#include <iostream>

using namespace std;

int main() //changed void main() to int main()
{
	//removed char statement[100];
	double op1; //changed op1 and op2 to double instead of int
	double op2;
	char operation;
	char answer = 'y'; //changed answer from "Y" to 'y' and added semicolon
	while (answer == 'y' || answer == 'Y')
	{
		cout << "CALCULATOR" << endl;
		cout << "Enter expression" << endl << "Guide:" << endl << "X + Y, X - Y, X * Y, X / Y" << endl;
		cin >> op2 >> operation >> op1;
		//changed all if statements to have curly brackets instead of semicolons
		if (operation == '+') { 
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; //changed >> to <<
		}
		if (operation == '-') {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
		}
		if (operation == '*') {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; //added a semicolon and changed the output symbol to / from * 
		}
		if (operation == '/') { //made proper code blocks
 			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //changed * to / when outputting
			}
		cout << "Do you wish to evaluate another expression? Y for yes and N for no." << endl;
		cin >> answer;
	}
	return 0; //added a return 0 statement to main()

}






