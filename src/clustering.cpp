#include "cluster.h"
#include <fstream>
void clustering(const vector<vector<double> > &vec,int nClus,int mode, int nn,double tau,int metric,const string &outputfile,int* clus) {
	int Num=vec.size();
	double** matrix=new double*[Num];
	for(int i=0; i<Num; ++i)
		*(matrix+i)=new double[Num-i]();
	double(*metricfun)(const vector<double> &,const vector<double> &);
	if(metric==0)
		metricfun=EuclideanDistance;
	else
		metricfun=cosineDistance;
	distanceMatrix(vec,matrix,metricfun);
	double* rho=new double[Num];
	double radius=searchRadius(matrix,Num,tau);
	density(matrix,Num,radius,mode,nn,rho);
	double* delta=new double[Num];
	int* neighbor=new int[Num];
	int* order=new int[Num];
	getDelta(matrix,Num,rho,delta,neighbor,order);
	string decisiongraph_file=outputfile+".decisiongraph";
	ofstream graph_out(decisiongraph_file.c_str());
	for(int t=0; t<Num; ++t)
		graph_out<<rho[t]<<' '<<delta[t]<<endl;
	graph_out.close();
	vector<int> clustersVec;
	findInitialCenters(rho,delta,Num,nClus,clustersVec);
	string centers_file=outputfile+".centers";
	ofstream centers_out(centers_file.c_str());
	for(size_t sz=0; sz<clustersVec.size(); ++sz)
		centers_out<<clustersVec[sz]<<' ';
	centers_out.close();
	assignClusters(order,neighbor,Num,clustersVec,clus);
	int* halo=new int[Num];
	filterHalos(matrix,Num,nClus,clus,rho,radius,halo);
	for(int ii=0; ii<Num; ++ii)
		delete[] *(matrix+ii);
	delete[] matrix;
	delete[] rho;
	delete[] delta;
	delete[] neighbor;
	delete[] order;
	string clust_file=outputfile+".result";
	ofstream clus_out(clust_file.c_str());
	for(int i=0; i<Num; ++i)
		clus_out<<i<<' '<<*(clus+i)<<' '<<*(halo+i)<<endl;
	clus_out.close();
	delete[] halo;
}
