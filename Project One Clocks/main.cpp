//import libraries
#include <iostream>
#include <iomanip>
#include "clock.h" //import header file

int main()
{
	int menuSelection = 0; //variable for user to select items from menu
	Clock t; //create t object of type Clock

	do
	{
		//display clock and menu
		t.displayClock();
		cout << "**************************" << endl;
		cout << "* 1-Add One Hour         *" << endl;
		cout << "* 2-Add One Minute       *" << endl;
		cout << "* 3-Add One Second       *" << endl;
		cout << "* 4-Exit Program         *" << endl;
		cout << "**************************" << endl;

		//get menu selection from user
		cin >> menuSelection;
		switch (menuSelection)
		{
		case 1:
			t.addHour(1);
			break;
		case 2:
			t.addMinute(1);
			break;
		case 3:
			t.addSecond(1);
			break;
		}
	} while (menuSelection != 4);
	return 0;

}