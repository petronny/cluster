#include "cluster.h"
#include <cstdlib>
#include <map>
#include <sstream>
void processParams(const string &line,string &inputfile,int &nClus,int &nn,\
                   int &mode,double &tau,int &metric,int &withlabel,string &outputfile) {
	if(!line.size()) {
		cerr<<"Options must be provied here."<<endl;
		help();
	}
	//set default values for parameters
	inputfile="";
	nClus=-1;
	nn=5;
	mode=0;//Gauss kernel.
	tau=0.05;//average percent for the number of neighbors of each point
	metric=0;//Euclidean
	outputfile="";//output
	withlabel=0;//without label in the input file
	map<string,int> cmd_map;
	cmd_map["--help"]=-1;
	cmd_map["--input"]=1;
	cmd_map["--clusters"]=2;
	cmd_map["--neighbors"]=3;
	cmd_map["--metric"]=4;
	cmd_map["--mode"]=5;
	cmd_map["--output"]=6;
	cmd_map["--withlabel"]=7;
	cmd_map["--tau"]=8;
	stringstream ss;
	ss<<line;
	string cmd,val;
	vector<string> cmd_vec;
	vector<string> val_vec;
	while(ss>>cmd) {
		if(!cmd_map[cmd]) { //invalid option
			cerr<<"Invalid option:"<<cmd<<endl;
			help();
			exit(0);
		}
		cmd_vec.push_back(cmd);
		if(cmd=="--help") {
			val_vec.push_back("help");//just to fill in the position here
			continue;
		}
		ss>>val;
		if(cmd_map[val]) { //value for last option is missing
			cerr<<"Value missing for option:"<<cmd<<endl;
			help();
			exit(0);
		}
		val_vec.push_back(val);
	}
	for(size_t sz=0; sz<cmd_vec.size(); ++sz) {
		cmd=cmd_vec[sz];
		cout<<"cmd:"<<cmd<<" val:"<<val_vec[sz]<<endl;
		switch(cmd_map[cmd]) {
			case -1://help
				help();
				break;
			case 1://input file
				inputfile=val_vec[sz];
				cout<<"input:"<<inputfile<<endl;
				if(outputfile=="") outputfile=inputfile;
				break;
			case 2://number of clusters
				nClus=atoi(val_vec[sz].c_str());
				cout<<"clusters:"<<nClus<<endl;
				break;
			case 3://number of nearest neighbors
				ss>>nn;
				cout<<"neighbors:"<<nn<<endl;
				break;
			case 4://metric for distance
				metric=atoi(val_vec[sz].c_str());
				cout<<"metric:"<<metric<<endl;
				break;
			case 5://mode of density computing
				mode=atoi(val_vec[sz].c_str());
				cout<<"mode:"<<mode<<endl;
				break;
			case 6://output of filename
				outputfile=val_vec[sz];
				cout<<"outputfile:"<<outputfile<<endl;
				break;
			case 7://indicates whether the last column are the labels
				withlabel=atoi(val_vec[sz].c_str());
				cout<<"withlabel:"<<withlabel<<endl;
				break;
			case 8://average percent for the number of neighbors of each point
				tau=atof(val_vec[sz].c_str());
				cout<<"tau:"<<tau<<endl;
				if(tau<0.0||tau>1) {
					cerr<<"Invalid tau(lies in (0,1)"<<endl;
					exit(0);
				}
				break;
			default:
				cerr<<"Invalid option:"<<cmd<<endl;
				help();
				exit(0);
		}
	}
}
