#include "cluster.h"
#include <cstring>
void filterHalos(double** matrix,int Num,int nClus,const int* clus, const double* rho,double radius,int* halo) {
	memset(halo,0,sizeof(int)*Num);
	if(nClus<=1)
		return;
	double* boundary_rho=new double[nClus]();
	double dist;
	double avg_rho;
	for(int i=0; i<Num-1; ++i)
		for(int j=i+1; j<Num; ++j) {
			dist=getMatrixData(matrix,i,j);
			if(dist<=radius&&*(clus+i)!=*(clus+j)) {
				avg_rho=(*(rho+i)+*(rho+j))/2.0;
				if(boundary_rho[*(clus+i)]<avg_rho)
					boundary_rho[*(clus+i)]=avg_rho;
				if(boundary_rho[*(clus+j)]<avg_rho)
					boundary_rho[*(clus+j)]=avg_rho;
			}
		}
	for(int i=0; i<Num; ++i) {
		if(*(rho+i)<boundary_rho[*(clus+i)])
			*(halo+i)=1;
	}
	delete[] boundary_rho;
}
