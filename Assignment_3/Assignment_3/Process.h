#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
	Process() {};
	virtual ~Process() {}
	virtual double evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const = 0;

private:

};

class ProcessGB : public Process
{
public:

	ProcessGB();
	virtual ~ProcessGB() {}
	double evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const;

private:

};

class ProcessBach : public Process
{
public:
	ProcessBach();
	virtual ~ProcessBach() {}

	double evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const;

private:

};

class ProcessMean : public Process
{
public:
	ProcessMean();
	virtual ~ProcessMean() {}

	double evolve(double Spot, double r, double Expiry, double Vol, double kappa, double theta) const;

private:
	
};

#endif
