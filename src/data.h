/*
 * data.h
 *
 *  Created on: 2013-3-30
 *      Author: ryanhust
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

using namespace std;
struct FeatureTuple {
	int feature_index;
	double feature_value;
};

struct VectorSort {
	bool operator() (const FeatureTuple a, const FeatureTuple b) const{};
}
class SVMData {
public:
	SVMData(const char* file, int feature, int size, int _class, int myid, int procs);
	~SVMData();

protected:
	int N;
	int n;
	int K;
	int F;
    int minindex, maxindex;
    int* nodes;
    vector<FeatureTuple>* rawFeature;
	double** label;
	double** pred;
	double** score;
	bool processLine(int &linenum, ifstream &input, int i);
	bool parseFeatureTuple(string &cstring, string &cvalue);
	int binarySearch(int f, int i);
	void getSection();
	void resetNode();


}

class FeatureData: public SVMData {
public:
	FeatureData(const char* file, int feature, int size, int _class, int myid, int procs);
	~FeatureData();

private:
	int f;
	int minifeature, maxfeature;
	vector<FeatureTuple>* sortedFeature;
	int whoHasFeature(int gf);
	bool isLocalFeature(int gf);
	int localFeatureIndex(int gf);
	int globalFeatureIndex(int lf);
	void sort();

}




#endif /* DATA_H_ */
