#include <iostream>
#include <vector>
using namespace std;
double EuclideanDistance(const vector<double> &vec1,const vector<double> &vec2);
double cosineDistance(const vector<double> &vec1,const vector<double> &vec2);
double getMatrixData(double** matrix,int i,int j);
void setMatrixData(double** matrix,int i,int j,double val);
void distanceMatrix(const vector<vector<double> > &vec,double** matrix,double (*metricfun)(const vector<double> &,const vector<double> &));
double searchRadius(double** matrix,int Num,double tau=0.02);
void density(double** matrix,int Num,double threshold,int mode,int nn,double* res);
void getDelta(double** matrix,int Num,const double* rho,double* delta,int* neighbor,int* order);
void sortByDensity(const double* rho,int Num,int* index);
int numberOfClusters(const double* pgamma,int Num,double threshold);
double CDFofNormalDistribution(double x);
int findInitialCenters(const double* rho,const double* delta,int Num,int nClus,vector<int> &vec);
void assignClusters(const int* order,const int* neighbor,int Num,const vector<int> &vec,int* res);
void filterHalos(double** matrix,int Num,int nClus,const int* clus,const double* rho,double radius,int* halo);
void clustering(const vector<vector<double> > &vec,int nClus,int mode,int nn,double tau,int metric,const string &outputfile,int* clus);
void readData(const char* filename,int withlabel,vector<vector<double> > &data_vec,vector<int> &label_vec);
void checkCDF();
void processParams(const string &line,string &inputfile,int &nClus,int &nn,int &mode,double &tau,int &metric,int &withlabel,string &outputfile);
void help();
