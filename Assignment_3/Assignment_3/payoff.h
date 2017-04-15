#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:

	PayOff() {};
	virtual double operator()(double Spot) const = 0;
	virtual ~PayOff() {}

private:

};


class PayOffCall : public PayOff
{
public:

	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {}

private:

	double Strike;

};


class PayOffPut : public PayOff
{
public:

	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {}

private:

	double Strike;

};


class PayOffDigitalCall : public PayOff
{
public:

	PayOffDigitalCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDigitalCall() {}

private:

	double Strike;

};

class PayOffDigitalPut : public PayOff
{
public:

	PayOffDigitalPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDigitalPut() {}

private:

	double Strike;

};
#endif



