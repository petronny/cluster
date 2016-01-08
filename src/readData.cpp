#include "cluster.h"
#include <sstream>
#include <fstream>
void readData(const char* filename,int withlabel,vector<vector<double> > &data_vec,vector<int> &label_vec) {
	stringstream ss;
	ifstream ifs(filename);
	double val;
	if(ifs) {
		data_vec.clear();
		string line;
		vector<double> subvec;
		while(getline(ifs,line)) {
			ss.clear();
			ss<<line;
			while(ss>>val) subvec.push_back(val);
			if(withlabel>0) {
				vector<double>::iterator last=subvec.end()-1;
				label_vec.push_back(*last);
				subvec.pop_back();
			}
			data_vec.push_back(subvec);
			subvec.clear();
		}
	} else
		cerr<<filename<<" doesn't exist!\n";
}

