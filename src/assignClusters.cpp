#include "cluster.h"
void assignClusters(const int* order,const int* neighbor,int Num,const vector<int> &vec,int* res) {
	for(int i=0; i<Num; ++i)
		*(res+i)=-1;
	for(size_t sz=0; sz<vec.size(); ++sz)
		*(res+vec[sz])=sz;
	for(int t=0; t<Num; ++t)
		if(*(res+*(order+t))==-1)
			*(res+*(order+t))=*(res+*(neighbor+*(order+t)));
}
