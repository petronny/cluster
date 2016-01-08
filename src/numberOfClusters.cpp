#include "cluster.h"
#include <algorithm>
#include <cstring>
#include <cmath>
int numberOfClusters(const double* pgamma,int Num,double threshold) {
	double* buf=new double[Num]();
	memcpy(buf,pgamma,Num*sizeof(double));
	std::sort(buf,buf+Num);
	double sum=0.0;
	for(int i=0; i<Num; ++i)
		sum+=buf[i];
	double mu=sum/Num;
	sum=0.0;
	for(int i=0; i<Num; ++i)
		sum+=(buf[i]-mu)*(buf[i]-mu);
	double variance=sum/Num;
	double std=sqrt(variance);
	double prob=0;
	int nClusters=1;
	double var;
	for(int i=Num-1; i>=0; --i) {
		var=(buf[i]-mu)/std;
		prob=CDFofNormalDistribution(var);
		if(i>Num-100) cout<<" "<<prob;
		if(prob<threshold||(1-prob)<threshold)
			continue;
		nClusters=Num-1-i;
		break;
	}
	delete[] buf;
	return nClusters;
}

