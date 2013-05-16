/*
 * data.h
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <vector>

using namespace std;
struct FeatureTuple {
	int feature_index;
	double feature_value;
};

struct VectorSort {
	bool operator() (const FeatureTuple a, const FeatureTuple b) const{
        return (a.feature_value > b.feature_value);
    }
};
class SVMData {
public:
	SVMData(int feature, int size, int _class, int _myid, int _procs);
	~SVMData();
	void read(const char* file);


protected:
	int N, localN;
	int K;
	int F, localFeatures;
	int minindex, maxindex;
	int* nodes;
	vector<vector<FeatureTuple>> rawFeatures;
	double** label;
	double** pred;
	double** score;
	int myid, procs;
	int minifeature, maxfeature;
	int whoHasFeature(int gf);
	bool isLocalFeature(int gf);
	int localFeatureIndex(int gf);
	int globalFeatureIndex(int lf);
	bool processLine(int &linenum, ifstream &input, int i);
	bool processLabel(int &linenum, ifstream &input, )
	bool parseFeatureTuple(string &cstring, string &cvalue);
	int binarySearch(int f, int i);
	void getSection();
    void getFeatureSection();
	void resetNode();
}

class FeatureData: public SVMData {
public:
	FeatureData(int feature, int size, int _class, int myid, int procs):SVMData(feature, size, 
            _clss, myid, procs)
    {
        getFeatureSection();
        for(int j == 0; j <localFeatures; j++)
        {
            sortedFeatures.push_back(vector<FeatureTuple>());
        }

    }
	~FeatureData();

private:
	vector<vector<FeatureTuple>> sortedFeatures;
	void sort();
}




#endif /* DATA_H_ */
