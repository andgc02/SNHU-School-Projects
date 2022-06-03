#pragma once
#ifndef DATA_INPUT_CALC_H
#define DATA_INPUT_CALC_H
#include <vector>

class DataInputCalc {
public:
	//Constructors
	DataInputCalc();
	DataInputCalc(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numYears);
	
	//Mutators
	void setYearEndBalance();
	void setYearEndEarnedInterest();
	void setYearEndWithMonthly();
	void setYearEndInterestWithMonthly();

	void PrintDataScreen();
	void PrintBalance();
	void PrintBalanceWithDeposits();
	
private:
	//Data Members
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_yearEndBalance;
	double m_yearEndEarnedInt;
	double m_yearEndBalanceMonthly;
	double m_yearEndEarnedIntMonthly;
	double m_tempInt;
	double m_compoundIntPrincipal;
	double m_futureVal;
	double m_futureValForPeriod;
	double m_tempInt2;

	vector<double> m_yearEndVect;
	vector<double> m_yearEndIntVect;
	vector<double> m_yearEndMonthlyVect;
	vector<double> m_yearEndIntMonthlyVect;

	int m_numYears;
	int i;
	int j;

};

#endif // !DATA_INPUT_CALC_H