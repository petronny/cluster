#include <cmath>
double CDFofNormalDistribution(double x) {
	//const double PI=3.1415926;
	double p0=220.2068679123761;
	double p1=221.2135961699311;
	double p2=112.0792914978709;
	double p3=33.91286607838300;
	double p4=6.373962203531650;
	double p5=.7003830644436881;
	double p6=.03326249659989109;
	double q0=440.4137358247552;
	double q1=793.8265125199484;
	double q2=637.3336333788311;
	double q3=296.5642487796737;
	double q4=86.78073220294608;
	double q5=16.06417757920695;
	double q6=1.755667163182642;
	double q7=0.08838834764831844;
	double cutoff=7.071;
	double root2pi=2.506628274631001;
	double xabs=fabs(x);
	double res=0;
	if(x>37.0)
		res=1.0;
	else if(x<-37.0)
		res=0.0;
	else {
		double expntl=exp(-.5*xabs*xabs);
		double pdf=expntl/root2pi;
		if(xabs<cutoff)
			res=expntl*((((((p6*xabs + p5)*xabs + p4)*xabs + p3)*xabs+ p2)*xabs + p1)*xabs + p0)/(((((((q7*xabs + q6)*xabs + q5)*xabs + q4)*xabs + q3)*xabs + q2)*xabs + q1)*xabs+q0);
		else
			res=pdf/(xabs+1.0/(xabs+2.0/(xabs+3.0/(xabs+4.0/(xabs+0.65)))));
	}
	if(x>=0.0)
		res=1.0-res;
	return res;
}
