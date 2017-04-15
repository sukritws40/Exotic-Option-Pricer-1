#include "payoff.h"
#include "minmax.h"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator () (double Spot) const
{
	return max(Spot - Strike, 0.0);
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

double PayOffPut::operator () (double Spot) const
{
	return max(Strike - Spot, 0.0);
}

PayOffDigitalCall::PayOffDigitalCall(double Strike_) : Strike(Strike_)
{
}

double PayOffDigitalCall::operator () (double Spot) const
{
	return Spot > Strike ? 1 : 0.;
}

PayOffDigitalPut::PayOffDigitalPut(double Strike_) : Strike(Strike_)
{
}

double PayOffDigitalPut::operator () (double Spot) const
{
	return Spot < Strike ? 1 : 0.;
}
