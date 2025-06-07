#ifndef BANKING_CALCULATOR_H
#define BANKING_CALCULATOR_H

class BankingCalculator {
public:
    // Constructor to initialize investment details
    BankingCalculator(double initial, double monthly, double rate, int years);

    // Calculates balance without monthly deposit
    double calculateBalanceWithoutMonthlyDeposit();

    // Calculates balance with monthly deposit
    double calculateBalanceWithMonthlyDeposit();

    // Prints details for a given year
    void printDetails(int year, double yearEndBalance, double interestEarned);

private:
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numberOfYears;
};

#endif
