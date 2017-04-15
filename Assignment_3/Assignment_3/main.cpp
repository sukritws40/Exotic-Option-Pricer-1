#include <iostream>
#include <string>

#include "double_check.h"
#include "unsignedlong_check.h"
#include "LowerStrike_check.h"
#include "payoff.h"
#include "MonteCarlo.h"
#include "restart.h"
#include "DoubleDigital.h"
#include "Process.h"
#include "SelectProcess.h"
#include "SelectOption.h"
#include "Greek_check.h"
#include "BoxMuller.h"

using namespace std;

int main()
{




	cout << "=======================================================================================================================" << endl;
	cout << "                                               Monte Carlo Option Pricer" << endl;
	cout << "=======================================================================================================================" << endl;
	cout << "Welcome to Monte Carlo Option Pricer\n" << "\nPlease note that inputs required are:" << endl;
	cout << "1. Years to Expiry\n" << "2. Spot Price\n" << "3. Strike Price\n" << "4. Annualized Volatility\n" << "5. Short Rate\n" << "6. Number of Path" << endl;
	cout << "\nFor double digital Upper Strike and Lower Strike are required" << endl;
	cout << "For Mean Reverting log-normal Process Kappa and Theta required" << endl;
	cout << "=======================================================================================================================" << endl;

	bool r = true;
	while (r == true)
	{
		
		
		cout << "\nPlease Select your Option type" << endl;
		cout << "Please type 1 for European Call" << endl;
		cout << "Please type 2 for European Put" << endl;
		cout << "Please type 3 for Digital Call" << endl;
		cout << "Please type 4 for Digital Put" << endl;
		cout << "Please type 5 for Double Digital" << endl;
		cout << "Please type 6 to Exit\n" << endl;

		cout << "Your Option type is: ";
		string n = SelectOption();

		unsigned long NumberOfPath;
		double input[5];
		double input_doubledigital[4];
		double UpperStrike;
		double LowerStrike;
		double ShortRate;
		
		string input_name[4] = { "Years to expiry",
			"Strike price",
			"Spot price",
			"Annualized volatility"};
		
		string input_name_doubledigital[3] = { "Years To Expiry",
			"Spot",
			"Annualized Volatility"};
		
		string path = "Number of Path";

		string option_type;
		double kappa;
		double theta;
		
		if (n == "1" || n == "2" || n == "3" || n == "4")
		{
			cout << "\nPlease Select your Process" << endl;
			cout << "Please type 1 for Geometric Brownian Process" << endl;
			cout << "Please type 2 for Bachelier Process" << endl;
			cout << "Please type 3 for Mean Reverting log-normal Process\n" << endl;

			cout << "Your Process is: ";
			string p = SelectProcess();

			string Process_type;

			Process* theProcess;

			if (p == "1")
			{
				theProcess = new ProcessGB();
				Process_type = "Geometric Brownian Process";
				kappa = 0;
				theta = 0;
			}
			else if (p == "2")
			{
				theProcess = new ProcessBach();
				Process_type = "Bachelier Process";
				kappa = 0;
				theta = 0;
			}
			else
			{
				theProcess = new ProcessMean();
				Process_type = "Mean Reverting log-normal Process";
				
				cout << "Please input Kappa & Theta for mean reverting log-normal process" << endl;

				kappa = Greek_check("Kappa");
				theta = Greek_check("Theta");
			}

			for (int i = 0; i<4; i++)
			{
				input[i] = double_check(input_name[i]);
			}
			ShortRate = Greek_check("Short Rate");
			NumberOfPath = unsignedlong_check(path);

			cout << "=======================================================================================================================" << endl;
			cout << "Your Inputs are" << endl;
			cout << "=======================================================================================================================" << endl;
			cout << "Years To Expiry       : " << *(input + 0) << endl;
			cout << "Strike                : " << *(input + 1) << endl;
			cout << "Spot                  : " << *(input + 2) << endl;
			cout << "Annualized Volatility : " << *(input + 3) << endl;
			cout << "Short Rate            : " << ShortRate << endl;
			cout << "Number Of Paths       : " << NumberOfPath << endl;

			PayOff* thePayOff;

			if (n == "1")
			{
				thePayOff = new PayOffCall(*(input + 1));
				option_type = "European Call";
			}

			else if (n == "2")
			{
				thePayOff = new PayOffPut(*(input + 1));
				option_type = "European Put";
			}

			else if (n == "3")
			{
				thePayOff = new PayOffDigitalCall(*(input + 1));
				option_type = "Digital Call";
			}

			else
			{
				thePayOff = new PayOffDigitalPut(*(input + 1));
				option_type = "Digital Put";
			}

			double price = MonteCarlo(*thePayOff,
				*theProcess,
				*(input + 0),
				*(input + 2),
				*(input + 3),
				ShortRate,
				NumberOfPath,
				kappa,
				theta);

			delete thePayOff;
			delete theProcess;

			cout << "=======================================================================================================================" << endl;
			cout << "Your Process type: " << Process_type << endl;
			cout << option_type << " price: " << price << endl;
			cout << "=======================================================================================================================" << endl;
		}

		else if (n == "5")
		{
			option_type = "Double Digital";

			cout << "\nPlease Select your Process" << endl;
			cout << "Please type 1 for Geometric Brownian Process" << endl;
			cout << "Please type 2 for Bachelier Process" << endl;
			cout << "Please type 3 for Mean Reverting log-normal Process\n" << endl;

			cout << "Your Process is: ";
			string p = SelectProcess();

			string Process_type;

			Process* theProcess;

			if (p == "1")
			{
				theProcess = new ProcessGB();
				Process_type = "Geometric Brownian Process";
				kappa = 0;
				theta = 0;
			}
			else if (p == "2")
			{
				theProcess = new ProcessBach();
				Process_type = "Bachelier Process";
				kappa = 0;
				theta = 0;
			}
			else
			{
				theProcess = new ProcessMean();
				Process_type = "Mean Reverting log-normal Process";

				cout << "Please input Kappa & Theta for mean reverting log-normal process" << endl;

				kappa = Greek_check("Kappa");
				theta = Greek_check("Theta");
			}

			UpperStrike = double_check("Upper Strike");
			LowerStrike = LowerStrike_check("Lower Strike", UpperStrike);
			
			for (int i = 0; i<3; i++)
			{
				input_doubledigital[i] = double_check(input_name_doubledigital[i]);
			}
			ShortRate = Greek_check("Short Rate");
			NumberOfPath = unsignedlong_check(path);

			cout << "=======================================================================================================================" << endl;
			cout << "Your Inputs are" << endl;
			cout << "=======================================================================================================================" << endl;
			cout << "Years To Expiry       : " << *(input_doubledigital + 0) << endl;
			cout << "Upper Strike          : " << UpperStrike << endl;
			cout << "Lower Strike          : " << LowerStrike << endl;
			cout << "Spot                  : " << *(input_doubledigital + 1) << endl;
			cout << "Annualized Volatility : " << *(input_doubledigital + 2) << endl;
			cout << "Short Rate            : " << ShortRate << endl;
			cout << "Number Of Paths       : " << NumberOfPath << endl;

			PayOffDoubleDigital thePayOff(LowerStrike, UpperStrike);
			
			double price = MonteCarlo(thePayOff,
				*theProcess,
				*(input_doubledigital + 0),
				*(input_doubledigital + 1),
				*(input_doubledigital + 2),
				ShortRate,
				NumberOfPath,
				kappa,
				theta);

			cout << "=======================================================================================================================" << endl;
			cout << option_type << " price: " << price << endl;
			cout << "=======================================================================================================================" << endl;
		}

		else 
		{
			cout << "=======================================================================================================================" << endl;
			cout << "Thankyou for using our software." << endl;
			cout << "=======================================================================================================================" << endl;
			exit(0);
		}
		r = restart();
	}
	
}