#include "Process.h"
#include "BoxMuller.h"
#include <cmath>

ProcessGB::ProcessGB()
{
}

double ProcessGB::evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const
{
	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double thisGaussian = getOneGaussianByBoxMuller();
	double itoCorrection = -0.5*Vol*Vol*Expiry;
	return Spot*exp(r*Expiry + itoCorrection)* exp(rootVariance * thisGaussian);

}

ProcessBach::ProcessBach()
{
}

double ProcessBach::evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const

{
	double variance = exp(((2 * r*Expiry) - 1) / (2 * r));
	double rootVariance = sqrt(variance);
	double thisGaussian = getOneGaussianByBoxMuller();
	return Spot*exp(r*Expiry) + rootVariance*thisGaussian;
}

ProcessMean::ProcessMean()
{
}

double ProcessMean::evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const {
	
	double variance = (exp(2 * kappa*Expiry) - 1) / (2 * kappa);
	double rootVariance = sqrt(variance);
	double thisGaussian = getOneGaussianByBoxMuller();
	return Spot + ((kappa*theta + r - variance / 2)*(exp(kappa*Expiry) - 1) / kappa) + rootVariance*thisGaussian;
}
