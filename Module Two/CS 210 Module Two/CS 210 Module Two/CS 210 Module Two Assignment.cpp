/*
 * Calculator.cpp
 *
 *  Date: [5/15/2025]
 *  Author: [Juan Gonzalez]
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'y'; //Changed uppercase Y to lowercase y to keep it consistent within the loop, also inserted a semi-colon to end the line. Chaged the double quotes into single quotes to define a single character.
		while (answer == 'y')
		{
			cout << "Enter expression" << endl;
			cin >> op2 >> operation >> op1;

			//Changed multiple if statements into else if statements and clean up the code so that multiple expressions do not process at once.
			if (operation == '+') {
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; //Changed >> stream operator to << stream operator
			}
			else if (operation == '-') {
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; //Changed >> stream operator to << stream operator
			}
			else if (operation == '*') {
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; //Missing semi-colon at the end of the line, corrected the / operator in the cout statement.
			}
			else if (operation == '/') {
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //Corrected the * operator in the cout statement.
			}

			cout << "Do you wish to evaluate another expression (y/n)? " << endl; //Added (y/n) to the prompt to clarify the user input.
			cin >> answer;
		}
		cout << "Progam Finished." << endl; //Added print statement to indicate the end of the program.
}
