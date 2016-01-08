#include "cluster.h"
#include <cmath>
double EuclideanDistance(const vector<double> &vec1,const vector<double> &vec2) {
	double res=0.0;
	vector<double>::const_iterator iter1=vec1.begin();
	vector<double>::const_iterator iter2=vec2.begin();
	while(iter1!=vec1.end()&&iter2!=vec2.end()) {
		res+=(*iter1-*iter2)*(*iter1-*iter2);
		++iter1;
		++iter2;
	}
	return sqrt(res);
}
