#include <cstdlib>
#include <cmath>

#include "BoxMuller.h"
#include "MonteCarlo.h"
#include "Process.h"
#include "payoff.h"

double MonteCarlo(const PayOff& thePayOff,
	const Process& theProcess,
	double Expiry,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths,
	double Kappa,
	double Theta)
{
	double runningSum = 0.0;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisSpot = theProcess.evolve(Spot, r, Expiry, Vol, Kappa, Theta);
		double thisPayOff = thePayOff(thisSpot);
		runningSum += thisPayOff;
	}
	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}