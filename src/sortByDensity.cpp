#include "cluster.h"
void sortByDensity(const double* rho,int Num,int* order) {
	for(int t=0; t<Num; ++t)
		order[t]=t;
	for(int i=0; i<Num-1; ++i) {
		int max=i;
		for(int j=i+1; j<Num; ++j)
			if(*(rho+order[max])<*(rho+order[j]))
				max=j;
		std::swap(order[i],order[max]);
	}
}
