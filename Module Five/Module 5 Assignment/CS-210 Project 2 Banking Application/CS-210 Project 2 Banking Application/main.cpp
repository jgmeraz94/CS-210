//Juan Gonzalez
//CS-210
//06/08/2023

#include <iostream>
#include <iomanip>
#include "bankingcalculator.h"

using namespace std;

int main() {
    double initial, monthly, rate;
    int years;
    char choice = 'Y';


    // Display initial screen
    cout << string(32, '*') << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount:" << endl;
    cout << "Monthly Deposit:" << endl;
    cout << "Annual Interest:" << endl;
    cout << "Number of years:" << endl;
    cout << "Press any key to continue . . .";
    cin.get();


	// Main loop of application to allow user to input values and see results until they choose to exit
    while (choice == 'Y' || choice == 'y') {

        // Input all values at once
        cout << "\nEnter the following values separated by spaces:\n";
        cout << "Initial MonthlyDeposit AnnualInterest Years\n";
        cin >> initial >> monthly >> rate >> years;

        // Print the screen again, this time with user input
        cout << endl;
        cout << string(32, '*') << endl;
        cout << "********** Data Input **********" << endl;
        cout << "Initial Investment Amount: $" << initial << endl;
        cout << "Monthly Deposit: $" << monthly << endl;
        cout << "Annual Interest: %" << rate << endl;
        cout << "Number of years: " << years << endl;
        cout << "Press any key to continue . . .";
        cin.ignore();
        cin.get();

        // Create a new calculator with updated values
        BankingCalculator calculator(initial, monthly, rate, years);

        // Display report without monthly deposits
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        cout << string(66, '=') << endl;
        cout << right << setw(6) << "Year"
            << right << setw(30) << "Year End Balance"
            << right << setw(30) << "Year End Earned Interest" << endl;
        cout << string(66, '-') << endl;
        calculator.calculateBalanceWithoutMonthlyDeposit();

        // Display report with monthly deposits
        cout << "\nBalance and Interest With Additional Monthly Deposits\n";
        cout << string(66, '=') << endl;
        cout << right << setw(6) << "Year"
            << right << setw(30) << "Year End Balance"
            << right << setw(30) << "Year End Earned Interest" << endl;
        cout << string(66, '-') << endl;
        calculator.calculateBalanceWithMonthlyDeposit();

        // Ask if the user wants to test again
        cout << "\nWould you like to test another scenario? (Y/N): " << endl;
        cin >> choice;
    }

    return 0;
}