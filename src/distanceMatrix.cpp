#include "cluster.h"
void distanceMatrix(const vector<vector<double> > &vec,double** matrix,double (*metricfun)(const vector<double> &,const vector<double> &)) {
	size_t sz=vec.size();
	double dist=0.0;
	for(size_t i=0; i<sz; ++i) {
		setMatrixData(matrix,i,i,0);
		for(size_t j=i+1; j<sz; ++j) {
			dist=metricfun(vec[i],vec[j]);
			setMatrixData(matrix,i,j,dist);
		}
	}
}
