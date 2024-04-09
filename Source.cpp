/*
Program name: MortgagePayment.cpp
Programmer: Tyler Davies
Date: 9-18-21
Version: 1.0
Description: This program demonstrates the created MonthlyMortgagePayment class which determines the
             monthly payment on a home mortgage. The class has member functions for setting the loan
             amount, interest rate, and number of years of the loan; and member functions for returning
             the monthly payment amount and the total amount paid to the bank at the end of the loan
             period. The class will not accept negative values as input from the user.
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Class declaration; this class helps determine the monthly payment on a home mortgage.
class MonthlyMortgagePayment
{
private:
    double monthlyPayment;
    double principal;
    double rate;
    int term;
    double totalMoneyOwed;
public:
    void setLoanAmount(double);
    void setInterestRate(double);
    void setNumYearsLoan(int);
    double calcMonthlyPayment();
    double calcTotalOwed();
};

//setLoanAmount assigns a value to principal (original amount agreed upon for the loan)
void MonthlyMortgagePayment::setLoanAmount(double loanAmount)
{
    principal = loanAmount;
}

//setInterestRate assigns a value to rate (interest rate)
void MonthlyMortgagePayment::setInterestRate(double interestRate)
{
    rate = interestRate;
}

//setNumYearsLoan assigns a value to term (number of years of the loan period)
void MonthlyMortgagePayment::setNumYearsLoan(int years)
{
    term = years;
}

//calcMonthlyPayment calculates and returns the monthly payment amount
double MonthlyMortgagePayment::calcMonthlyPayment()
{
    rate = rate / 1200.0;
    term = term * 12.0;
    monthlyPayment = (principal * rate) / (1.0 - pow(rate + 1, -term));
    
    return monthlyPayment;
}

//calcTotalOwed calculates and returns the total amount to be paid to the bank at the end of the loan period
double MonthlyMortgagePayment::calcTotalOwed()
{
    totalMoneyOwed = (monthlyPayment * 12) * term;
    return totalMoneyOwed;
}

//The main function serves to implement and test the MonthlyMortgagePayment class
int main()
{
    MonthlyMortgagePayment payment;
    double amount, interest, monthlyPaymentOwed, totalOwed;
    int numYears;
    bool validAmount = false, validInterest = false, validYears = false;

    while (!validAmount)
    {
        cout << "Enter the loan amount:" << endl;
        cin >> amount;
        if (amount < 0)
            cout << "Error: loan amount must be a positive value.\nPlease try again!" << endl;
        else
            validAmount = true;
    }
    payment.setLoanAmount(amount);

    while (!validInterest)
    {
        cout << "Enter the interest rate in decimal format:" << endl;
        cin >> interest;
        if (interest < 0)
            cout << "Error: interest rate must be a positive value.\nPlease try again!" << endl;
        else
            validInterest = true;
    }
    payment.setInterestRate(interest);

    while (!validYears)
    {
        cout << "Enter the number of years for the loan period:" << endl;
        cin >> numYears;
        if (numYears < 0)
            cout << "Error: number of years must be a positive value.\nPlease try again!" << endl;
        else
            validYears = true;
    }
    payment.setNumYearsLoan(numYears);

    monthlyPaymentOwed = payment.calcMonthlyPayment();
    totalOwed = payment.calcTotalOwed();

    cout << left << fixed << setprecision(2);
    cout << "The monthly payment owned on your home mortgage is: $" << monthlyPaymentOwed << endl;
    cout << "The total amount to be paid to the bank by the end of the loan period: $" << totalOwed << endl;

    exit(0);
}