#include "payoff.h"
#include "Process.h"

double MonteCarlo(const PayOff& thePayOff,
	const Process& theProcess,
	double Expiry,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths,
	double Kappa,
	double Theta);