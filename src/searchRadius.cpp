#include "cluster.h"
#include <cmath>
#include <algorithm>
double searchRadius(double** matrix,int Num,double tau) {
	int nElem=Num*(Num-1)/2;
	vector<double> dist;
	dist.reserve(nElem);
	int cnt=0;
	for(int i=0; i<Num-1; ++i)
		for(int j=i+1; j<Num; ++j)
			dist[cnt++]=getMatrixData(matrix,i,j);
	int pos=int(round(tau*Num));
	nth_element(dist.begin(),dist.begin()+pos-1,dist.end());
	return dist[pos-1];
}
