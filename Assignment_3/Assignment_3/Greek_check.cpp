#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

double Greek_check(string x)
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
		if (2 == sscanf_s(s, "%lf%c", &d, &c))
		{
			if ('\n' == c)
			{
				break;
			}
		}
		if ('\n' == s[strlen(s) - 1])
		{
			s[strlen(s) - 1] = 0;
			++a;
			if (a < 5)
			{
				
					cout << x.c_str() << " Input must be a number, please try again, " << 5 - a << " attempts left" << endl;
				
			}

			else
			{
				
					cout << x.c_str() << " Input must be a number, please try again, " << 5 - a << " attempts left" << endl;
					cout << "Error, running out of attempt" << endl;
					exit(0);

				

			}
		}
	}

	d = strtod(s, &step);
	return d;
}