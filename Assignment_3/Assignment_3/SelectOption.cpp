#include "SelectOption.h"

string SelectOption()
{
	string choice;

	int attempts = 4;
	for (; attempts >= 0; attempts--)
	{
		cin >> choice;

		if ((choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6") && attempts >= 0)
		{
			return choice;
			break;
		}
		else if ((choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6") && attempts == 0)
		{
			cout << "Error, run out of attempt. \n";
			exit(0);
		}
		else
		{
			cout << "Incorrect input, Please only enter a 1,2,3,4,5 or 6, attempt left: " << attempts << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

}
