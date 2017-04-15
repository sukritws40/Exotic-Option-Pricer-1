#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

double double_check(string x) 
{
	char s[80];
	double d;
	char c;
	int a = 0;
	char *step;
	while (a<6) 
	{
		cout << x.c_str() << ": ";
		fflush(stdout);
		rewind(stdin);
		fgets(s, 80, stdin);
		if (2 == sscanf_s(s, "%lf%c", &d, &c) && strtod(s, &step) >= 0)
		{
			if ('\n' == c) 
			{
				break;
			}
		}
		if ('\n' == s[strlen(s) - 1] || strtod(s, &step) < 0)
		{
			s[strlen(s) - 1] = 0;
			++a;
			if (a < 5)
			{
				if (strtod(s, &step) < 0)
				{
					cout << x.c_str() <<  " Input must be a positive number, please try again, " << 5 - a << " attempts left" << endl;
				}

				else
				{
					cout << x.c_str() << " Input must be a positive number, please try again, " << 5 - a << " attempts left" << endl;
				}
			}

			else
			{
				if (strtod(s, &step) < 0)
				{
					cout << x.c_str() << " Input can't be a negative number, please try again, " << 5 - a << " attempts left" << endl;
				}

				else
				{
					cout << x.c_str() << " Input must be a positive number, please try again, " << 5 - a << " attempts left" << endl;
					cout << "Error, running out of attempt" << endl;
					exit(0);

				}
				
			}
		}
	}

	d = strtod(s, &step);
	return d;
}