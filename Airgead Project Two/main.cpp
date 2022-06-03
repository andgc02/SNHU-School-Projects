#include <iostream>
#include <stdexcept>
using namespace std;

#include "DataInputCalc.h"



int main() {

	DataInputCalc dataInput; //instantiate new object of type DataInputCalc Class
	int m_menuSelection = 0;

	try
	{

		do
		{
			cout << endl << "       Airgead Banking App  " << endl 
				<< "**********************************" << endl
				<< "1. Input New Data" << endl
				<< "2. Show Balance and Interest Without Additional Monthly Deposits" << endl
				<< "3. Show Balance and Interest With Additional Monthly Deposits" << endl
				<< "4. Quit Program" << endl
				<< "**********************************" << endl;

			cin >> m_menuSelection;
			if (cin.fail()) { //throw runtime error if user does not input valid selection
				throw runtime_error("Enter a valid selection.");
			}
			switch (m_menuSelection)
			{
			case 1:
				dataInput.PrintDataScreen(); //screen for user to input new data
				break;
			case 2:
				dataInput.setYearEndBalance(); //run year end balance calculations before displaying data to user
				dataInput.setYearEndEarnedInterest(); //calculate interests
				dataInput.PrintBalance(); //display data to user
				break;
			case 3:
				//case 3 calculates interest in a similar way to case 2 but adds the monthly deposit and compounds it
				dataInput.setYearEndWithMonthly();
				dataInput.setYearEndInterestWithMonthly();

				dataInput.PrintBalanceWithDeposits();
				break;
			case 4:
				break;
			default:
				break;
			}
		} while (m_menuSelection != 4);
	}
	catch (runtime_error &excpt)
	{
		cout << excpt.what() << endl;
		cout << "Error Please run program again." << endl;
	}
	return 0;
}