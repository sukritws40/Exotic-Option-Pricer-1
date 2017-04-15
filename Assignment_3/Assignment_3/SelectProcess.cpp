#include "SelectProcess.h"

string SelectProcess()
{
	string choice;

	int attempts = 4;
	for (; attempts >= 0; attempts--)
	{
		cin >> choice;

		if ((choice == "1" || choice == "2" || choice == "3") && attempts >= 0)
		{
			return choice;
			break;
		}
		else if ((choice != "1" || choice != "2" || choice != "3") && attempts == 0)
		{
			cout << "Error, run out of attempt. \n";
			exit(0);
		}
		else
		{
			cout << "Incorrect input, Please only enter a 1,2 or 3, attempt left: " << attempts << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

}
