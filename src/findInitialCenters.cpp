#include "cluster.h"
int findInitialCenters(const double* rho,const double* delta,
                       int Num,int nClus,vector<int> &vec) {
	if(NULL==rho||NULL==delta)
		return -1;
	vec.clear();
	double rho_min,rho_max;
	rho_min=rho_max=*rho;
	for(int i=1; i<Num; ++i) {
		if(*(rho+i)>rho_max) rho_max=*(rho+i);
		else if(*(rho+i)<rho_min) rho_min=*(rho+i);
	}
	double rho_range=rho_max-rho_min;
	double delta_min,delta_max;
	delta_min=delta_max=*delta;
	for(int ii=1; ii<Num; ++ii) {
		if(*(delta+ii)>delta_max) delta_max=*(delta+ii);
		else if(*(delta+ii)<delta_min) delta_min=*(delta+ii);
	}
	double delta_range=delta_max-delta_min;
	double* pgamma=new double[Num];
	for(int t=0; t<Num; ++t)
		*(pgamma+t)=(*(rho+t)-rho_min)*(*(delta+t)-delta_min)/(rho_range*delta_range);
	if(nClus<=0) {
		double thres=5e-2;
		nClus=numberOfClusters(pgamma,Num,thres);
	}
	for(int s=0; s<nClus; ++s) {
		int max=s;
		for(int j=s+1; j<Num; ++j)
			if(*(pgamma+max)<*(pgamma+j)) max=j;
		std::swap(*(pgamma+s),*(pgamma+max));
		vec.push_back(max);
	}
	delete[] pgamma;
	return nClus;
}

