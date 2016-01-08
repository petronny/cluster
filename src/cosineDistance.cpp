#include "cluster.h"
#include <cmath>
double cosineDistance(const vector<double> &vec1,const vector<double> &vec2) {
	vector<double>::const_iterator iter1=vec1.begin();
	vector<double>::const_iterator iter2=vec2.begin();
	double vec_product=0.0;
	double norm1=0.0,norm2=0.0;
	while(iter1!=vec1.end()&&iter2!=vec2.end()) {
		vec_product+=((*iter1)*(*iter2));
		norm1+=(*iter1)*(*iter1);
		norm2+=(*iter2)*(*iter2);
		++iter1;
		++iter2;
	}
	double eps=1e-6;
	double res;
	if(fabs(norm1)<=eps||fabs(norm2)<=eps)
		res=0.0;
	else
		res=vec_product/sqrt(norm1*norm2);
	return res;
}
