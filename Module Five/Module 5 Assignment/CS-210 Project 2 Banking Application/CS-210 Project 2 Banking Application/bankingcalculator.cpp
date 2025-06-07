#include "bankingcalculator.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Constructor to initialize values
BankingCalculator::BankingCalculator(double initial, double monthly, double rate, int years) {
    initialInvestment = initial;
    monthlyDeposit = monthly;
    interestRate = rate;
    numberOfYears = years;
}

// Calculates and prints yearly balances without monthly deposits
double BankingCalculator::calculateBalanceWithoutMonthlyDeposit() {
    double balance = initialInvestment;
    double monthlyRate = (interestRate / 100.0) / 12.0;
    double interest = 0.0;
    double interestEarnedThisYear = 0.0;

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarnedThisYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            interest = balance * monthlyRate;
            interestEarnedThisYear += interest;
            balance += interest;
        }

        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}

// Calculates and prints yearly balances with monthly deposits
double BankingCalculator::calculateBalanceWithMonthlyDeposit() {
    double balance = initialInvestment;
    double monthlyRate = (interestRate / 100.0) / 12.0;
    double interest = 0.0;
    double interestEarnedThisYear = 0.0;

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarnedThisYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit;
            interest = balance * monthlyRate;
            interestEarnedThisYear += interest;
            balance += interest;
        }

        printDetails(year, balance, interestEarnedThisYear);
    }

    return balance;
}

// Prints formatted details of a single year's results and sets alignment for output
void BankingCalculator::printDetails(int year, double yearEndBalance, double interestEarned) {
    stringstream balanceStream, interestStream;
    balanceStream << "$" << fixed << setprecision(2) << yearEndBalance;
    interestStream << "$" << fixed << setprecision(2) << interestEarned;
    cout << right << setw(6) << year
        << right << setw(30) << balanceStream.str()
        << right << setw(30) << interestStream.str()
        << endl;
}