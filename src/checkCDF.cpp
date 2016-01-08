#include "cluster.h"
#include <fstream>
#include <sstream>
void checkCDF() {
	ifstream ifs("cdftable.txt");
	char ch;
	double x,res,pred;
	stringstream ss;
	string line;
	while(getline(ifs,line)) {
		ss.clear();
		ss<<line;
		ss>>ch>>ch>>x>>ch>>ch>>res;
		pred=CDFofNormalDistribution(x);
		cout<<'('<<pred<<','<<1-res<<')'<<endl;
	}
}

