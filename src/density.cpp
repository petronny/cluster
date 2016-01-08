#include "cluster.h"
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
void density(double** matrix,int Num,double radius,int mode,int nn,double* rho) {
	double dist,val;
	memset(rho,0,sizeof(double)*Num);
	vector<double> vec(Num,0);
	switch(mode) {
		case 0:
			for(int i=0; i<Num; ++i)
				for(int j=i+1; j<Num; ++j) {
					dist=getMatrixData(matrix,i,j);
					val=exp(-(dist/radius)*(dist/radius));
					*(rho+i)+=val;
					*(rho+j)+=val;
				}
			break;
		case 1:
			for(int i=0; i<Num; ++i)
				for(int j=i+1; j<Num; ++j) {
					dist=getMatrixData(matrix,i,j);
					if(dist<radius) {
						*(rho+i)+=1;
						*(rho+j)+=1;
					}
				}
			break;
		case 2:
			for(int i=0; i<Num; ++i) {
				for(int j=0; j<Num; ++j)
					vec[j]=-getMatrixData(matrix,i,j);
				make_heap(vec.begin(),vec.end());
				vector<double>::iterator first=vec.begin();
				vector<double>::iterator last=vec.end();
				for(int jj=0; jj<nn; ++jj)
					pop_heap(first,last--);
				last=vec.end();
				double sum=.0;
				for(int t=0; t<nn; ++t)
					sum+=*(--last);
				*(rho+i)=sum/nn;
			}
			break;
		default:
			cerr<<"Invalid option for computing density"<<endl;
			help();
			exit(0);
	}
}
