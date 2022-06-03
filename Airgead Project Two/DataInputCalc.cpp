#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

#include "DataInputCalc.h"

//Constructors
DataInputCalc::DataInputCalc() {
	m_initialInvestment = 0.0;
	m_monthlyDeposit = 0.0;
	m_annualInterest = 0.0;
	m_numYears = 0;
	m_yearEndBalance = 0;
	m_yearEndEarnedInt = 0;
	i = 0;
	j = 0;
	m_tempInt = 0;
}

DataInputCalc::DataInputCalc(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numYears) {
	m_initialInvestment = t_initialInvestment;
	m_monthlyDeposit = t_monthlyDeposit;
	m_annualInterest = t_annualInterest;
	m_numYears = t_numYears;
	m_yearEndBalance = 0;
	m_yearEndEarnedInt = 0;
	i = 0;
	j = 0;
	m_tempInt = 0;

}

//Mutators
void DataInputCalc::setYearEndBalance() {
	//Calculate the first year end balance with interest
	m_yearEndBalance = m_initialInvestment + ((m_initialInvestment) * (m_annualInterest / 100));
	m_yearEndVect.push_back(m_yearEndBalance); //adds the first year's balance to the vector
	for (j = 1; j < m_numYears; j++) { //add the rest of the year end balance's to the vector
		m_yearEndBalance = m_yearEndBalance + ((m_yearEndBalance) * (m_annualInterest / 100));
		m_yearEndVect.push_back(m_yearEndBalance);
	}
}

void DataInputCalc::setYearEndEarnedInterest() {
	//calculate only the earned interest from the first year 
	m_yearEndEarnedInt = (m_initialInvestment) * (m_annualInterest / 100);
	m_yearEndIntVect.push_back(m_yearEndEarnedInt); //add the earned interest to a vector
	for (j = 1; j < m_numYears; j++) { //calculate and add the rest of the earned interests to a vector
		m_yearEndEarnedInt = (m_yearEndEarnedInt + m_yearEndVect.at(j-1)) * (m_annualInterest / 100);
		m_yearEndIntVect.push_back(m_yearEndEarnedInt);
	}
}

void DataInputCalc::setYearEndWithMonthly() {
	for (j = 1; j <= m_numYears; j++) { //iterate through all the years to calculate the year end balance of each year
		m_tempInt = 1 + (m_annualInterest / 100) / 12; //break down the base for pow() in m_compoundIntPrincipal and m_futureVal
		m_tempInt2 = 12 * j; //break down the exponent for pow() in m_compoundIntPrincipal and m_futureVal

		m_compoundIntPrincipal = m_initialInvestment * pow(m_tempInt, m_tempInt2); //calculate the compound interest on the initial investment
		m_futureVal = m_monthlyDeposit * ((pow(m_tempInt, m_tempInt2) - 1) / ((m_annualInterest / 100) / 12)); //calculate the future value of each deposit of each month
		m_futureValForPeriod = 1 + ((m_annualInterest / 100) / 12); //calculate the future value since deposits need to be accounted for

		m_yearEndBalanceMonthly = m_compoundIntPrincipal + m_futureVal * m_futureValForPeriod; //add the initial compound interest with the future value of the series
		m_yearEndMonthlyVect.push_back(m_yearEndBalanceMonthly);
	}
}

void DataInputCalc::setYearEndInterestWithMonthly() {
	for (j = 1; j <= m_numYears; j++) {
		m_yearEndEarnedInt = m_yearEndMonthlyVect.at(j - 1) - (m_yearEndEarnedInt + m_initialInvestment + (m_monthlyDeposit * (j * 12)));
		m_yearEndIntMonthlyVect.push_back(m_yearEndEarnedInt);
	}
}

void DataInputCalc::PrintDataScreen() {
	cout << "**********************************" << endl
		<< "************Data Input************" << endl;
	cout << "Initial Investment Amount: $";
	cin >> m_initialInvestment;
	cout << endl << "Monthly Deposit: $";
	cin >> m_monthlyDeposit;
	cout << endl << "Annual Interest: %";
	cin >> m_annualInterest;
	cout << endl << "Number of Years: ";
	cin >> m_numYears;
	m_yearEndBalance = 0;
	m_yearEndEarnedInt = 0;

	//clear all vectors so user can see the data with new information
	m_yearEndVect.clear();
	m_yearEndIntVect.clear();
	m_yearEndMonthlyVect.clear();
	m_yearEndIntMonthlyVect.clear();
}

void DataInputCalc::PrintBalance() {
	cout << "   Balance and Interest Without Additional Monthly Deposits " << endl;
	cout << "===============================================================";
	cout << endl;
	cout << setw(20) << left << "Year";
	cout << setw(20) << left << "Year End Balance";
	cout << setw(20) << right << "Year End Earned Interest" << endl;
	for (i = 1; i <= this->m_numYears; i++) { //iterate through each year to add each line
		cout << setw(20) << left << i;
		cout << setw(20) << left << setprecision(3) << showpoint << m_yearEndVect.at(i - 1);
		cout << setw(20) << right << setprecision(1) << m_yearEndIntVect.at(i - 1) << endl;
	}
}

void DataInputCalc::PrintBalanceWithDeposits() {
	cout << "   Balance and Interest With Additional Monthly Deposits " << endl;
	cout << "===============================================================";
	cout << endl;
	cout << setw(20) << left << "Year";
	cout << setw(20) << left << "Year End Balance";
	cout << setw(20) << right << "Year End Earned Interest" << endl;
	cout << setprecision(3) << showpoint;
	for (i = 1; i <= this->m_numYears; i++) {
		cout << setw(20) << left << i;
		cout << setw(20) << left << setprecision(5) << showpoint << m_yearEndMonthlyVect.at(i - 1);
		cout << setw(20) << right << setprecision(5) << m_yearEndIntMonthlyVect.at(i-1) << endl;
	}
}
