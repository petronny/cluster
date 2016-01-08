#include "cluster.h"
void getDelta(double** matrix,int Num,const double* rho,double* delta, int* neighbor,int* order) {
	sortByDensity(rho,Num,order);
	double globalMax=getMatrixData(matrix,0,0);
	for(int i=0; i<Num; ++i) {
		double min=getMatrixData(matrix,order[i],order[0]);
		double buf=0;
		*(neighbor+order[i])=order[0];
		for(int j=0; j<i; ++j) {
			buf=getMatrixData(matrix,order[i],order[j]);
			if(buf>globalMax) globalMax=buf;
			if(buf<min) {
				min=buf;
				*(neighbor+order[i])=order[j];
			}
		}
		*(delta+order[i])=min;
	}
	*(delta+order[0])=globalMax;
}

