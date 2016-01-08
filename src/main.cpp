#include "cluster.h"
int main(int argc,char* argv[]) {
	string para_line;
	for(int i=1; i<argc; ++i)
		para_line+=string(argv[i])+' ';
	string inputfile;
	int nClus;
	int nn;
	double tau;
	int metric;
	int mode;
	int withlabel=0;
	string outputfile;
	processParams(para_line,inputfile,nClus,nn,mode,tau,metric,withlabel,outputfile);
	vector<vector<double> > data_vec;
	vector<int> label_vec;
	readData(inputfile.c_str(),withlabel,data_vec,label_vec);
	int Num=data_vec.size();
	int* res=new int[Num];
	clustering(data_vec,nClus,mode,nn,tau,metric,outputfile,res);
	delete[] res;
	return 0;
}

